#include<stdio.h>
#include<math.h>
//Yap Module 1
//Conversion to Microseconds
double time (int i){
	
	if (i==0){
		return 1000000;
	}
	else if (i==1){
		return 60000000;
	}
	else if (i==2){
		return 3600000000;
	}
	else if (i==3){
		return 86400000000;
	}
	else if (i==4){
		return 2629800000000;
	}
	else if (i==5){
		return 31557600000000;
	}
	else if (i==6){
		return 3155760000000000;
	}	
}

int main(void){
	int i, ntwo, nthree, twon, a, b;
	double sqrtn, test, column;
	printf("\t1 second\t1 minute\t1 hour\t\t1 day\t\t1 month\t\t1 year\t\t1 century\n");
	
	//Log of N Formula
	printf("\nlgn\t");
	for(i=0;i<=6;i++){
		printf("2^");
		printf("%2.e\t",time(i));
	}
	
	//Square Root of N Formula
	printf("\nsqrtOfn");
	for(i=0;i<=6;i++){
		sqrtn = pow(time(i), 2);
		printf("%.2e\t", sqrtn);
	}
	
	//N Display
	printf("\nn\t");
	for(i=0;i<=6;i++){
		printf("%.2e\t", time(i));
	}
	
	//nlogn Formula
	printf("\nnlgn\t");
	for(i=0;i<=6;i++){
		test=time(i)/(log(time(i))/log(2));
		
	while(test!=column){
		column=test;
		test=time(i)/(log(column)/log(2));
	}
		printf("%.2e\t", test);
	}
	
	//N Squared Formula
	printf("\nn^2\t");
	for(i=0;i<=6;i++){
		ntwo =  pow(time(i),.5);	
		printf("%d\t\t", ntwo);
	}
	
	//N Cubed Formula
	printf("\nn^3\t");
	for(i=0;i<=6;i++){
		nthree= pow(time(i),.33);
		printf("%d\t\t", nthree);
	}
	
	//2^n Formula
	printf("\n2^n\t");
	for(i=0;i<=6;i++){
		twon = log(time(i))/log(2);
		printf("%d\t\t", twon);
	}
	
	//N Factorial Formula
	printf("\nn!\t");
	for(i=0;i<=6;i++){
		double finalmicro=time(i);
		a=1;
		while(finalmicro>1){
		finalmicro=finalmicro/a;
		a++;
		}
		b = a-2;
		printf("%d\t\t", b);
	}
}

