//  NlogN 의 시간복잡도로 가장 빠름. 하지만, 트레이스 불가
#include<bits/stdc++.h>
using namespace std ;

int N, len, num ;
int lis[1001] ;

int main() {

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {

        cin >> num ;

        auto lowerPos = lower_bound( lis, lis + len , num ) ;

        if( *lowerPos == 0 ) len++ ;

        *lowerPos = num ;

        // for( int j = 0 ; j < N ; j++ ) {
        //     cout << lis[j] << " " ;
        // }
        // cout << "\n" ;
    }

    cout << len << "\n";
    return 0 ;

}