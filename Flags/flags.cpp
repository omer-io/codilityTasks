// Flags

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &array){
    size_t arraySize = array.size();
    
    // if array size < 3, no peak exists
    if(arraySize < 3)
        return 0;

    vector<int> peaks;
    // find and store peaks
    for(size_t currentPeak = 1; currentPeak < arraySize-1; currentPeak++){
        if(array[currentPeak] > array[currentPeak-1] && array[currentPeak] > array[currentPeak+1]){
            peaks.push_back(currentPeak);
        }
    }

    int numPeaks = peaks.size();
    // return 0 if no peak exists
    if (numPeaks == 0) 
        return 0;

    int usedFlags;  
    int lastFlagPosition;

    // start with max number of flags, reduce by one if all flags can't be placed
    for (int flags = numPeaks; flags >= 1; --flags) {
        usedFlags = 1;  // Place the first flag
        lastFlagPosition = peaks[0];

        for (int currentPeak = 1; currentPeak < numPeaks; ++currentPeak) {
            if (peaks[currentPeak] - lastFlagPosition >= flags) {
                usedFlags++;
                lastFlagPosition = peaks[currentPeak];  // Place flag here
                if (usedFlags == flags) {  
                    return flags;       // if all flags placed return number of flags
                }

            }
            // check if remaining flags > remaining peaks
            if(flags - usedFlags > numPeaks - currentPeak - 1){
                break;
            }
        }
    }
    return 1;
}

int main(){
    vector<int> array = {1,5,3,4,3,4,1,2,3,4,6,2};
    cout << solution(array) << endl;
}