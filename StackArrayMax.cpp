#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

 


int main() {    
    int query, element, N, top = 0, max = INT_MIN , max_index = -1; 
    cin >> N;
    int stack[N+1];
    
    for(int i = 0; i < N; i++){
        cin >> query;
        if (query == 1){
            cin >> element;
            stack[top] = element;
            if (element > max){
                max = element;
                max_index = top;
            }
            top++;
       } else if (query == 2){
            top--;
            if (top == 0){ // reset
                max = INT_MIN;
                max_index = 0;
                continue;
            }
            if (max_index == top){
               max = stack[0];
               max_index = 0;
               for (int i = 1; i < top; i++){
                     if (stack[i] > max){
                              max = stack[i];
                              max_index = i;
               } 
              }     
        } }else if (query == 3){
            if (max_index != -1)
                cout << stack[max_index] << endl;         
        }
    }
    return 0;
}
