// Dominator
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    if(A.empty())
        return -1;
    int n = A.size();
    for(int i = 0; i < n/2 + 1; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(A[i] == A[j]){
                if(++count > n/2)
                    return i;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> A = {1,2,1};
    cout << solution(A) << endl;
}