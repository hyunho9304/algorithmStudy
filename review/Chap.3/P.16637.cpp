#include<bits/stdc++.h>
using namespace std ;

int N ;
string s ;
vector<int> numList;
vector<char> operList ;

int ret = -987654321 ;

int calc( int num1 , char op , int num2 ) {

    if( op == '+' ) return num1 + num2 ;
    else if( op == '-' ) return num1 - num2 ;
    else if( op == '*' ) return num1 * num2 ;

    return -1 ;
}

void go( int here, int result ) {

    if( here == (int)numList.size() - 1 ) {
        ret = max( ret, result ) ;
        return ;
    }

    go( here + 1 , calc( result , operList[here], numList[here+1] ) ) ;

    if( here + 2 <= (int)numList.size() - 1 ) {
        int tmp = calc( numList[here+1] , operList[here+1], numList[here+2] ) ;
        go( here + 2 , calc( result , operList[here], tmp ) ) ;
    }
}

int main() {

    cin >> N ;
    cin >> s ;
    for( int i = 0 ; i < (int)s.size() ; i++ ) {

        if( i % 2 == 0 ) numList.push_back( s[i] - '0' ) ;
        else operList.push_back( s[i] ) ;
    }

    go( 0, numList[0] ) ;

    cout << ret << "\n" ;
    return 0 ;
}