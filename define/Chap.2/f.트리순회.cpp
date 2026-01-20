#include<bits/stdc++.h>
using namespace std ;

vector<int> adj[1004];
int visited[1004] ;

//  왼쪽 오른쪽 나
void postorder( int here) {

    if( visited[here] == false ) {
        if( adj[here].size() == 1 ) postorder( adj[here][0] ) ;
        if( adj[here].size() == 2 ) {
            postorder( adj[here][0] ) ;
            postorder( adj[here][1] ) ;
        }
        visited[here] = true ;
        cout << here << " " ;
    }
}

//  나 왼쪽 오른쪽
void preorder( int here ) {

    if( visited[here] == false ) {
        visited[here] = true ;
        cout << here << " " ;

        if( adj[here].size() == 1 ) preorder( adj[here][0]) ;
        if( adj[here].size() == 2 ) {
            preorder( adj[here][0] ) ;
            preorder( adj[here][1] ) ;
        }
    }
}

//  왼쪽 나 오른쪽
void inorder( int here ) {

    if( visited[here] == false ) {

        if( adj[here].size() == 1 ) {
            inorder(adj[here][0] ) ;
            visited[here] = true ;
            cout << here << " " ;
        } else if( adj[here].size() == 2 ) {
            inorder(adj[here][0] ) ;
            visited[here] = true ;
            cout << here << " " ;
            inorder(adj[here][1] ) ;
        } else {
            visited[here] = true ;
            cout << here << " ";
        }
    }
}
int main() {

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    
    cout << "postorder : " ;
    postorder(root);
    memset(visited, 0, sizeof(visited));

    cout << "\n" << "preorder : " ;
    preorder( root ) ;
    memset(visited, 0, sizeof(visited));

    cout << "\n" << "inorder : " ;
    inorder( root ) ;

    return 0 ;

}