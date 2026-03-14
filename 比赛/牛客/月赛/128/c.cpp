#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 0 && b != 0) {
        while (n -- ) cout << 1;
        cout << endl;
    } else if (b == 0) {
        while (n --) cout << 0;
        cout << endl;
    } else {
        int n0 = 0, n1 = 0;
        for (int i = 1; i <= n; i ++) {
            if (abs ((n0 + 1) * a - n1 * b) < abs((n1 + 1) * b - (n0 * a))) {
                cout << 1;
                n0 ++;
            } else {
                cout << 0;
                n1 ++;
            }
        }
        cout << endl;
    }
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