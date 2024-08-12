// Tape Equilibrium
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int solution(vector<int> &A){
            int P, minDiff = 0, diff = 0;
            int n = A.size();
            for(P = 1; P < n; P++){
                int lCount = P, rCount = P, leftSum = 0, rightSum = 0;
                while(lCount != 0)
                    leftSum += A[--lCount];
                
                while(rCount != n)
                    rightSum += A[rCount++];
                
                if(P == 1)
                    minDiff = abs(leftSum - rightSum);
                
                diff = abs(leftSum - rightSum);
                if(diff < minDiff)
                    minDiff = diff;
            }
            return minDiff;
        }
};

int main(){
    vector<int> arr = {3,1,2,4,3};
    Solution tapeEq;
    cout << "Minimum difference is " << tapeEq.solution(arr) << endl;
    return 0;
}