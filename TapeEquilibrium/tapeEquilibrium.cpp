// Tape Equilibrium
// Correctness 100 Performance 100

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A){
    int leftSum = A[0], rightSum = 0, n = A.size();

    for (int i = 1; i < n; i++) {
        rightSum += A[i];
    }
    int minDiff = abs(rightSum - leftSum);
    int currDiff = 0;
    for (int i = 1; i < A.size() - 1; i++) {
        leftSum += A[i];
        rightSum -= A[i];
        currDiff = abs(rightSum - leftSum);
        if (currDiff < minDiff) {
            minDiff = currDiff;
        }
    }
    return minDiff;
    // int P, minDiff = 0, diff = 0;
    // int n = A.size();
    // for(P = 1; P < n; P++){
    //     int lCount = P, rCount = P, leftSum = 0, rightSum = 0;
    //     while(lCount != 0)
    //         leftSum += A[--lCount];
        
    //     while(rCount != n)
    //         rightSum += A[rCount++];
        
    //     if(P == 1)
    //         minDiff = abs(leftSum - rightSum);
        
    //     diff = abs(leftSum - rightSum);
    //     if(diff < minDiff)
    //         minDiff = diff;
    // }
    // return minDiff;
}

int main(){
    vector<int> arr = {3,1,2,4,3};
    cout << "Minimum difference is " << solution(arr) << endl;
    return 0;
}