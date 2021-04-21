#include <iostream>
#include <stack>

using namespace std;

int main (){
    stack<int> stacks;
    int add (0);
    for (int i=1;i<=100;i++){
        cout << "Added " << i << endl;
        stacks.push(i);
    }
    while (!stacks.empty()){
        add += stacks.top();
        stacks.pop();
    }
    cout <<"\n \n \n \t \t \t"<< "The sum of all number is: " << add << endl;
    return 0;
}
