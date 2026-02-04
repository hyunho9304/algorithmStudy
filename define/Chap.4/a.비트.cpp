
/*
1 ) +
    더하기

2 ) -
    뺄셈
    
3 ) &
    둘다 1일 경우만 1

4 ) |
    하나라도 1이라면 1

5 ) a << b
    a * pow( 2, b ) 

6 ) a >> b
    a * pow( 1/2, b)

7 ) XOR -> ^
    같으면 0

8 ) 1의 보수 -> ~
    ~a = -( a + 1 ) ;
    ~a = -a -1 ;

    -a = ~a + 1 
*/


#include<bits/stdc++.h>
using namespace std ;

const int max_n = 4 ;

int main() {

    int S = 18 ;    //  10010
    int idx = 1 ;

    //  idx 번째 비트 켜져있는지 꺼져있는지 확인
    //  켜져있으면 2의n승나온다. 꺼져있으면 0
    idx= 3 ;
    cout << "1 ) " << ( S & ( 1 << idx ) ) << "\n" ;

    
    //  idx 번째 비트 끄기          
    cout << "2 ) " << ( S & ~( 1 << idx ) ) << "\n" ;


    //  idx 번째 비트 켜기
    idx = 1 ;
    cout << "3 ) " << ( S | ( 1 << idx ) ) << "\n" ;


    //  idx 번째 비트 반전 
    //  idx 번째 비트를 0 -> 1, 1 -> 0 하고 싶다는 뜻
    cout << "4 ) " << ( S ^ ( 1 << idx ) ) << "\n" ;


    //  idx = ( S & -S )
    //  최하위 켜져있는 비트 찾기
    cout << "5 ) " << ( S & -S ) << "\n" ;


    //  크기가 n인 집합의 모든 비트를 켜기
    //  5 => 31 , 4 => 15 , 3 => 7
    int n = 5 ;
    cout << "6 ) " << ( 1 << n ) - 1 << "\n";




/*
    

__builtin_popcount(i) 는 1의 갯수


    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) != N / 2) continue;

        cout << "리셋" << "\n";

        vector<int> teamA, teamB;
        teamA.reserve(N / 2);
        teamB.reserve(N / 2);

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) teamA.push_back(v[j]);
            else teamB.push_back(v[j]);
        }

        cout << "Ateam" << "\n";
        for (int num : teamA) cout << num << " ";
        cout << "\n";

        cout << "Bteam" << "\n";
        for (int num : teamB) cout << num << " ";
        cout << "\n";
    }

    return 0 ;
*/