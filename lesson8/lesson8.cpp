// Dominator
// Correctness 100 Performance 100

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> &A){
    if(A.empty())
        return -1;

    int n = A.size();
    map<int, int> indexToVal;
    // map values to respective index
    for(int a = 0; a < n; a++)
        indexToVal[A[a]] = a;

    sort(A.begin(), A.end());
    // if domniator exists, it must be in middle
    int dominator = A[n/2];

    int count = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == dominator)
            if(++count > n/2)
                return indexToVal[A[i]];
    }
    return -1;
}

int main(){
    vector<int> A = {2,1,1,1,3};
    cout << solution(A) << endl;
}