// NumberOfDiscIntersections
// Correctness 100 Performance 100

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size(), discIntersect = 0;

    vector<long long> lower(n);  
    vector<long long> upper(n);  

    for (int i = 0; i < n; i++) {
        lower[i] = (long long)i - A[i];
        upper[i] = (long long)i + A[i];
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && upper[i] >= lower[j]) {
            cout << upper[i] << ".\n";
            discIntersect += j-i;
            j++;

            if (discIntersect > 10000000) {
                return -1;
            }
        }
        cout << discIntersect << endl;
    }
    return discIntersect;
    // for(int i = 0; i < n-1; i++){
    //     for(int j = i+1; j < n; j++){
    //         if(static_cast<long int>(A[i]) + static_cast<long int>(A[j]) >= abs(i - j)){
    //             discIntersect+=1;
    //         }
    //     }
    //     if(discIntersect > 10000000)
    //         return -1;
    // }
    // return discIntersect;
}

int main(){
    vector<int> A = {1, 5, 2, 1, 4, 0};
    cout << solution(A) << endl;
}