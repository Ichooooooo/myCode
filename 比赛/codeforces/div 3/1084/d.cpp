
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> a (n + 1);

    int mnp = 0, mnz = n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i > x && i <= y) {
            if (mnz > a[i]) {
                mnz = a[i];
                mnp = i;
            }
        }
    }
    vector <int> l, mid, r;
    l.reserve(n); r.reserve(n); mid.reserve(n);
    
    int tar = mnz;
    int x1 = 1;
    while (a[x1] < tar && x1 <= x) {
        l.push_back(a[x1]);
        x1 ++;
    }

    // for (int & i : l) cout << i << ' ';

    int okl = 0;
    if (x1 > x) {
        int x2 = y + 1;
        while (x2 <= n && a[x2] < tar) {
            l.push_back(a[x2]);
            x2 ++;
        }

        // for (int & i : l) cout << i << ' ';
        while (x2 <= n) {
            r.push_back(a[x2]);
            x2 ++;
        }
        
        // for (int & i : r) cout << i << ' ';

        for (int i = 0; i < l.size(); i ++) cout << l[i] << ' ';
        int ch = mnp - (x + 1), tt = y - (x + 1) + 1, bs = x + 1;
        // cout << ch << ' ' << tt << '\n';
        for (int i = x + 1; i <= y; i ++) {
            int pos = bs + (i - bs + ch) % tt;
            cout << a[pos] << ' ';
        } 
        for (int i = 0; i < r.size(); i ++) {
            cout << r[i] << ' ';
        }
    } else if (x1 <= x) {
        while (x1 <= x) {
            r.push_back(a[x1]);
            x1 ++;
        }
        
        for (int i = 0; i < l.size(); i ++) {
            cout << l[i] << ' ';
        } 
        int ch = mnp - (x + 1), tt = y - (x + 1) + 1, bs = x + 1;
        // cout << ch << ' ' << tt << '\n';
        for (int i = x + 1; i <= y; i ++) {
            int pos = bs + (i - bs + ch) % tt;
            cout << a[pos] << ' ';
        } 
        for (int i = 0; i < r.size(); i ++) {
            cout << r[i] << ' ';
        }
        for (int i = y + 1; i <= n ; i ++) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}