// CountNonDivisible

#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> &array){
    int arraySize = array.size();
    vector<int> result;

    // Create a sorted copy of array
    vector<int> sortedArray = array;
    sort(sortedArray.begin(), sortedArray.end());

    // map to store number of non-divisors of each element
    unordered_map<int, int> nonDivisors;

    int count;
    int elem;
    for(int index = 0; index < arraySize; index++){
        count = arraySize - index - 1; // values greater than element are non divisors, add them first
        elem = sortedArray[index];
        for(int divisorIndex = index-1; divisorIndex >= 0; divisorIndex--){ // loop to iterate through values smaller than element
            if(elem % sortedArray[divisorIndex] != 0){
                ++count;
            }
        }
        nonDivisors[elem] = count;
    }
    for(int index = 0; index < arraySize; index++){
        result.push_back(nonDivisors[array[index]]);
    }

    return result;
}

int main(){
    vector<int> array = {3,1,2,3,6};
    vector<int> result = solution(array);
    for(int index = 0; index < result.size(); index++){
        cout << result[index] << " ";
    }
    cout << endl;
}
