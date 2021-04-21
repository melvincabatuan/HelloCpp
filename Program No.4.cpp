#include <iostream>
#include <stack>

using namespace std;

int main (){
    stack<int> stacks;
    stacks.push(1000);
    stacks.push(2000);
    stacks.push(3000);
    stacks.top() -= 500;
    cout << "\n\n\n\t\tThe top of the stack is " <<
    stacks.top() << endl;
    return 0;
}
