// Flags
// wip
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    vector<int> peaks;
    for(int i = 1; i < n-1; i++){
        if(A[i] > A[i-1] && A[i] > A[i+1]){
            peaks.push_back(i);
        }
    }
    int flags = 0;
    for(int j = 0; j < peaks.size(); j++){
    for(int k = 0; k < peaks.size(); k++){
        if(abs(peaks[k] - peaks[k+1]) > flags){
            continue;
        }
        break;
    }
    flags++;
    }
    return flags;
}

int main(){
    vector<int> A = {1,5,3,4,3,4,1,2,3,4,6,2};
    cout << solution(A) << endl;
}