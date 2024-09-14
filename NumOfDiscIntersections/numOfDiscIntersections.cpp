// NumberOfDiscIntersections
// Correctness 100 Performance 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size(), discIntersect = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(static_cast<long int>(A[i]) + static_cast<long int>(A[j]) >= abs(i - j)){
                discIntersect+=1;
            }
        }
        if(discIntersect > 10000000)
            return -1;
    }
    return discIntersect;
}

int main(){
    vector<int> A = {1, 5, 2, 1, 4, 0};
    cout << solution(A) << endl;
}