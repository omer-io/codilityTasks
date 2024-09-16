// StoneWall

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> &heights){
    int arraySize = heights.size();
    stack<int> blocks;
    int numBlocks = 0;

    // Iterate through each height in the input vector
    for (int currentIndex = 0; currentIndex < arraySize; ++currentIndex) {

        // If stack is empty or current height is greater than the top of the stack
        if (blocks.empty() || heights[currentIndex] > blocks.top()) {
            blocks.push(heights[currentIndex]);    // push current height
            ++numBlocks;
        } 
        // If current height is less than top of the stack
        else if (heights[currentIndex] < blocks.top()) {
            // pop blocks from stack until the top of stack is less than or equal to current height
            while (!blocks.empty() && blocks.top() > heights[currentIndex]) {
                blocks.pop();
            }
            // If stack is empty or new top is less than current height
            if (blocks.empty() || blocks.top() < heights[currentIndex]) {
                blocks.push(heights[currentIndex]);    // add current height as new block
                ++numBlocks;
            }
        }
    }
    return numBlocks;
}

int main(){
    vector<int> heights = {8,8,5,7,9,8,7,4,8};
    cout << solution(heights) << endl;
}