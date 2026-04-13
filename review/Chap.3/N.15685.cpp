#include<bits/stdc++.h>
using namespace std ;

const int max_n = 54 ;

int N , M ;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken ;
vector<vector<pair<int,int>>> remainChickenList ;

int result = 987654321 ;

void combi( int start , vector<int>& b ) {
    if( (int)b.size() == M ) {
        
        vector<pair<int,int>> tmp ;
        for( int i : b ) {
            tmp.push_back( chicken[i]) ;
        }

        remainChickenList.push_back( tmp ) ;

        return ;
    }

    for( int i = start + 1 ; i < (int)chicken.size() ; i++ ) {
        b.push_back(i ) ;
        combi( i, b ) ;
        b.pop_back() ;
    }
}

int main() {

    cin >> N >> M ;

    int num ;
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= N ; j++ ) {
            cin >> num ;

            if( num == 1 ) house.push_back( { i, j} ) ;
            else if( num == 2 ) chicken.push_back( { i, j} ) ;
        }
    }


    vector<int> b ;
    combi( -1, b ) ;

    for( vector<pair<int,int>> tmpChickenList : remainChickenList ) {

        int ret = 0 ;
        for( pair<int,int> housePoint : house ) {

            int dist = 987654321 ;
            int houseY = housePoint.first ;
            int houseX = housePoint.second ;

            for( pair<int,int> chickenPoint : tmpChickenList ) {

                int chickenY = chickenPoint.first ;
                int chickenX = chickenPoint.second ;

                int num = abs( houseY - chickenY ) + abs( houseX - chickenX ) ;
                dist = min( dist, num ) ;
            }
            ret += dist ;
        }

        result = min( result, ret ) ;

    }

    cout << result << "\n" ;

    return 0 ;
    
}