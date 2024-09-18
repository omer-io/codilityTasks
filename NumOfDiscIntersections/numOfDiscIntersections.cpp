// NumberOfDiscIntersections

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &inputArray){
    size_t arraySize = inputArray.size();

    if(arraySize < 1){
        return 0;
    }
    int discIntersect = 0;

    // Outer loop to iterate over each disc
    for(size_t currentDisc = 0; currentDisc < arraySize-1; currentDisc++){
        // Inner loop to check intersections with next discs
        for(size_t nextDisc = currentDisc+1; nextDisc < arraySize; nextDisc++){
            // if sum of their radius is > distance between their centres
            if(static_cast<long int>(inputArray[currentDisc]) + static_cast<long int>(inputArray[nextDisc]) >= nextDisc - currentDisc){
                discIntersect += 1;
            }
        }
        if(discIntersect > 10000000)
            return -1;
    }
    return discIntersect;
}

int main(){
    vector<int> inputArray = {1, 5, 2, 1, 4, 0};
    cout << solution(inputArray) << endl;
}