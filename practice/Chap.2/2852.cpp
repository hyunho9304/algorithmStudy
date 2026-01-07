#include<bits/stdc++.h>
using namespace std ;

int N ;
int team1, team2 ;
pair<int,int> p ;

string func2( int num ) {

    int min = num / 60 ;
    int sec = num % 60 ;

    string minStr = (min < 10 ? "0" : "") + to_string(min);
    string secStr = (sec < 10 ? "0" : "") + to_string(sec);
    return minStr + ":" + secStr ;
    
}

int func( string tmpTime ) {

    size_t pos = tmpTime.find(':');
    string tmpMin = tmpTime.substr(0, pos);
    string tmpSec = tmpTime.substr( pos+1 ) ;

    int result = ( stoi(tmpMin) * 60 ) + stoi(tmpSec) ;
    return result ;
}
int main() {

    cin >> N ;
    int startTime = 0 ;
    for( int i = 0 ; i < N ; i++ ) {
        int teamNum ;
        cin >> teamNum ;

        string tmpTime ; int timeSec ;
        cin >> tmpTime ; timeSec = func(tmpTime);

        if(  p.first > p.second ) {
            team1 += timeSec - startTime ;
        } else if( p.first < p.second ) {
            team2 += timeSec - startTime ;
        }

        if( teamNum == 1 ) p.first++ ;
        else p.second++ ;

        startTime = timeSec ;
        
    }

    if( p.first > p.second ) team1 += ((48 * 60) - startTime);
    else if( p.first < p.second ) team2 += ((48 * 60) - startTime );

    cout << func2(team1) << "\n" << func2(team2) << "\n" ;
    return 0;


}