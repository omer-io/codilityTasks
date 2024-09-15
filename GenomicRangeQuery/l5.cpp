// GenomicRangeQuery
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;

    int n = S.size();
    vector<bool> A(n, false);
    vector<bool> C(n, false);
    vector<bool> G(n, false);
    vector<bool> T(n, false);
    
 
    const int p =P.size();

    for(int j = 0; j < n; j++){
        if(S[j] == 'A')
            A[j] = true;
        else if(S[j] == 'C')
            C[j] = true;
        else if(S[j] == 'G')
            G[j] = true;
        else if(S[j] == 'T')
            T[j] = true;
    }

    int factor;
    for(int i = 0; i < p; i++){
        factor = 4;
        for(int k = P[i]; k <= Q[i]; k++){
            if(A[k]){
                if(factor > 1){
                    factor = 1;
                }
                // factor = min(factor, 1);
                break;
            }
            else if(C[k]){
                if(factor > 2){
                    factor = 2;
                }
                // factor = min(factor, 2);
            }
            else if(G[k]){
                if(factor > 3){
                    factor = 3;
                }
                // factor = min(factor, 3);
            }
        }
        result.push_back(factor);
    }
    
    // dnaMap['A'] = 1;
    // dnaMap['C'] = 2;
    // dnaMap['G'] = 3;
    // dnaMap['T'] = 4;
    // const int n =P.size();
    // result.reserve(n);
    // for(int j = 0; j < n; j++){
    //     result.push_back(dnaMap[*min_element(S.begin() + P[j],S.begin() + Q[j]+1)]);
    // }
    return result;
}

int main(){
    string S = "CAGCCTA";
    vector<int> P = {2,5,0};
    vector<int> Q = {4,5,6};
    vector<int> result = solution(S, P, Q);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}