
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n, q;
    cin >> n >> q;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int x, y;
    while (q-- ) {
        cin >> x >> y;
        if (a[x] > a[y]) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}