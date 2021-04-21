#include <iostream>
#include <stack> 
#include <algorithm> 

using namespace std;

int order(char c) 
{  
    if (c == '*' || c == '/'){
    return 2; 
    }else if (c == '+' || c == '-'){
    return 1; 
    }else {
    return -1;
	}
} 
  
string infixToPostfix(string infix) 
{ 
    stack<char> stack; 
    int len = infix.length(); 
    string postfix; 
    for(int i = 0; i < len; i++){ 
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
        	postfix += infix[i]; 
    	}else if(infix[i] == '('){
        	stack.push('('); 
    	}else if(infix[i] == ')'){ 
            while(!stack.empty() && stack.top() != '('){ 
                char c = stack.top(); 
                stack.pop(); 
                postfix += c; 
            } 
            if(stack.top() == '('){ 
                char c = stack.top(); 
                stack.pop(); 
            } 
        }else{ 
            while(!stack.empty() && order(infix[i]) <= order(stack.top())){ 
                char c = stack.top(); 
                stack.pop(); 
                postfix += c; 
            } 
            stack.push(infix[i]); 
        } 
    } 
    
    while(!stack.empty()){ 
        char c = stack.top(); 
        stack.pop(); 
        postfix += c; 
    }
    return postfix; 
} 

string infixToPrefix(string infix){
	int len = infix.length();
	reverse(infix.begin(),infix.end());
	for (int i = 0; i < len; i++){
		if (infix[i] == '('){
			infix[i] = ')';
			i++;
		}else if (infix[i] == ')'){
			infix[i] = '(';
			i++;
		}else{
			i++;
		}
	}
	string prefix = infixToPostfix(infix);
	reverse(prefix.begin(),prefix.end());
	return prefix;
}

main (){
	string infix = "((A+(B*(C/A)))-(B/C))";
	cout << "Expression: " << infix << endl;
	cout << "Postfix: ";
	cout << infixToPostfix(infix) << endl;
	cout << "Prefix: ";
	cout << infixToPrefix(infix) << endl;
	return 0;
}






