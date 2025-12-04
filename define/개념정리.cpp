/*
Title : 순열( 순서 O ) nPr = n! / (n - r )!
Desc : 1 ) 순열( next_permutation 이용 ) - vector, arr 버전
        2 ) 재귀함수를 이용한 순열
*/

//  1 ) 순열( next_permutation 이용 )
#include <bits/stdc++.h>
using namespace std;
int main() {

    // arr 버전
    int a[] = {1, 2, 3};
    do {
        for (int i : a) cout << i << " ";
        cout << '\n';
    } while (next_permutation(&a[0], &a[0] + 3));

    // vector 버전
    vector<int> v = { 1,2,3 } ;
    do {
        for( int a : v )
            cout << a << " " ;
        cout << "\n" ;
    } while( next_permutation(v.begin() , v.end() ) );
}

//  2 ) 재귀함수를 이용한 순열
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


/*
Title : 조합( 순서 X ) nCr = n! / (n - r)! r!
Desc : 1 ) 재귀함수를 이용한 조합
        2 ) 반복문을 이용한 조합( r이 작을 경우 유리 )
*/

//  1 ) 재귀함수를 이용한 조합
#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};

void print(vector<int> b) {
    for (int i : b) cout << a[i] << " ";
    cout << '\n';
}

void combi(int start, vector<int>& b) {
    if (b.size() == k) {
        print(b);
        return;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main() {
    vector<int> b;
    combi(-1, b);
    return 0;
}

//  2 ) 반복문을 이용한 조합( r이 작을 경우 유리 )
#include <bits/stdc++.h>
using namespace std;
int n = 5;
int k = 3;
int a[5] = {1, 2, 3, 4, 5};
int main() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << i << " " << j << " " << k << '\n';
            }
        }
    }
    return 0;
}

/*
Title : split 함수 정의
Desc : 문자열을 기준으로 split 함수 구현
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, string delimeter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimeter);

    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimeter.size();
        end = input.find(delimeter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main() {
    string str = "apple,aaaa,bbbb,ccccccc,dddd,eee";
    vector<string> vstr = split(str, ",");

    for (const string& tmpstr : vstr) cout << tmpstr << " ";
    cout << "\n";
}

/*
Title : erase, unqiue
Desc : vector 안의 숫자 중복 제거
*/
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = { 1 ,1 , 2 ,2, 3 ,3, 4 , 5 , 5 , 6 , 7 };
    sort(v.begin(), v.end() );
    
    v.erase( unique(v.begin(), v.end()), v.end());

    for( int vectorIt : v )
        cout << vectorIt << " " ;
    cout << "\n" ;

    return 0 ;
}


