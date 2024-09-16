// Tape Equilibrium

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &array){
    int leftSum = array[0]; // initialize sum of elements to the left with first element
    int rightSum = 0;
    int arraySize = array.size();

    // calculate initial sum of all elements to the right of the first element
    for (int index = 1; index < arraySize; index++) {
        rightSum += array[index];
    }

    // initialize the minimum difference with the difference at first possible split point
    int minDiff = abs(rightSum - leftSum);
    int currDiff = 0;

    // iterate through split points
    for (int index = 1; index < array.size() - 1; index++) {
        // update left sum to include current element
        leftSum += array[index];
        // update right sum to exclude current element
        rightSum -= array[index];
        // calculate difference 
        currDiff = abs(rightSum - leftSum);
        if (currDiff < minDiff) {
            minDiff = currDiff;
        }
    }
    return minDiff;
}

int main(){
    vector<int> arr = {3,1,2,4,3};
    cout << "Minimum difference is " << solution(arr) << endl;
    return 0;
}