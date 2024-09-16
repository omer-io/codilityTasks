// Max Counters

#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int totalCounters, vector<int> &array){
    // initialize counters array with 0s
    vector<int> counters(totalCounters, 0);
    int max = 0, min = 0;

    int arraySize = array.size();
    for (int counterIndex = 0; counterIndex < arraySize; ++counterIndex)
    {
        if (array[counterIndex] <= totalCounters)
        {
            // if counter value is smaller than minimum, update min
            if (counters[array[counterIndex]-1] < min){
                counters[array[counterIndex]-1] = min;
            }
                
            // increment by 1
            counters[array[counterIndex]-1] += 1;

            // if counter value is > max, update max
            if (counters[array[counterIndex]-1] > max){
                max = counters[array[counterIndex]-1];
            }
        }
        // if array value is = totalCounters + 1
        else{
            min = max;       // assign the max value to minimum 
        }
    }
    
    // iterate over counters, if some counter is still < min, update it
    for (int counterIndex=0; counterIndex < totalCounters; ++counterIndex)
    {
        if (counters[counterIndex] < min)
            counters[counterIndex] = min;
    }

    return counters;
}

int main(){
    vector<int> arr = {3,4,4,6,1,4,4};
    vector<int> result = solution(5, arr);
    cout << "Values of counters: ";
    for (int counterIndex = 0; counterIndex < result.size(); counterIndex++) {
        cout << result[counterIndex] << " ";
    }
    cout << endl;
}