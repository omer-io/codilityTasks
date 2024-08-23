// MaxDoubleSliceSum
// Correctness 100

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){

    int n = A.size();
    int maxSum=0;
    for(int i = 0; i < n-2; i++){
        for(int j = i + 1; j < n-1; j++){
            for(int k = j + 1; k < n; k++){
                float sum = 0;
                for(int s = i+1; s < k; s++){
                    sum += A[s];
                }
                sum -= A[j];
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
    }
    return maxSum;
}

int main(){
    //vector<int> A = {5,5,5};
    vector<int> A = {3,2,6,-1,4,5,-1,2};
    cout << solution(A) << endl;
}