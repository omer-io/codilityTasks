// Tape Equilibrium
#include <iostream>
using namespace std;

class Solution{
    public:
        int solution(int A[]){
            int P, minDiff = 0, diff = 0;
            for(P = 1; P < 5; P++){
                int lCount = P, rCount = P, leftSum = 0, rightSum = 0;
                while(lCount != 0)
                    leftSum += A[--lCount];
                
                while(rCount != 5)
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
    int arr[5] = {3,1,2,4,3};
    Solution tapeEq;
    cout << tapeEq.solution(arr) << endl;
    return 0;
}