// Peaks
// 

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    if (n < 3) return 0;

    vector<int> peaks;
    for (int i = 1; i < n - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peaks.push_back(i);
        }
    }
    
    int numPeaks = peaks.size();
    if (numPeaks == 0) 
        return 0;

    int maxBlocks = 1;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            int numBlocks = n/i;
            for(int j = 0; j < numBlocks; j++){

            }
        }
    }
    // for (int K = numPeaks; K >= 1; K--) {
    //     if (n % K == 0) { 
    //         int blockSize = n / K;
    //         int peakCount = 0;
    //         int currentBlock = 0;

    //         for (int peak : peaks) {
    //             if (peak / blockSize > currentBlock) {
    //                 currentBlock++;
    //                 peakCount++;
    //             }
    //         }
            

    //         if (peakCount == K) {
    //             return K; 
    //         }
    //     }
    // }
    
    return 0; 
}

int main(){
    vector<int> A = {1,2,3,4,3,4,1,2,3,4,6,2};
    cout << solution(A) << endl;
}