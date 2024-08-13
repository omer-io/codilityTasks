// StoneWall
// wip
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> &H){
    int n = H.size();
    int numBlocks = 1;
    int currHeight = H[0];
    for(int i = 0; i < n - 1; i++){
        if(H[i] != H[i+1]){
            if(H[i] < H[i+1]){
                currHeight = H[i];
            }
        }
        cout << numBlocks << endl;
    }
    return numBlocks;
}

int main(){
    vector<int> H = {8,8,5,7,9,8,7,4,8};
    cout << solution(H) << endl;
}