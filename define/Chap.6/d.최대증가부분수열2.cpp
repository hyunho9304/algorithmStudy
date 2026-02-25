//  트레이스 가능한 로직

#include<bits/stdc++.h>
using namespace std ;

int N , ret ;
int a[1001];
int cnt[1001] ;
int prevList[1001];
int idx ;
vector<int> v ;

void go( int idx ) {

    if( idx == -1 ) return ;

    v.push_back( a[idx] ) ;
    go( prevList[idx] ) ;

    return ;
}

int main() {

    fill( prevList, prevList + 1001 , -1 ) ;
    fill( cnt, cnt + 1001 , 1 ) ;

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> a[i] ;
    }

    for( int i = 0 ; i < N ; i++ ) {

        for( int j = 0 ; j < i ; j++ ) {
            if( a[j] < a[i] && cnt[i] < cnt[j]+1 ) {
                
                cnt[i] = cnt[j] + 1 ;
                prevList[i] = j ;

                if( ret < cnt[i] ) {
                    ret = cnt[i] ;
                    idx = i ;
                }
            }
        }
    }

    cout << ret << "\n" ;
    go( idx ) ;

    for( int i = v.size() -1 ; i >= 0 ; i-- ) {
        cout << v[i] << " " ;
    }
    cout << "\n" ;
    return 0 ;
}