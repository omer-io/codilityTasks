// GenomicRangeQuery
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;
    for(int j = 0; j < P.size(); j++){
        int minImpact = 4;
        int currImpact = 0;
        for(int i = P[j]; i <= Q[j]; i++){
            if(S[i] == 'A'){    
                currImpact = 1;
                if(currImpact < minImpact)
                    minImpact = currImpact;
            }
            else if(S[i] == 'C'){
                currImpact = 2;
                if(currImpact < minImpact)
                    minImpact = currImpact;
            }
            else if(S[i] == 'G'){
                currImpact = 3;
                if(currImpact < minImpact)
                    minImpact = currImpact;
            }
            else if(S[i] == 'T'){
                currImpact = 4;
                if(currImpact < minImpact)
                    minImpact = currImpact;
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