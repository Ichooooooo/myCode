#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector <int> vs(26), vt(26);
    for (char & i : s) vs[i - 'a'] = 1;
    for (char & j : t) vt[j - 'a'] = 1;

    int q; cin >> q; string p;
    while (q --) {
        cin >> p;
        int ok1 = 1, ok2 = 1;
        for (char & i : p) {
            if (vs[i - 'a'] != 1) {
                ok1 = 0;
                break;
            }
        }
        for (char & i : p) {
            if (vt[i - 'a'] != 1) {
                ok2 = 0;
                break;
            }
        }
        if (ok1 && !ok2) {
            cout << "Takahashi" << endl;
        } else if (!ok1 && ok2) {
            cout << "Aoki" << endl;
        } else {
            cout << "Unknown" << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}