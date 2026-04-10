#include<bits/stdc++.h>
using namespace std ;

int A, B, C ;
int retHour, retMin ;

int main() {

    cin >> A >> B >> C ;

    int tmp = B + C ;

    int tmpHour = tmp / 60 ;
    int tmpMin = tmp % 60 ;

    retHour = A + tmpHour ;
    retMin = tmpMin ;

    cout << retHour % 24 << " " << retMin << "\n" ;

    return 0 ;
}



