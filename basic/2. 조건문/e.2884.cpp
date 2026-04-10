#include<bits/stdc++.h>
using namespace std ;

int H, M ;
int retH, retM ;

int main() {

    cin >> H >> M ;

    if( M - 45 >= 0 ) {
        retH = H ;
        retM = M - 45 ;
    } else {

        retM = 60 + ( M - 45 ) ;

        if( H - 1 >= 0 ) retH = H - 1 ;
        else {
            retH = 24 + ( H - 1 ) ;
        }
    }

    cout << retH << " " << retM << "\n" ;

    return 0 ;
}