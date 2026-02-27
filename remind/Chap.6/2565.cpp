/*
    이분탐색 - 최대증가부분수열
*/
#include<bits/stdc++.h>
using namespace std ;

int N;
int num1, num2 ;
vector<pair<int,int>> v ;
int cnt[104] ;

int ret ;

int main() {

    fill( cnt, cnt + 104 , 1 ) ;

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> num1 >> num2 ;
        v.push_back( {num1, num2 }) ;
    }

    sort( v.begin(), v.end() ) ;

    for( int i = 0 ; i < N ; i++ ) {

        for( int j = 0 ; j < i ; j++ ) {

            if( v[j].second < v[i].second && cnt[i] < cnt[j] + 1 ) {

                cnt[i] = cnt[j] + 1 ;


            }
        }

        if( ret < cnt[i] ) {
            ret = cnt[i] ;
        }
    }

    cout << N - ret << "\n" ;
    return 0 ;
}