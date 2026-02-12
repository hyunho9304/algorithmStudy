//  라인스위핑
//  입력 속도 빠르게
#include<bits/stdc++.h>
using namespace std ;

int N ;
int from, to ;
vector<pair<int, int >> v ;

int ret ;

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);    

    cin >> N ;
    for( int i = 0 ; i < N ; i++ ) {
        cin >> from >> to ;
        v.push_back( {from, to }) ;
    }

    sort( v.begin(), v.end() ) ;

    from = v[0].first ;
    to = v[0].second ;
    ret = ( to - from ) ;

    for( int i = 1 ; i < v.size() ; i++ ) {

        if( v[i].second <= to ) continue ;
        else {

            if( to <= v[i].first ) {
                ret += ( v[i].second - v[i].first ) ;
                from = v[i].first ;
                to = v[i].second ;
            } else {
                ret += ( v[i].second - to ) ;
                to = v[i].second ;
            }
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}