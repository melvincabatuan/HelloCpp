#include <iostream>
#include <stack>
using namespace std; 
  
bool isOperator(char check) 
{ 
    return (!isalpha(check) && !isdigit(check)); 
} 

int proc(char check) // proc = operator precedence 
{ 
    if(check == '^') 
    return 3; 
    else if(check == '*' || check == '/') 
    return 2; 
    else if(check == '+' || check == '-') 
    return 1; 
    else
    return -1; 
} 
  
string intopost(string in) // string for infix to postfix, in = infix
{ 
    stack<char> stacks; 
    stacks.push('o'); 
    int g = in.length(); 
    string post; // postfix
    for(int h = 0; h < g; h++) 
    { 
          
        if((in[h] >= 'a' && in[h] <= 'z') || (in[h] >= 'A' && in[h] <= 'Z')) 
        post+=in[h]; 
  
        else if(in[h] == '(') 
        stacks.push('('); 
    
        else if(in[h] == ')') 
        { 
            while(stacks.top() != 'o' && stacks.top() != '(') 
            { 
            	char check = stacks.top(); 
                stacks.pop(); 
                post += check; 
            } 
            if(stacks.top() == '(') 
            { 
                char check = stacks.top(); 
                stacks.pop(); 
            } 
        } 
          
        else{ 
            while(stacks.top() != 'o' && proc(in[h]) <= proc(stacks.top())) 
            { 
                char check = stacks.top(); 
                stacks.pop(); 
                post += check; 
            } 
            stacks.push(in[h]); 
        } 
  
    } 
    
    while(stacks.top() != 'o') 
    { 
        char check = stacks.top(); 
        stacks.pop(); 
        post += check; 
    } 
      
    return post; 
} 
  
string intopre(string in) //infix to prefix
{
	stack<char> symbols; 
    stack<string> quantity; 
  
    for (int h = 0; h < in.length(); h++) { 
        if (in[h] == '(') { 
            symbols.push(in[h]); 
        } 
  
        else if (in[h] == ')') { 
            while (!symbols.empty() &&  symbols.top() != '(') { 
                string sym1 = quantity.top(); 
                quantity.pop(); 
  
                string sym2 = quantity.top(); 
                quantity.pop(); 

                char sym3 = symbols.top(); 
                symbols.pop(); 

                string symall = sym3 + sym2 + sym1; 
                quantity.push(symall); 
            } 
            symbols.pop(); 
        } 

        else if (!isOperator(in[h])) { 
            quantity.push(string(1, in[h])); 
        } 

        else { 
            while (!symbols.empty() && proc(in[h]) <= proc(symbols.top())) { 
  
                string sym1 = quantity.top(); 
                quantity.pop(); 
  
                string sym2 = quantity.top(); 
                quantity.pop(); 
  
                char sym3 = symbols.top(); 
                symbols.pop(); 
  
                string symall = sym3 + sym2 + sym1; 
                quantity.push(symall); 
            } 
  
            symbols.push(in[h]); 
        } 
    } 
 
    while (!symbols.empty()) { 
        string sym1 = quantity.top(); 
        quantity.pop(); 
  
        string sym2 = quantity.top(); 
        quantity.pop(); 
  
        char sym3 = symbols.top(); 
        symbols.pop(); 
  
        string symall = sym3 + sym2 + sym1; 
        quantity.push(symall); 
    } 
  
    return quantity.top(); 
}

main() 
{ 
	string in;
    cout << "Enter Infix: "; 
    cin >> in;
    cout << "Postfix Notation: " << intopost(in) << endl; 
	cout << "Prefix Notation: " << intopre(in); 
} 
