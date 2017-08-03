#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
	double a;
    double b;
} complex;


int main(){
    complex *first_complex;
    first_complex = (complex *)malloc(sizeof(complex));
    first_complex->a = 3;
    first_complex->b = 4; 
    cout << "The real part is " << first_complex->a << endl;
    cout << "The imag part is " << first_complex->b << endl;
    free(first_complex);
	return 0;
}
