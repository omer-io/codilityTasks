// MinAvgTwoSlice

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    float minAvg = INT_MAX;
    int startPos;
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            float sum = 0;
            for(int k = i; k <= j; k++){
                sum += A[k];
            }
            sum =  sum / (j - i + 1);
            if(sum < minAvg){
                minAvg = sum;
                startPos = i;
            }
        }
    }
     return startPos;
}


int main(){
    vector<int> A = {4, 2, 2, 5, 1, 5, 8};
    cout << solution(A) << endl;
}