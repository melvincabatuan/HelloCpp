#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
// ((A+(B*(C/A)))-(B/C))
// ((T+O)*(N+I)/(A-B))+C
int main ()
{
    // Stacks for holding input.
    stack<char> stack1;
    stack<char> op1;
    stack<char> input;

    // Input of the user.
    char x[30];
    char z;

    // Tracks size of stack.
    int vol;
    // Take input of user.
    cout<<"Enter string of your statement: ";
    scanf("%s", &x);
    for(int i = 0; x[i]!=0 ;i++){
        z = x[i];
        if(z == '+' || z == '-' || z == '*' || z == '('){
            op1.push(z);
        }else if(z == ')' || z == '/'){
            while (op1.top()!='('){
                stack1.push(op1.top());
                op1.pop();
            }
            if(z == '/'){
                op1.push(z);
            }else{
                op1.pop();
            }
        }else{
            stack1.push(z);
        }
        vol++;
    }
    while (!op1.empty()){
        stack1.push(op1.top());
        op1.pop();
    }
    while (!stack1.empty()){
        input.push(stack1.top());
        stack1.pop();
    }
    // Display stack to user.
    cout << "\nInto Postfix: ";
    while (!input.empty()){
        cout << input.top();
        input.pop();
    }
    for(int i = vol; i>=0 ;i--){
        z = x[i];
        if(z == '+' || z == '-' || z == '/' || z == '*' || z == ')'){
            op1.push(z);
        }else if(z == '('){
            while (op1.top()!=')'){
                stack1.push(op1.top());
                op1.pop();
            }
            op1.pop();
        }else{
            stack1.push(z);
        }
        vol++;
    }
    while (!op1.empty()){
        stack1.push(op1.top());
        op1.pop();
    }
    cout << "\nInto Prefix: ";
    while (!stack1.empty()){
        cout << stack1.top();
        stack1.pop();
    }
    return 0;
}
