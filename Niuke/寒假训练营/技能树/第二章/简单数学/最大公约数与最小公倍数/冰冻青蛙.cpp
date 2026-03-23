#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    int of = 999999999;
    vector <int> a, b; a.reserve(n); b.reserve(n);
    for (int i = 1; i <= n; i ++) {
        if (gcd (i, of) != 1) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    if (b.size() > 2 * a.size()) {
        cout << "Baka!" << endl;
    } else {
        int k = 0, m = 0;
        for (int i = 1; i <= n; i ++) {
            if (i % 3 != 2 && k < b.size()) {
                cout << b[k] << ' '; k ++;
            } else {
                cout << a[m] << ' '; m ++;
            }
        }
    }

    cout << endl;
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