// CountNonDivisible
// Correctness 100

#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<int> &A){
    int n = A.size();
    vector<int> result;

    vector<int> temp = A;
    sort(temp.begin(), temp.end());

    map<int, int> indextoVal;
    for(int i = 0; i < n; i++) {
        indextoVal[temp[i]] = i;
    }

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < indextoVal[A[i]]; j++){
            if(A[i] % temp[j] != 0){
                ++count;
            }
        }
        count += (temp.size() -1 - indextoVal[A[i]]); 
        result.push_back(count);
    }

    return result;
}

int main(){
    vector<int> A = {3,1,2,3,6};
    vector<int> result = solution(A);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}
