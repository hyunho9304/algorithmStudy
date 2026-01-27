#include<bits/stdc++.h>
using namespace std ;

int M ;

int S = 0;

void func(const string& op, int num) {

    
    if (op == "add") {
        S |= (1 << (num ));
    } else if (op == "remove") {
        S &= ~(1 << (num ));
    } else if (op == "check") {
        cout << ((S & (1 << (num ))) ? 1 : 0) << '\n';
    } else if (op == "toggle") {
        S ^= (1 << (num ));
    } else if (op == "all") {
        S = (1 << 21) - 1;
    } else if (op == "empty") {
        S = 0;
    }
}

int main() {

    cin >> M ;
    
    int num ;
    string op ;

    for( int i = 0 ; i < M ; i++ ) {
        cin >> op ;
        cin >> num ;

        func( op, num ) ;
        
    }

    return 0 ;

}


/*
#include <bits/stdc++.h>
using namespace std;
int n, m, x;
char s[11];
int main() {
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        scanf(" %s %d", &s, &x); 
        if (s[0]=='a' && s[1]=='d') n |= (1 << x);
        else if (s[0] == 'r') n &= ~(1 << x);
        else if (s[0] == 'c') printf("%d\n", (n&(1 << x)) ==0? 0: 1);
        else if (s[0] == 't') n ^=(1<<x);
        else if (s[0] == 'a' && s[1] == 'l') n = (1 << 21) - 1;
        else n = 0;
    }
}

*/