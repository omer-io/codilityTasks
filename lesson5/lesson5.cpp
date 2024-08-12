// GenomicRangeQuery
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;
    int minImpact = 4;

    for(int j = 0; j < P.size(); j++){
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
    string S = "AC";
    vector<int> P = {0,0,1};
    vector<int> Q = {0,1,1};
    vector<int> result = solution(S, P, Q);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}