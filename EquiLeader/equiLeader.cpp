// Equileader

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> &array){

    int arraySize = array.size();
    int equiLeaders = 0;
    map<int, int> countMap;

    // Count each element occurence
    for (int index = 0; index < arraySize; index++) {
        countMap[array[index]]++;
    }

    int leader, leaderCount = 0;

    map<int, int>::iterator it = countMap.begin();
    // find leader of complete vector
    while(it != countMap.end()){
        if (it->second > arraySize / 2) {
            leader = it->first;
            leaderCount = it->second;
            break;
        }
        it++;
    }

    int leftCount = 0;
    int rightCount = leaderCount; // initialze rightCount with total leader counts

    for (int index = 0; index < arraySize - 1; index++) {
        // at each index check if leader exists, then add one to left leader counts and reduce one from right counts
        if (array[index] == leader) {
            leftCount++;
            rightCount--;
        }
        // check if leader counts in boths sides left and right are greater than half of their side
        if (leftCount > (index + 1) / 2 && rightCount > (arraySize - index - 1) / 2) {
            equiLeaders++;
        }
    }

    return equiLeaders;

}

int main(){
    vector<int> array = {-1,-1,-1};
    cout << solution(array) << endl;
}