#include<bits/stdc++.h>
using namespace std ;

int T, N, M, num ;
vector<int> v1 ;

int binarySearch( const vector<int> &v , int target ) {

    int left = 0 ;
    int right = v.size() - 1;

    while( left <= right ) {

        int mid = ( left + right ) / 2 ;

        if( v[mid] == target ) {
            return mid ;
        } else if( v[mid] < target ) {
            left = mid + 1 ;
        } else {
            right = mid - 1 ;
        }
    }

    return -1 ;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   

    cin >> T ;

    while( T > 0 ) {

        v1.clear();

        cin >> N ;
        for( int i = 0 ; i < N ; i++ ) {
            cin >> num ;
            v1.push_back(num);
        }

        sort( v1.begin(), v1.end() );

        cin >> M ;
        for( int i = 0 ; i < M ; i++ ) {
            cin >> num ;
            
            int result = binarySearch( v1, num ) ;

            if( result == -1 ) {
                cout << "0" << "\n" ;
            } else {
                cout << "1" <<"\n" ;
            }
        }

        T--;
    }
    return 0;
}