
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << n * m << '\n';
    } else if (n == 2 || m == 2) {
        if (n > m) swap (n, m);
        cout << (m / 4) * 4 + min((m % 4) * 2, 4LL) << '\n'; 
    } else {
        int sum = n * m;
        if (sum & 1) {
            cout << sum / 2 + 1 << '\n';
        } else {
            cout << sum / 2 << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}