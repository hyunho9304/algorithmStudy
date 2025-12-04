#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = { 1 ,1 , 2 ,2, 3 ,3, 4 , 5 , 5 , 6 , 7 };
    sort(v.begin(), v.end() );
    
    v.erase( unique(v.begin(), v.end()), v.end());

    for( int vectorIt : v )
        cout << vectorIt << " " ;
    cout << "\n" ;

    return 0 ;
}