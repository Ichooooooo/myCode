#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    vector <vector<int>> a(5, vector<int> (5));
    for (int i = 1; i <= 4; i ++) {
        for (int j = 1; j <= 4; j ++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= 4; i ++) {
        vector<int> vis(5);
        for (int j = 1; j <= 4; j ++) {
            vis[a[i][j]] = 1;
        }
        if (find(vis.begin() + 1, vis.end(), 0LL) != vis.end()) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i <= 4; i ++) {
        vector<int> vis(5);
        for (int j = 1; j <= 4; j ++) {
            vis[a[j][i]] = 1;
        }
        if (find(vis.begin() + 1, vis.end(), 0LL) != vis.end()) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int r = 0; r <= 2; r += 2) {
        vector<int> vis(5);
        for (int i = 1 + r; i <= 1 + r + 1; i ++) {
            for (int j = 1; j <= 2; j ++) {
                vis[a[j][i]] = 1;
            }
        }
        if (find(vis.begin() + 1, vis.end(), 0LL) != vis.end()) {
                cout << "NO" << endl;
                return;
            }
        vis.clear();
        for (int i = 1 + r; i <= 1 + r + 1; i ++) {
            for (int j = 2; j <= 4; j ++) {
                vis[a[j][i]] = 1;
            }
            
        }
        if (find(vis.begin() + 1, vis.end(), 0LL) != vis.end()) {
                cout << "NO" << endl;
                return;
        }
    }
    cout << "YES" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}