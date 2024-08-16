// GenomicRangeQuery
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;
    map<char, int> dnaMap;
    dnaMap['A'] = 1;
    dnaMap['C'] = 1;
    dnaMap['G'] = 1;
    dnaMap['T'] = 1;

    for(int j = 0; j < P.size(); j++){
        int minImpact = 4;
       // int currImpact = 0;
       vector<int> sorted;
        for(int i = P[j]; i <= Q[j]; i++){
            
            if(S[i] == 'A'){    
                minImpact = 1;
            }
            else if(S[i] == 'C'){
                minImpact = 2;
            }
            else if(S[i] == 'G'){
                minImpact = 3;
            }
        }
        result.push_back(minImpact);
    }
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