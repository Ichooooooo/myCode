
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int h, w, k;
    cin >> h >> w >> k;
    char c1, c2;
    cin >> c1 >> c2;

    char t;
    vector <vector <char>> a (h * k + 1, vector<char> (w * k + 1));
    for (int i = 1; i <= h; i ++) {
        for (int j = 1; j <= w; j ++) {
            cin >> t;
            if (t == '#') {
                for (int v = k * (i - 1) + 1; v <= k * i; v ++) {
                    for (int u = k * (j - 1) + 1; u <= k * j; u ++) {
                        a[v][u] = c1;
                    }
                } 
            } else {
                for (int v = k * (i - 1) + 1; v <= k * i; v ++) {
                    for (int u = k * (j - 1) + 1; u <= k * j; u ++) {
                        a[v][u] = c2;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= h * k; i ++) {
        for (int j = 1; j <= w * k ; j ++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}