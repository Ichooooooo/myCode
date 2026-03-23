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

    auto ack = [&](int m, int n, auto self) -> int {
        if (m == 0) return n + 1;
        else if (m > 0 && n == 0) return self (m - 1, 1, self);
        else if (m > 0 && n > 0) return self (m, self (m, n + 1, self), self);
    };

    cout << ack (n, m, ack) << endl;
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