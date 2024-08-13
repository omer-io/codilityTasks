// Nesting
#include <iostream>
#include <stack>
using namespace std;

int solution(string &S){
    stack<char> a;
    for (int i = 0; i < S.length(); i++){
        if (S[i] == '('){
            a.push(S[i]);
        }
        else if (S[i] == ')'){
            if (a.empty()){
                return 0;
            }
            else{
                a.pop();
            }
        }
    }
    if (a.empty())
        return 1;
    else
        return 0;
}

int main(){
    string S = "(()(())())";
    cout << solution(S) << endl;
}