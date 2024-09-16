// NumberOfDiscIntersections

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &inputArray){
    int n = inputArray.size();
    int discIntersect = 0;

    // Outer loop to iterate over each disc
    for(int currentDisc = 0; currentDisc < n-1; currentDisc++){
        // Inner loop to check intersections with next discs
        for(int nextDisc = currentDisc+1; nextDisc < n; nextDisc++){
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