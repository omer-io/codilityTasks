// Max Counters
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> &A){
    vector<int> counters(N, 0); 
    for(int i = 0; i < A.size(); i++){
        if(A[i] >= 1 && A[i] <= N)
            counters[A[i]-1] += 1;
        if(A[i] == (N+1)){
            int max = 0;
            for(int j = 0; j < N; j++){
                if(counters[j] > max)
                    max = counters[j];
            }
            for(int j = 0; j < N; j++)
                counters[j] = max;
        }
    }
    return counters;
}

int main(){
    vector<int> arr = {3,4,4,6,1,4,4};
    vector<int> result = solution(5, arr);
    cout << "Values of counters: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}