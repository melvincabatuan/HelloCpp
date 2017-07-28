#include <iostream>
#include <stack>

using namespace std;

bool isMatch(char current, char previous){
   bool match = false;
   if (previous == '(' && current == ')')
       match = true;
   if (previous == '{' && current == '}')
       match = true;
    if (previous == '[' && current == ']')
       match = true;
   return match; 
}

    

int main(){
    stack<char> balancer;
    char current = '\0', previous = '\0';
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        previous = s.at(0);
        balancer.push(previous);
        for(int i = 1; i < s.length(); i++){
               current = s.at(i);
               if (!isMatch(current, previous)){
		           balancer.push(current);
               } else {
                   balancer.pop();
               }
               if (!balancer.empty()){ 
                   previous = balancer.top();
               } else {
                   previous = '\0';
               }
        } 
        if (!balancer.empty()){ 
            cout << "NO" << endl;
            while(!balancer.empty()) // housekeeping
                  balancer.pop();
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}
