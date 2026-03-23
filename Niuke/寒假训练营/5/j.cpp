
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    vector <array<int, 3>> a (3); vector <int> vis (10);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> a[i][j]; vis[a[i][j]]++;
        }
    }
    
    for (int i = 1; i <= 9; i ++) {
        if (vis[i] != 1) {
            cout << "No" << '\n';
            return;
        }
    }

    vector <int> s(3), l(3);
    int c = 0, d = 0;
    
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            s[i] += a[i][j];
            l[j] += a[i][j];
            if (i == j) c += a[i][j];
            if (i + j == 2) d += a[i][j];
        }
    }
    
    if (s[0] == s[1] && s[1] == s[2] && s[0] == l[0] && l[1] == l[0] && l[1] == l[2] && l[2] == c && c == d) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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