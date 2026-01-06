#include<bits/stdc++.h>
using namespace std ;

int N ;
long long int C;
map<long long int,int> mp ;
map<long long int,int> mp_first ;
vector<pair<long long int, int>> v ;

bool cmp( pair<long long int,int> a, pair< long long int, int > b ) {

    if( a.second == b.second ) {
        return mp_first[a.first] < mp_first[b.first] ;
    }

    return a.second > b.second ;
}

int main() {

    cin >> N >> C ;

    for( int i = 0 ; i < N ; i++ ) {
        long long int x ;
        cin >> x ;

        mp[x]++ ;

        if( mp_first[x] == 0 ) mp_first[x] = i + 1 ;
    }

    for( auto it : mp )
        v.push_back( {it.first, it.second}) ;

    sort( v.begin(), v.end(), cmp ) ;

    for(auto i : v){
		for(int j = 0; j < i.second; j++){
			cout << i.first << " ";
		}
	} 
    return 0;

}