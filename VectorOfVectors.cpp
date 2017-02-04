#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned int n, q, k, x;
    cin >> n >> q;
    vector< vector<unsigned int> > data(n);
    for(int i = 0; i < n; ++i){
        cin >> k;
        data[i].resize(k);
        for(int j = 0; j < k; ++j){
            cin >> x; 
            data[i][j] = x;
        }
    }
    
    unsigned int index, j_arr;
    for(int i = 0; i < q; ++i){
        cin >> index;
        cin >> j_arr;
        cout << data[index][j_arr] << endl;
    }
    
    return 0;
}
