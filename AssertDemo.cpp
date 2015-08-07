#include <iostream>


const double c = 299792.458; // km/s


void f(const double speed)
{
	 const double local_max = 160.0/(60*60); //160 km/h == 160.0/(60*60) km/s
	//static_assert(speed < c,"can't go that fast"); 
	 static_assert(local_max < c,"can't go that fast"); // OK
}


int main()
{
    const double v = 300000.0; // km/s
	f(v); 
}
