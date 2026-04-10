#include<bits/stdc++.h>
using namespace std ;

int A, B ;
double ret ;

int main() {

    cin >> A >> B ;
    ret = (double)A / B ;
    
    cout << fixed << setprecision(9) << ret << "\n" ;
    return 0 ;
}