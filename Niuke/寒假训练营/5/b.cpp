
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m; 
    cin >> n >> m;
    vector <vector <char>> a (n, vector <char> (m));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (i % 2 == 0 && j % 2 == 0) {
                cout << '/';
            } else if (i % 2 == 0 && j % 2 == 1) {
                cout << '\\';
            } else if (i % 2 == 1 && j % 2 == 0) {
                cout << '\\';
            } else {
                cout << '/';
            }
        }

        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}