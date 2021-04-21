#include<iostream>
#include<stack>
using namespace std;
void convert(int n) {  //number = n
   stack<int> s;       //stack = s
   while(n > 0) {   
      int r = n % 2; //remainder = r
      n = n / 2;
      s.push(r);
   }
   while(!s.empty()) {
      int v;            //value = v
      v = s.top();
      s.pop();
      printf("%d",v);
   }
}
main() {
   int n;
   printf("Enter a decimal: ");
   scanf(" %d",&n);
   convert(n);
}
