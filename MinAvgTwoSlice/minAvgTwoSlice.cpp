// MinAvgTwoSlice

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &array){
    size_t arraySize = array.size();
    int minIndex = 0;

    if (arraySize < 2){ 
        return 0;
    }  

    // Initialize minimum average with avg of first two elements  
    double minAvg = (array[0] + array[1]) / 2.0;  
    // Iterate over array
    for (size_t index = 0; index < arraySize - 1; index++) {

        // Check slice of length 2
        double avg2 = (array[index] + array[index + 1]) / 2.0;
        if (avg2 < minAvg) {
            minAvg = avg2;
            minIndex = index;
        }
        // Check slice of length 3
        if (index < arraySize - 2) {
            double avg3 = (array[index] + array[index + 1] + array[index + 2]) / 3.0;
            if (avg3 < minAvg) {
                minAvg = avg3;
                minIndex = index;
            }
        }
    }

    return minIndex;
}


int main(){
    vector<int> array = {4, 2, 2, 5, 1, 5, 8};
    cout << solution(array) << endl;
}