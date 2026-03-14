
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n + 1), pos;

    int ok1 = 0, ok2 = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i <= n/ 2 && a[i] == 0) {
            ok1 = 1;
        } else if (i > n / 2 && a[i] == 0) {
            ok2 = 1;
        }
    }

    if (ok1 == 0 && ok2 == 0) {
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
    } else if (ok1 == 1 && ok2 == 0) {
        cout << 2 << '\n';
        cout << 1 << ' ' << n / 2 << '\n';
        cout << 1 << ' ' << n - n / 2 + 1 << '\n';
    } else if (ok1 == 0 && ok2 == 1) {
        cout << 2 << '\n';
        cout << n / 2 + 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n /2 + 1 << '\n';
    } else {
        cout << 3 << '\n';
        cout << 1 << ' ' << n / 2 << '\n';
        cout << 2 << ' ' << (n - n / 2 + 1) << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}