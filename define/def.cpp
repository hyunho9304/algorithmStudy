#include<bits/stdc++.h>
using namespace std ;

int main() {

    vector<int> v = { 1, 5, 4, 2, 7 } ;
    reverse( v.begin(), v.end() ) ;

    for( int num : v ) cout << num << " ";
    cout <<"\n";
    return 0 ;
    
}