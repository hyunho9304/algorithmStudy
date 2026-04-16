#include<bits/stdc++.h>
using namespace std ;

const int max_n = 20 ;

struct Vita {
    int p;
    int f;
    int s;
    int v;
    int cost;
} ;

int N ;
int mp, mf, ms, mv ;
Vita a[max_n] ;


int ret = 987654321 ;
vector<int> result ;

int main() {

    cin >> N ;
    cin >> mp >> mf >> ms >> mv ;

    for( int i = 0 ; i < N ; i++ ) {
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].cost ;
    }

    for( int i = 1 ; i < ( 1 << N ) ; i++ ) {

        vector<int> picked ;

        int sumP = 0 ;
        int sumF = 0 ;
        int sumS = 0 ;
        int sumV = 0 ;
        int sumCost = 0 ;
        for( int j = 0 ; j < N ; j++ ) {


            if( i & ( 1 << j ) ) {

                picked.push_back( j+1) ;
                sumP += a[j].p ;
                sumF += a[j].f ;
                sumS += a[j].s ;
                sumV += a[j].v ;
                sumCost += a[j].cost ;
            }
        }

        if( sumP >= mp && sumF >= mf && sumS >= ms && sumV >= mv ) {

            if( ret > sumCost ) {
                ret = sumCost ;
                result = picked ;
            } else if( ret == sumCost && picked < result ) {
                result = picked ;
            }
        }
    }

    if( ret == 987654321 ) cout << -1 << "\n" ;
    else {
        cout << ret << "\n" ;
        for( int num : result ) {
            cout << num << " " ;
        }
        cout << "\n" ;
    }

    return 0 ;
}