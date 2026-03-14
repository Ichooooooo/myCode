#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    int cur = 1;
    vector <int> a (n + 1);
    for (int i = n; i >= 1; i -=2) {
        a[i] = cur;
        cur ++;
    }

    if (n & 1) {
        for (int i = 2; i <= n; i += 2) {
            a[i] = cur;
            cur ++;
        }
    } else {
        for (int i = 1; i <= n; i += 2) {
            a[i] = cur;
            cur ++;
        }
    }

    for (int i = 1; i <= n; i ++ )  cout << a[i] << ' ';
    cout << endl;
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