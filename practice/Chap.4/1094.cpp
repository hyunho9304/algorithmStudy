//  재귀함수 풀이
// #include<bits/stdc++.h>
// using namespace std ;

// int X ;
// int ret ;

// void func( int current, int sum , int cnt ) {

//     if( sum == X ) {
//         ret = cnt ; return ;
//     }

//     int plusNum = sum + current ;

//     if( X < plusNum ) {
//         func( current / 2 , sum, cnt ) ;
//     } else {
//         func( current / 2 , plusNum, cnt + 1 ) ;
//     }
    
// }

// int main() {
    
//     cin >> X ;

//     func(64, 0, 0 ) ;


//     cout << ret << "\n" ;
//     return 0 ;
// }



#include<bits/stdc++.h>
using namespace std ;

int X ;
int ret ;

int main() {

    cin >> X ;

    while( X > 0 ) {
        
        int num = X % 2 ;
        if( num == 1 ) ret++ ;

        // if( X & 1 ) ret++ ;  홀수라면으로 같은말

        X /= 2 ;

    }
    
    cout << ret << "\n" ;
    return 0 ;
}









//  2진수로 변경하는 방법
// #include<bits/stdc++.h>
// using namespace std ;

// int X ;

// int main() {

//     cin >> X ;

//     string str = "" ;
//     while( X != 1 ) {
        
//         int num = X % 2 ;
//         if( num == 1 ) str += "1" ;
//         else str += "0" ;

//         X /= 2 ;

//         if( X == 1 ) str += "1" ;
//     }
    
//     reverse(str.begin(), str.end());
//     cout << str << "\n" ;
//     return 0 ;
// }