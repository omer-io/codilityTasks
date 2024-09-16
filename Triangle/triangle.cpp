// Triangle

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &array){
    int numOfElements = array.size();

    // Sort array in ascending order
    sort(array.begin(), array.end());

    // Iterate through array to check for any valid triangle
    for(int index = 0; index < numOfElements - 2; index++){
        // Check if the current triplet is triangular
        if(static_cast<long int>(array[index]) + static_cast<long int>(array[index+1]) > array[index+2]){
            return 1; // A valid triangular found
        }
    }
    return 0;
}

int main(){
    vector<int> array = {10,5,8};
    cout << solution(array) << endl;
}