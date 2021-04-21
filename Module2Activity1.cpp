#include <iostream>
#include <stack>

using namespace std;
int main(){
    stack<int> binary;
    int x;
    bool isNegative = false;
    cout << "Please input proper decimal number: ";
    cin >> x;
    if(x<0){
        isNegative = true;
        x=x*-1;
    }
    while(x > 0){
        if(x % 2 == 0){
            x = x/2;
            binary.push(0);
        }else{
            x--;
            x = x/2;
            binary.push(1);
        }
    }
    cout << "In Binary: ";
    if(isNegative == true){
        cout << "-";
    }
    while(!binary.empty()){
        cout << binary.top();
        binary.pop();
    }
}
