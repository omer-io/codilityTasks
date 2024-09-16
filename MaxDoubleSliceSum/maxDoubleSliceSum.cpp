// MaxDoubleSliceSum

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &array){

    int arraySize = array.size();
    int maxSum = 0;
    int sum;

    // outer loop for starting index of slice
    for(int startIndex = 0; startIndex < arraySize - 2; startIndex++){
        // middle loop for middle index of slice
        for(int midIndex = startIndex + 1; midIndex < arraySize - 1; midIndex++){
            // loop for ending index of slice
            for(int endIndex = midIndex + 1; endIndex < arraySize; endIndex++){
                sum = 0;
                // loop to calculate sum of slice
                for(int sliceIndex = startIndex + 1; sliceIndex < endIndex; sliceIndex++){
                    sum += array[sliceIndex];
                }
                // subtract value at mid index
                sum -= array[midIndex];
                // assign sum to maxSum if its greater
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
    }
    return maxSum;
}

int main(){
    vector<int> array = {3,2,6,-1,4,5,-1,2};
    cout << solution(array) << endl;
}