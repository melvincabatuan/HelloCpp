#include <iostream>

using namespace std;

#define M 3
#define N 3

void multiplyMatrix(double m1[M][N], double m2[M][N], double result[M][N], 
int row1, int col1, int row2, int col2){
	if (col1 != row2){
	   cerr << "Invalid Matrix Multiplication" << endl;
       exit(-1);
    }
    for (int rows = 0; rows < row1; rows++ ) {
	    for (int cols = 0; cols < col2; cols++  ){
            result[rows][cols] = 0.0;
            for (int k = 0; k < col1; k++)
                 result[rows][cols] += m1[rows][k] * m2[k][cols];
        }
    }      
         
}

int main(){
	double result[M][N];
    double m1[M][N];
    int row1, col1;
    double m2[M][N];
    int row2, col2;

    cout << "How many rows for the first matrix: " ;
    cin >> row1;
    cout << "How many cols for the first matrix: " ;
    cin >> col1;
    cout << "Enter the elements: \n";
    for (int i = 0; i < row1; i++){
	    for (int j = 0; j < col1; j++){	
             cout << "m1[" << i <<"][" << j <<"] = ";
             cin >> m1[i][j];
        }
    }

    cout << "How many rows for the second matrix: " ;
    cin >> row2;
    cout << "How many cols for the second matrix: " ;
    cin >> col2;
    cout << "Enter the elements: \n";
    for (int i = 0; i < row2; i++){
	    for (int j = 0; j < col2; j++){	
             cout << "m2[" << i <<"][" << j <<"] = ";
             cin >> m2[i][j];
        }
    }
   
    multiplyMatrix(m1, m2, result, row1, col1, row2, col2);


    for (int i = 0; i < row1; i++){
	   for(int j = 0; j < col2; j++)
          cout << result[i][j] << " ";
       cout << endl;
    }     
    return 0;
}
