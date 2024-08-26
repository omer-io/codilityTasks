// NumberOfDiscIntersections
// Correctness 100 Performance 

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int n = A.size(), discIntersect = 0;

    vector<long int> lower(n);  
    vector<long int> upper(n);  

    for (int i = 0; i < n; i++) {
        // lower array stores left endpoints of discs
        lower[i] = static_cast<long int>(i) - static_cast<long int>(A[i]);
                // lower array stores left endpoints of discs
        upper[i] = static_cast<long int>(i) + static_cast<long int>(A[i]);
    }

    // sort lower and upper arrays
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && upper[i] >= lower[j]) {
            // subtract previously counted intersections
            discIntersect += j-i;
            j++;

            if (discIntersect > 10000000) {
                return -1;
            }
        }
    }
    return discIntersect;
}

int main(){
    vector<int> A = {1, 5, 2, 1, 4, 0};
    cout << solution(A) << endl;
}