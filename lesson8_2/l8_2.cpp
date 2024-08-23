// Equileader
// Correctness 100 Performance 100

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> &A){

    int n = A.size();
    int equiLeaders = 0;
    map<int, int> countMap;

    // Count each element occurence
    for (int i = 0; i < n; i++) {
        countMap[A[i]]++;
    }

    int leader, leaderCount = 0;

    map<int, int>::iterator it = countMap.begin();
    // find leader of complete vector
    while(it != countMap.end()){
        if (it->second > n / 2) {
            leader = it->first;
            leaderCount = it->second;
            break;
        }
        it++;
    }

    int leftCount = 0;
    int rightCount = leaderCount;

    for (int S = 0; S < n - 1; S++) {
        if (A[S] == leader) {
            leftCount++;
            rightCount--;
        }

        if (leftCount > (S + 1) / 2 && rightCount > (n - S - 1) / 2) {
            equiLeaders++;
        }
    }

    return equiLeaders;

    // int n = A.size();
    // int equiLeaders = 0;

    // for (int S = 0; S < n - 1; S++) {

    //     vector<int> leftVector(A.begin(), A.begin() + S + 1);
    //     sort(leftVector.begin(), leftVector.end());

    //     int leftLeader = leftVector[leftVector.size() / 2];

    //     int leftCount = 0;
    //     for (int i = 0; i <= S; i++) {
    //         if (A[i] == leftLeader) {
    //             leftCount++;
    //         }
    //     }

    //     vector<int> rightVector(A.begin() + S + 1, A.end());
    //     sort(rightVector.begin(), rightVector.end());

    //     int rightLeader = rightVector[rightVector.size() / 2];

    //     int rightCount = 0;
    //     for (int i = S + 1; i < n; i++) {
    //         if (A[i] == rightLeader) {
    //             rightCount++;
    //         }
    //     }

    //     if (leftCount > (S + 1) / 2 && rightCount > (n - S - 1) / 2 && leftLeader == rightLeader) {
    //         ++equiLeaders;
    //     }
    // }

    // return equiLeaders;
}

int main(){
    vector<int> A = {-1,-1,-1};
    cout << solution(A) << endl;
}