
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int h, w, q;
    cin >> h >> w >> q;

    int opt, x;
    while (q --) {
        cin >> opt >> x;
        if (opt == 1) {
            cout << x * w << '\n';
            h -= x;
        } else {
            cout << x * h << '\n';
            w -= x;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}