// GenomicRangeQuery
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;
    map<char, int> dnaMap;
    vector<int> A(S.size(), 0), C(S.size(), 0), G(S.size(), 0), T(S.size(), 0);
    
    const int n =P.size();

    for(int j = 0; j < S.size(); j++){
        if(S[j] == 'A')
            A[j] == 1;
        if(S[j] == 'C')
            C[j] = 1;
        if(S[j] == 'G')
            G[j] = 1;
        if(S[j] == 'T')
            T[j] = 1;
    }
    for(int i = 0; i < S.size(); i++)
    
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