#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <string.h>

//((A+(B*(C/A)))-(B/C)) equation infix

using namespace std;

void preFix(){
	string prefix = "";
	stack<char> operatorStack;
	string infixEquation = "((A+(B*(C/A)))-(B/C))";
	for(int i = infixEquation.size()-1; i>=0; i--){
		char input = infixEquation[i];
		if(isalpha(input)){
			prefix+=input;
		}
		else if(input == '('){
			prefix+=operatorStack.top();
			operatorStack.pop();
		}
		else if(input == ')'){
			continue;
		}
		else{
			operatorStack.push(input);
		}
	}
	while(!operatorStack.empty()){
		prefix+=operatorStack.top();
		operatorStack.pop();
	}
	cout<<"Prefix: ";
	for(int j = prefix.size()-1;j>=0;j--){
		cout<<prefix[j];
	}
	cout<<"\n";
}

void postFix(){
	string postfix = "";
	stack<char> operatorStack;
	string infixEquation = "((A+(B*(C/A)))-(B/C))";
	for(int i = 0; i<infixEquation.size();i++){
		char input = infixEquation[i];
		if(isalpha(input)){
			postfix+=input;
		}
		else if(input == '('){
			continue;
		}
		else if(input == ')'){
			postfix+=operatorStack.top();
			operatorStack.pop();
		}
		else{
			operatorStack.push(input);
		}
	}
	cout<<"Postfix: "<<postfix;
}

int main ()
{
	cout<<"Infix"<<"((A+(B*(C/A)))-(B/C))"<<"\n";
  	preFix();
  	postFix();
    }
