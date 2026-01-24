#include<bits/stdc++.h>
using namespace std ;

int N, K ;
int words[51] ;

int ret = -1 ;

int countReadables(int know) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {                 // N까지만
        if ((words[i] & know) == words[i]) cnt++;
    }
    return cnt;
}

int go(int alphabet, int remain, int know) {
    if (remain < 0) return 0;
    if (alphabet == 26) return countReadables(know);

    // 이미 포함된 알파벳이면 그대로 진행
    if (know & (1 << alphabet)) {
        return go(alphabet + 1, remain, know);
    }

    // 선택/비선택 두 분기
    int take = go(alphabet + 1, remain - 1, know | (1 << alphabet));
    int skip = go(alphabet + 1, remain, know);
    return max(take, skip);
}

int main() {

    cin >> N >> K ;
    for( int i = 0 ; i < N ; i++ ) {
        string s ;
        cin >> s ;
        for( char ch : s ) {
            words[i] |= ( 1 << ( ch - 'a' ) ) ;
        }
    }

    // 'antic' 미리 포함
    int know = 0;
    for (char ch : string("antic")) know |= (1 << (ch - 'a'));

    cout << go( 0, K-5 , know ) << "\n" ;

    return 0 ;



}