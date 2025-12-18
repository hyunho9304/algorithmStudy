/*
Title : 구현
Desc : rotate, substr 등등

g++ -std=c++14 -Wall b.구현.cpp -o b.구현.out 
*/

#include<bits/stdc++.h>
using namespace std ;

string dopa = "abcde" ;

int N , tmpNum ;
double avg ;
vector<int> num ;

int main() {

    // 앞에서 3개의 문자열을 출력하라
    string astr = dopa.substr(0,3);
    cout << astr << "\n" ;

    //  해당문자열을 거꾸로 출력하라
    reverse(astr.begin(), astr.end() );
    cout << astr << "\n" ;

    //  문자열 추가
    astr.append( "bbbbbbbbb");
    cout << astr << "\n" ;


    cin >> N ;
    for( int i = 0 ; i < N ; i++) {
        cin >> tmpNum ;
        num.push_back( tmpNum ) ;
        avg += tmpNum ;
    }

    sort( num.begin() , num.end() );

    for( int result : num ) {
        cout << result << " " ;
    }
    cout << "\n" ;
    cout << fixed << setprecision(2) << avg / N << "\n";
    
    return 0 ;

}