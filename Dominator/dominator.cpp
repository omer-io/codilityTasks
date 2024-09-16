// Dominator

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> &array){
    if(array.empty())
        return -1;

    int arraySize = array.size();
    map<int, int> indexToVal;
    // map values to respective index
    for(int a = 0; a < arraySize; a++)
        indexToVal[array[a]] = a;

    sort(array.begin(), array.end());
    // if domniator exists, it must be in middle
    int dominator = array[arraySize/2];

    int count = 0;
    for(int index = 0; index < arraySize; index++){
        if(array[index] == dominator)
            if(++count > arraySize/2)
                return indexToVal[array[index]];
    }
    return -1;
}

int main(){
    vector<int> array = {2,1,1,1,3};
    cout << solution(array) << endl;
}