#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int order(char sign);
string InfToPost(string s);
string InfToPref(string s);

int main(){
    string input, test, test2;
    cout <<"Input an Infix Expression: ";
    cin>>input;
    cout <<"Postfix: ";
    cout << InfToPost(input) <<endl;
    cout <<"Prefix: ";
    cout << InfToPref(input);
}

int order(char sign){
    if(sign == '-'||sign == '+'){
        return 1; //Precedence of + and - is 1
    }
    else if(sign == '*'||sign == '/'){
        return 2; //Precedence of * and / is 1
    }
    else if(sign == '^'){
        return 3; //Precedence of ^ is 3
    }
    return 0;
}

string InfToPost(string s){
    s = '(' + s + ')';
    int size = s.size();
    stack<char> characters;
    string postfix;

    for(int i =0; i<size; i++){
        if(isalpha(s[i])){
            postfix += s[i]; //adds the character at s[i] to the string postfix
        }
        else if(s[i] == '('){
            characters.push(s[i]);
        }
        else if(s[i] == ')'){
            while(characters.top() != '('){
                postfix += characters.top(); //store and pop until ( has found
                characters.pop();
            }
            characters.pop();
        }
        else{
            if(!isalpha(characters.top())){ //checks if its a letter from the alphabet
                while(order(s[i]) <= order(characters.top())){
                    postfix += characters.top(); //stores and pops until stack is not empty
                    characters.pop();
                }
            }
            characters.push(s[i]);
        }
    }
    return postfix;
}

string InfToPref(string s){
    int size = s.size();
    reverse(s.begin(),s.end()); //reverse the string since prefix reads from R-L
    for(int i =0; i < size; i++){
        if(s[i] == ')'){
            s[i] = '(';
        }
        else if(s[i] == '('){
            s[i] = ')';
        }
    }
    s = '('+s+')';
    string prefix = InfToPost(s); //convert new reversed
    reverse(prefix.begin(),prefix.end()); //reverses result
    return prefix;
}
