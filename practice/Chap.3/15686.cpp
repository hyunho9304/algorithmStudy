#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;
int N, M ;
int a[max_n][max_n] ;

vector<pair<int,int>> house ;
vector<pair<int,int>> chi ;
vector<vector<int>> chickenList ;
int result = 987654321;

void combi( int start , vector<int> &v ) {
    
    if( v.size() == M) {
        chickenList.push_back( v ) ;
        return ;
    }

    for( int i = start + 1 ; i < chi.size() ; i++ ) {
        v.push_back(i) ;
        combi( i, v ) ;
        v.pop_back() ;
    }
    return ;
}

int main() {

    cin >> N >> M ;
    for( int i = 0 ; i < N ; i++ ) {
        for( int j = 0 ; j < N ;j++ ) {
            cin >> a[i][j] ;
            if( a[i][j] == 1 ) {
                house.push_back( {i,j});
            } else if( a[i][j] == 2 ) {
                chi.push_back( {i,j});
            }
        }
    }

    vector<int> v ;
    combi( -1, v ) ;

    for( vector<int> chicken : chickenList ) {
        int ret = 0 ;
        for( pair<int,int> home : house ) {
            int _min = 987654321 ;
            for( int idx : chicken ) {
                int dist = abs(home.first - chi[idx].first) + abs(home.second - chi[idx].second);
                _min = min( _min, dist ) ;
            }
            ret += _min ;
        }
        result = min(result, ret);
    }

    cout << result << "\n" ;
    return 0 ;
}
