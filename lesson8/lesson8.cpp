// Dominator
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    int maxCount = 0, index;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(A[i] == A[j]){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            index = i;
        }
    }
    if(maxCount > n/2)
    return index;
    else
    return -1;

}

int main(){
    vector<int> A = {1,3,3, 4, 3, 2, 3, -1, 3, 3};
    cout << solution(A) << endl;
}