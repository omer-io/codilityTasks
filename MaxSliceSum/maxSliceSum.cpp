// MaxSliceSum

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &array){
    // Initialize maxSliceSum and currentSliceSum to the first element
    int currentSliceSum = array[0];
    int maxSliceSum = array[0];

    // Iterate over array starting from second element
    for (int currentIndex = 1; currentIndex < array.size(); currentIndex++) {
        // Update currentSliceSum
        currentSliceSum = max(array[currentIndex], currentSliceSum + array[currentIndex]);
        // Update maxSum if currentSliceSum is larger
        maxSliceSum = max(maxSliceSum, currentSliceSum);
    }

    return maxSliceSum;
}


int main(){
    vector<int> array = {10};
    cout << solution(array) << endl;
}