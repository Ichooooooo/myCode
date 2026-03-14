
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <int> a (n), b (m);
    for (int & i : a) cin >> i;
    for (int & j : b) cin >> j;

    int MX = n + m + 10;
    ranges :: sort (a);
    vector <int> tags (MX);
    
    for (int i = 0; i < n; i ++) {
        if (i != 0 && a[i] == a[i - 1]) continue;
        for (int j = a[i]; j < MX; j += a[i]) {
            tags[j] = 1;
        }
    }

    int mx = 1;
    for (int i = 0; i < n; i ++) {
        mx = lcm(mx, a[i]);
        if (mx > MX) {
            mx = MX;
            break;
        }
    }

    int all = 0, non = 0, par = 0;
    for (int i = 0; i < m; i ++) {
        if (b[i] % mx == 0) {
            all ++;
        } else if (tags[b[i]]) {
            par ++;
        } else {
            non ++;
        }
    }

    int w = (par & 1);
    if (w + all > non) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}