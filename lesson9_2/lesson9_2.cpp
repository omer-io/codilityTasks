// MaxDoubleSliceSum
// wip
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    int currMax = A[0];
    int maxSum = A[0];

    for (int i = 1; i < A.size()-2; i++) {
   
        currMax = max(A[i], currMax + A[i]);
        currMax -= A[i];
        currMax = max(A[i], currMax + A[i+1]);
        currMax -= A[i+1];
        maxSum = max(maxSum, currMax);
    }

    return maxSum;

    // int n = A.size();
    // int maxSum=0;
    // for(int i = 0; i < n-2; i++){
    //     for(int j = i + 1; j < n-1; j++){
    //         for(int k = j + 1; k < n; k++){
    //             float sum = 0;
    //             for(int s = i+1; s < k; s++){
    //                 sum += A[s];
    //             }
    //             sum -= A[j];
    //             if(i == 0 && j == 1 && k == 2)
    //                 maxSum = sum;
    //             if(sum > maxSum){
    //                 maxSum = sum;
    //             }
    //         }
    //     }
    // }
    // return maxSum;
}

int main(){
    //vector<int> A = {5,5,5};
    vector<int> A = {3,2,6,-1,4,5,-1,2};
    cout << solution(A) << endl;
}