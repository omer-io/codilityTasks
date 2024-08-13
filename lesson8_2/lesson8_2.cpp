#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    int maxCount = 0, index;
    int equiLeader = 0;

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(A[i] == A[j]){
                count++;
            }
        }
        if(count > n/2){
            maxCount = count;
            index = i;
        }
    }

    for(int S = 0; S < n; S++){
        int leftCount = 0, rightCount = 0;

        for(int left = 0; left <= S; left++){
            if(A[left] == A[index]){
                leftCount++;
            }
        }

        for(int right = S+1; right < n; right++){
            if(A[right] == A[index]){
                rightCount++;
            }
        }

        if(leftCount > (S+1)/2 && rightCount > (n-S-1)/2){
            equiLeader++;
        }
    }
    return equiLeader;
}

int main(){
    vector<int> A = {4, 4, 2, 5, 3, 4, 4, 4};
    cout << solution(A) << endl;
}