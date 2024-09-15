// GenomicRangeQuery
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;

    int n = S.size();
    vector<int> A(n, 5);
    vector<int> C(n, 5);
    vector<int> G(n, 5);
    vector<int> T(n, 5);
    
 
    const int p =P.size();

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


    vector<int> a = A, c = C, g = G, t = T; 

        sort(a.begin(), a.end());

        sort(c.begin(), c.end());

        sort(g.begin(), g.end());

        sort(t.begin(), t.end());
// for(bool x : c){
//     cout << x << " ";
// }
cout << endl;

    for(int i = 0; i < p; i++){
 

        if(a[n - 1 - P[i]]){
            result.push_back(1);
        }
        else if(c[n - 1 - P[i]]){
            result.push_back(2);
        }
        else if(g[n - 1 - P[i]]){
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
    string S = "AC";
    vector<int> P = {1};
    vector<int> Q = {1};
    vector<int> result = solution(S, P, Q);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}