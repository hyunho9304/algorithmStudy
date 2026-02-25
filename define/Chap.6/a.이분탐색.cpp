#include<bits/stdc++.h>
using namespace std ;

int binarySearch( const vector<int> & arr, int target ) {

    int left = 0 ;
    int right = arr.size() - 1 ;

    while( left <= right ) {

        int mid = ( left + right ) / 2 ;

        if( arr[mid] == target ) {
            return mid ;
        } else if( arr[mid] < target ) {
            left = mid + 1 ;
        } else {
            right = mid - 1 ;
        }
    }

    return -1 ;
    
}

int main() {

    vector<int> arr = { 1, 3, 6, 9 , 10 , 21 , 22 , 30 } ;

    sort( arr.begin(), arr.end() ) ;

    int target = 6 ;
    int result = binarySearch( arr, target ) ;

    if( result == -1 ) {
        cout << "찾지못했다 \n" ;
    } else {
        cout << arr[result] << "\n" ;
    }

    return 0 ;
}