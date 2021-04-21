#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
long long int checkExpo(long long int);
int main(){
    printf("\t1 sec\t\t1 min\t\t1 hour\t\t1 day\t\t1 mon\t\t1 yr\t\t1 century\n");
    cout << std::scientific << setprecision(2) << "lg(n)\t2^" << pow(1000000,1) << "\t2^" << pow(60000000,1) << "\t2^" << pow(3600000000,1) << "\t2^" << pow(86400000000,1) << "\t2^" << pow(2629800000000,1) << "\t2^" << pow(31557600000000,1) << "\t2^" << pow(3155760000000000,1);
    cout << setprecision(2) << "\nsqrt(n)\t" << pow(1000000,2) << "\t" << pow(60000000,2) << "\t" << pow(3600000000,2) << "\t" << pow(86400000000,2) << "\t" << pow(2629800000000,2) << "\t" << pow(31557600000000,2) << "\t" << pow(3155760000000000,2);
    cout << setprecision(2) << "\nn\t" << pow(1000000,1) << "\t" << pow(1000000*60,1) << "\t" << pow(3600000000,1) << "\t" << pow(86400000000,1) << "\t" << pow(2629800000000,1) << "\t" << pow(31557600000000,1) << "\t" << pow(3155760000000000,1);
    cout << setprecision(2) << "\nn lg n\t" << 62746.00 << "\t" << 2800000.00 << "\t" << 130000000.00  << "\t" << 2700000000.00  << "\t" << 71000000000.00  << "\t" << 790000000000.00 << "\t" << 68000000000000.00;
    cout << setprecision(2) << "\nn^2\t" << sqrt(1000000) << "\t" << sqrt(60000000) << "\t" << sqrt(3600000000) << "\t" << sqrt(86400000000) << "\t" << sqrt(2629800000000) << "\t" << sqrt(31557600000000) << "\t" << sqrt(3155760000000000);
    cout << setprecision(2) << "\nn^3\t" << cbrt(1000000) << "\t" << cbrt(60000000) << "\t" << cbrt(3600000000) << "\t" << cbrt(86400000000) << "\t" << cbrt(2629800000000) << "\t" << cbrt(31557600000000) << "\t" << cbrt(3155760000000000);
    cout << setprecision(2) << "\n2^n\t" << (log(1000000) / log(2)) << "\t" <<(log(60000000) / log(2)) << "\t" << (log(3600000000) / log(2)) << "\t" << (log(86400000000) / log(2)) << "\t" << (log(2629800000000) / log(2)) << "\t" <<
    (log(31557600000000) / log(2)) << "\t" << (log(3155760000000000) / log(2));
    cout << setprecision(2) << "\nn!\t" << checkExpo(1000000) << "\t\t" << checkExpo(60000000) << "\t\t" << checkExpo(3600000000) << "\t\t" << checkExpo(86400000000) << "\t\t" << checkExpo(2629800000000) << "\t\t" << checkExpo(31557600000000) << "\t\t" << checkExpo(3155760000000000);
    return 0;
}

long long int checkExpo(long long int limit){
    long long int result = 1;
    int expo = 0;
    while(result < limit){
        expo++;
        result = result * expo;
    }
    return expo-1;
}
