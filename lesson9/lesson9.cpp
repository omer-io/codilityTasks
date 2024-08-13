// MaxSliceSum

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    int maxSum=0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            float sum = 0;
            for(int k = i; k <= j; k++){
                sum += A[k];
            }
            if(i == 0 && j == 0)
                maxSum = sum;
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}


int main(){
    vector<int> A = {10};
    cout << solution(A) << endl;
}