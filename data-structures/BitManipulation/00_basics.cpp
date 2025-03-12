#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n = 5;

    // How to check that the rightmost bit is set or not
    if(n & 1) cout << "set bit" << endl;
    else cout << "not set bit" << endl;
    
    // right shift 
    cout << (n >> 1);
    return 0;
}