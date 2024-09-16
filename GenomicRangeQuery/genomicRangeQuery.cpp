// GenomicRangeQuery
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(string &DNAsequence, vector<int> &queryStart, vector<int> &queryEnd){
    vector<int> result; // iniitalze result vector

    int arraySize = DNAsequence.size();
    // intialize nucleotides A, C, G vectors with 0s
    vector<int> A(arraySize, 0);
    vector<int> C(arraySize, 0);
    vector<int> G(arraySize, 0);
    
    // Iterate over DNA string and put respective impact factor at that index
    for(int index = 0; index < arraySize; index++){
        if(DNAsequence[index] == 'A')
            A[index] = 1;
        else if(DNAsequence[index] == 'C')
            C[index] = 2;
        else if(DNAsequence[index] == 'G')
            G[index] = 3;
    }

    int totalQueries = queryStart.size();
    int impactFactor;

    // loop to iterate for total number of queries
    for(int index = 0; index < totalQueries; index++){
        impactFactor = 4;
        // loop over subarray defined by query
        for(int k = queryStart[index]; k <= queryEnd[index]; k++){
            if(A[k] == 1){
                if(impactFactor > 1){
                    impactFactor = 1;
                }
                break; // break if 1 found as its the lowest impact factor
            }
            else if(C[k] == 2){
                if(impactFactor > 2){
                    impactFactor = 2;
                }
            }
            else if(G[k] == 3){
                if(impactFactor > 3){
                    impactFactor = 3;
                }
            }
        }
        result.push_back(impactFactor);
    }    
    return result;
}

int main(){
    string DNAsequence = "CAGCCTA";
    vector<int> queryStart = {2,5,0};
    vector<int> queryEnd = {4,5,6};
    vector<int> result = solution(DNAsequence, queryStart, queryEnd);
    for (int index = 0; index < result.size(); index++)
        cout << result[index] << " ";
    cout << endl;
}