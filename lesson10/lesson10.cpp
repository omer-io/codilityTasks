// Flags
// Correctness 100
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    vector<int> peaks;
    
    if(A.size() < 3)
        return 0;

    for(int i = 1; i < n-1; i++){
        if(A[i] > A[i-1] && A[i] > A[i+1]){
            peaks.push_back(i);
        }
    }

    int numPeaks = peaks.size();
    if (numPeaks == 0) 
        return 0;

    // int flags = 4;
    // for(int j = 0; j < numPeaks - 1; j++){
    //     for(int k = j + 1; k < numPeaks; k++){
    //         if(abs(peaks[j] - peaks[k] <= flags)){
    //             --flags;
    //             continue;
    //         }
    //         j = k;
    //     }
    // }
    // return flags;
    for (int flags = numPeaks; flags >= 1; --flags) {
        int usedFlags = 1;  // Place the first flag
        int lastFlagPosition = peaks[0];

        for (int i = 1; i < numPeaks; ++i) {
            if (peaks[i] - lastFlagPosition >= flags) {
                usedFlags++;
                lastFlagPosition = peaks[i];  // Place flag here
                if (usedFlags == flags) {  
                    return flags;
                }
            }
        }
    }
    return 1;
}

int main(){
    vector<int> A = {1,5,3,4,3,4,1,2,3,4,6,2};
    cout << solution(A) << endl;
}