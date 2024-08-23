// GenomicRangeQuery
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q){
    vector<int> result;
    map<char, int> dnaMap;
    const int n =P.size();

    dnaMap['A'] = 1;
    dnaMap['C'] = 2;
    dnaMap['G'] = 3;
    dnaMap['T'] = 4;

    for(int j = 0; j < n; j++)
        result.push_back(dnaMap[*min_element(S.begin() + P[j],S.begin() + Q[j]+1)]);

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