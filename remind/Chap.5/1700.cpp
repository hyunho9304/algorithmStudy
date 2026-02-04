#include<bits/stdc++.h>
using namespace std ;

int N, K, num ;
vector<int> v ;
vector<int> plug ;

int ret ;

int main() {

    cin >> N >> K ;
    for( int i = 0 ; i < K ; i++ ) {
        cin >> num ;
        v.push_back( num ) ;
    }


    for( int i = 0 ; i < K ; i++ ) {

        int current = v[i] ;

        if( find( plug.begin(), plug.end(), current ) != plug.end() ) continue ;
    
        if( plug.size() < N ) {
            plug.push_back( v[i] ) ;
        } else {

            int value = -1 ;
            int far = -1 ;
            for( int p : plug ) {

                int idx = -1 ;
                for( int j = i + 1 ; j < K ; j++ ) {

                    if( p == v[j] ) {
                        idx = j ; break ;
                    }
                }

                if( idx == -1 ) {
                    value = p ;
                    break ;
                }
                
                if( far < idx ) {
                    far = idx ;
                    value = v[idx] ;
                }
            }

            for( int &p : plug ) {
                if( p == value ) {
                    p = current ; break ;
                }
            }

            ret++ ;
        }
    }

    cout << ret << "\n" ;
    return 0 ;
}