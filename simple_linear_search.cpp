#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


// Definition
typedef struct {
	string name;   // members
    string abbrev;
    int numOfDays;
} month; 

int main(){
	month currentMonth[12]; 
	// memory allocation
    currentMonth[0] = {"January","Jan",31};
    currentMonth[1] = {"February","Feb",28};
    currentMonth[2] = {"March","Mar",31};
    currentMonth[3] = {"April","Apr",30};
    currentMonth[4] = {"May","May",31};
    currentMonth[5] = {"June","Jun",30};
    string query;
    bool isFound = false;
    cout << "Enter the month to find: ";
    cin >> query;
    for(int i = 0; i < 6; ++i){
	   if(currentMonth[i].name == query) {
	    isFound = true;
	    cout << "Month is found at index " << i << endl;
	    cout << "currentMonth["<<i<<"].name = " << currentMonth[i].name  << endl; 
        cout << "currentMonth["<<i<<"].abbrev = " << currentMonth[i].abbrev  << endl;
        cout << "currentMonth["<<i<<"].numOfDays = " << currentMonth[i].numOfDays  << endl << endl;;
        }
    }
    if(!isFound) {
	    cout << "Month was not found!";
    }
	return 0;
}
