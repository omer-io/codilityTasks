// GenomicRangeQuery
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;

    int n = S.size();
    vector<int> A(n, 0);
    vector<int> C(n, 0);
    vector<int> G(n, 0);
    vector<int> T(n, 0);
    
 
    int p =P.size();

    for(int j = 0; j < n; j++){
        if(S[j] == 'A')
            A[j] = 1;
        else if(S[j] == 'C')
            C[j] = 2;
        else if(S[j] == 'G')
            G[j] = 3;
        else if(S[j] == 'T')
            T[j] = 4;
    }

    int factor;
    vector<bool> a, c, g, t; 
    for(int i = 0; i < p; i++){
        factor = 4;
        // a = vector<bool>(A.begin() + P[i], A.begin() + Q[i] + 1);
        // sort(a.begin(), a.end());

        // c = vector<bool>(C.begin() + P[i], C.begin() + Q[i] + 1);
        // sort(c.begin(), c.end());

        // g = vector<bool>(G.begin() + P[i], G.begin() + Q[i] + 1);
        // sort(g.begin(), g.end());

        // t = vector<bool>(T.begin() + P[i], T.begin() + Q[i] + 1);
        // sort(t.begin(), t.end());
        string subString = S.substr(P[i], Q[i] - P[i] + 1);
        sort(subString.begin(), subString.end());

        if(subString[0] == 'A'){
            result.push_back(1);
        }
        else if(subString[0] == 'C'){
            result.push_back(2);
        }
        else if(subString[0] == 'G'){
            result.push_back(3);
        }
        else{
            result.push_back(4);
        }
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