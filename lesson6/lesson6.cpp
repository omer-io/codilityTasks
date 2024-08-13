// Triangle
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    for(int P = 0; P < n-2; P++){
        for(int Q = P+1; Q < n-1; Q++){
            for(int R = Q+1; R < n; R++){
                if(static_cast<long int>(A[P]) + static_cast<long int>(A[Q]) > A[R] 
                && static_cast<long int>(A[Q]) + static_cast<long int>(A[R]) > A[P] 
                && static_cast<long int>(A[R]) + static_cast<long int>(A[P]) > A[Q]){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    vector<int> arr = {INT_MAX, INT_MAX, INT_MAX};
    cout << solution(arr) << endl;
}