// Nesting

#include <iostream>
#include <stack>
using namespace std;

int solution(string &inputString){
    // Create a stack to keep track of open parentheses
    stack<char> parantheses;

    // Loop through each character
    for (int index = 0; index < inputString.length(); index++){
        // If opening parantheses, push it the stack
        if (inputString[index] == '('){
            parantheses.push(inputString[index]);
        }
        // If current character is closing parenthesis ')'
        else if (inputString[index] == ')'){
            // Check if there is a matching opening parenthesis
            if (parantheses.empty()){
                return 0;   // Return 0 indicating the string is not balanced
            }
            else{
                parantheses.pop(); // pop the matching opening parenthesis
            }
        }
    }
    if (parantheses.empty())
        return 1;
    else
        return 0;
}

int main(){
    string inputString = "(()(())())";
    cout << solution(inputString) << endl;
}