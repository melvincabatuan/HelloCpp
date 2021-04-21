#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> stack1;
    stack<char> op1;
    stack<char> input;

    char x;

    for (int i=1; i<=21; ++i){
        cout<<"Enter character: ";
        cin>>x;
        if(x == '+' || x == '-' || x == '/' || x == '*'){
            op1.push(x);
        }else if(x == '('){
            stack1.push(op1.top());
            op1.pop();
        }else if(x != ')'){
            stack1.push(x);
        }
        input.push(x);
    }

    while (!op1.empty()){
        stack1.push(op1.top());
        op1.pop();
    }

    cout << "\nPrefix Form: ";
    while (!stack1.empty()){
        cout << " " << stack1.top();
        stack1.pop();
    }

    for (int i=1; i<=21; ++i){
        x = input.top();
        input.pop();
        if(x == '+' || x == '-' || x == '/' || x == '*'){
            op1.push(x);
        }else if(x == ')'){
            while (!op1.empty()){
                stack1.push(op1.top());
                op1.pop();
                }
        }else if(x != '('){
            stack1.push(x);
        }
    }

    while (!op1.empty()){
        stack1.push(op1.top());
        op1.pop();
    }

    while (!stack1.empty()){
        input.push(stack1.top());
        stack1.pop();
    }

    cout << "\nPostfix Form: ";
    while (!input.empty()){
        cout << " " << input.top();
        input.pop();
    }
    cout << endl;
    return 0;
}
