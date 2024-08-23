// StoneWall
// Correctness 100 Performance 100

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> &H){
    int n = H.size();
    stack<int> blocks;
    int numBlocks = 0;
    for (int i = 0; i < n; ++i) {

        if (blocks.empty() || H[i] > blocks.top()) {
            blocks.push(H[i]);
            ++numBlocks;
        } 
        else if (H[i] < blocks.top()) {
            while (!blocks.empty() && blocks.top() > H[i]) {
                blocks.pop();
            }

            if (blocks.empty() || blocks.top() < H[i]) {
                blocks.push(H[i]);
                ++numBlocks;
            }
        }
    }
    return numBlocks;
    // int n = H.size();
    // int numBlocks = 1;
    // int currHeight = H[0];
    // for(int i = 0; i < n - 1; i++){
    //     if(H[i] != H[i+1]){
    //         if(H[i] < H[i+1]){
    //             currHeight = H[i];
    //         }
    //     }
    //     cout << numBlocks << endl;
    // }
    // return numBlocks;
}

int main(){
    vector<int> H = {8,8,5,7,9,8,7,4,8};
    cout << solution(H) << endl;
}