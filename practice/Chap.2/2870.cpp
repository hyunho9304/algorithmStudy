#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<string> ret ;
vector<string> str ;

bool cmp( string a, string b ) {

    if( a.size() != b.size() ) return a.size() < b.size() ;
    else return a < b ;
}

string erase(string s ) {


    while(true){  
		if(s.size() && s.front() == '0')s.erase(s.begin()); 
		else break;
	}

    if( s.size() == 0 ) s = "0" ;
    return s;
}

int main() {

    cin >> N ;

    for( int i = 0 ; i < N ; i++ ) {
        string tmpstr;
        cin >> tmpstr ;

        str.push_back( tmpstr) ;
    }

    for( string s : str ) {
        
        string tmpret = "" ;
        for( int i = 0 ; i < s.size() ; i++ ) {
            
            if( s[i] >= 'a' && s[i] <= 'z' ) {
                if( tmpret != "" ) {
                    ret.push_back( erase(tmpret) ) ;
                    tmpret = "" ;
                } else continue ;
            } else {
                tmpret += s[i] ; 

                if( i == s.size() - 1)  ret.push_back( erase( tmpret ) );
            }
        }
    }

    sort( ret.begin() , ret.end() , cmp) ;

    for( string num : ret )
        cout << num << "\n" ;

    return 0 ;
}