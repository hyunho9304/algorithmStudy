#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void printV( int r) {

    for( int i = 0 ; i < r ; i++ )
        cout << v[i] << " " ;
    cout << "\n";
}

void makepermutation(int n, int r, int depth) {
    // cout << n << " : " << r << " : " << depth << "\n";
    if (r == depth) {
        printV(r);
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        makepermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        v.push_back(i);
    }

    makepermutation(3, 2, 0);
    return 0;
}