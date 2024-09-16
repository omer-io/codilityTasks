// Peaks

#include <iostream>
#include <vector>
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

    int blockSize;
    int peakCount;
    int blockStart;
    int blockEnd;
    for(int numOfBlocks = numPeaks; numOfBlocks >=1; numOfBlocks--){
        if(n % numOfBlocks != 0){
            continue;
        }
            blockSize = n / numOfBlocks;
            peakCount = 0;
            for(int currentBlock = 0; currentBlock < numOfBlocks; currentBlock++){
                blockStart = blockSize * currentBlock;
                blockEnd = blockSize * (currentBlock + 1);
                for(int peak = currentBlock; peak < numPeaks; peak++){
                    if(peaks[peak] >= blockStart && peaks[peak] < blockEnd){
                        ++peakCount;
                        break;
                    }
                }

            }
            if(peakCount == numOfBlocks){
                return numOfBlocks;
            }
    }
    return 1;
    
    // for(int numOfBlocks = numPeaks; numOfBlocks >=1; numOfBlocks--){
    //     if(n % numOfBlocks == 0){
    //         blockSize = n / numOfBlocks;
    //         peakCount = 0;
    //         for(int currentBlock = 0; currentBlock < numOfBlocks; currentBlock++){
    //             for(int j = blockSize * currentBlock; j < blockSize * (currentBlock + 1); j++){
    //                 for(int k = 0; k < numPeaks; k++){
    //                     if(j == peaks[k]){
    //                         ++peakCount;
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //         if(peakCount == numOfBlocks){
    //             return numOfBlocks;
    //         }
    //     }
    // }


    // int maxBlocks = 1;
    // for(int i = 1; i < n; i++){
    //     if(n % i == 0){
    //         int numBlocks = n/i;
    //         for(int j = 0; j < numBlocks; j++){

    //         }
    //     }
    // }
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

}

int main(){
    vector<int> A = {0,2,1,3,1,0,1,2,3,1};
    cout << solution(A) << endl;
}