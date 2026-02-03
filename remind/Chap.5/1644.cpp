//  투포인터
//  소수만들기 외우기

#include<bits/stdc++.h>
using namespace std ;

int N ;
vector<int> v ;
int l, r ;
long long sum ;

int ret ;

void sieve(int n){

    vector<bool> is(n+1, true);
    if(n>=0) is[0]=false;
    if(n>=1) is[1]=false;
    for(int i=2;i*i<=n;i++) {
        if(is[i]) {
            for(long long j=1LL*i*i;j<=n;j+=i) {
                is[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(is[i]) v.push_back(i);
    } 
}

int main() {
    cin >> N ;
    sieve(N) ;

    while( true ) {

        if( sum >= N ) {
            
            if( sum == N ) ret++ ;

            sum -= v[l++] ;
        } else {

            if( r == v.size() ) break ;

            sum += v[r++] ;
        }
        
    }

    cout << ret << "\n" ;
    return 0 ;
    
    
}
