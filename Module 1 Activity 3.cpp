#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    printf("\t\t\tAccess\tInsert\tSearch\tDelete\n");
    cout << "Static Array\t\tO(1)\tO(n)\tO(n)\tO(n)\n";
    cout << "Dynamic Array\t\tO(1)\tO(n)\tO(n)\tO(n)\n";
    cout << "Singly-Linked List\tO(n)\tO(n)\tO(1)\tO(1)\n";
    cout << "Doubly-Linked List\tO(n)\tO(n)\tO(1)\tO(1)\n";
    cout << "Stack\t\t\tO(n)\tO(n)\tO(1)\tO(1)\n";
    cout << "Queue\t\t\tO(n)\tO(n)\tO(1)\tO(1)\n";
    cout << "Binary Search Tree\tO(n)\tO(n)\tO(n)\tO(n)\n";
    cout << "Hash Table\t\tN/A\tO(n)\tO(n)\tO(n)\n";
    return 0;
}
