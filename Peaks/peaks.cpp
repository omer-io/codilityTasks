// Peaks

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &inputArray){
    size_t arraySize = inputArray.size();
    
    // if no peak exists
    if (arraySize < 3){ 
        return 0;
    }

    vector<int> peaks;
    // find and store indices peaks
    for (size_t index = 1; index < arraySize - 1; index++) {
        if (inputArray[index] > inputArray[index - 1] && inputArray[index] > inputArray[index + 1]) {
            peaks.push_back(index);
        }
    }
    
    int numPeaks = peaks.size();
    // if no peak exists
    if (numPeaks == 0) 
        return 0;

    int blockSize;
    int peakCount;
    int blockStart;
    int blockEnd;

    // start outer loop with max number of blocks possible that is number of peaks
    for(int numOfBlocks = numPeaks; numOfBlocks >=1; numOfBlocks--){
        // if array cannot be divided evenly into number of blocks, continue
        if(arraySize % numOfBlocks != 0){
            continue;
        }
            blockSize = arraySize / numOfBlocks;
            peakCount = 0;

            for(int currentBlock = 0; currentBlock < numOfBlocks; currentBlock++){
                // Calculate start and end indices of current block
                blockStart = blockSize * currentBlock;
                blockEnd = blockSize * (currentBlock + 1);

                // Check if there is a peak in current block
                for(int peak = currentBlock; peak < numPeaks; peak++){
                    // if there is a peak in current block, increment peakCount, break and check next block
                    if(peaks[peak] >= blockStart && peaks[peak] < blockEnd){
                        ++peakCount;
                        break;
                    }
                }

            }
            // If all blocks contain at least one peak return number of blocks
            if(peakCount == numOfBlocks){
                return numOfBlocks;
            }
    }
    return 1;
}

int main(){
    vector<int> inputArray = {0,2,1,3,1,0,1,2,3,1};
    cout << solution(inputArray) << endl;
}