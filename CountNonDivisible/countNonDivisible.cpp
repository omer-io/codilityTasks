// CountNonDivisible
// Correctness 100

#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> &A){
    int n = A.size();
    vector<int> result;

    vector<int> temp = A;
    sort(temp.begin(), temp.end());

    unordered_map<int, int> nonDivisors;

    int count;
    int elem;
    for(int i = 0; i < n; i++){
        count = n - i - 1;
        elem = temp[i];
        for(int j = i-1; j >= 0; j--){
            if(elem % temp[j] != 0){
                ++count;
            }
        }
        nonDivisors[elem] = count;
    }
    for(int i = 0; i < n; i++){
        result.push_back(nonDivisors[A[i]]);
    }

    // int count;
    // for(int i = 0; i < n; i++){
    //     count = 0;
    //     for(int j = 0; j < indextoVal[A[i]]; j++){
    //         if(A[i] % temp[j] != 0){
    //             ++count;
    //         }
    //     }
    //     count += (n -1 - indextoVal[A[i]]); 
    //     result.push_back(count);
    // }


    // int count;
    // for(int i = 0; i < n; i++){
    //     count = greaterElements[A[i]];
    //     for(int j = 0; j < indextoVal[A[i]]; j++){
    //         if(A[i] % temp[j] != 0){
    //             ++count;
    //         }
    //     }
    //     // count += (n -1 - indextoVal[A[i]]); 
    //     result.push_back(count);
    // }




    // int count;
    // for(int i = 0; i < n; i++){
    //     count = 0;
    //     for(int j = 0; j < indextoVal[A[i]]; j++){
    //         if(A[i] % temp[j] != 0){
    //             ++count;
    //         }
    //     }
    //     count += (n -1 - indextoVal[A[i]]); 
    //     result.push_back(count);
    // }


//    int count;
//     for(int i = 0; i < n; i++){
//         count = 0;
//         for(int j = 0; j < n; j++){
//             if(A[i] % temp[j] != 0){
//                 ++count;
//             }
//             else if(A[i] < temp[j]){
//                 count++;
//             }
//         }
//         //count += (n -1 - indextoVal[A[i]]); 
//         result.push_back(count);
    // }





    return result;
}

int main(){
    vector<int> A = {3,1,2,3,6};
    vector<int> result = solution(A);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}
