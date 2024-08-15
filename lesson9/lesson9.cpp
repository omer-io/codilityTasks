// MaxSliceSum

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int currMax = A[0];
    int maxSum = A[0];

    for (int i = 1; i < A.size(); i++) {
   
        currMax = max(A[i], currMax + A[i]);

        maxSum = max(maxSum, currMax);
    }

    return maxSum;
    // int n = A.size();
    // int maxSum=0;
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         float sum = 0;
    //         for(int k = i; k <= j; k++){
    //             sum += A[k];
    //         }
    //         if(i == 0 && j == 0)
    //             maxSum = sum;
    //         if(sum > maxSum){
    //             maxSum = sum;
    //         }
    //     }
    // }
    // return maxSum;
}


int main(){
    vector<int> A = {10};
    cout << solution(A) << endl;
}