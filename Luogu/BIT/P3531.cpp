
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT  {
    int n; 
    vector <int> bit;

    BIT (int x) : n (x) {
        bit.assign (n + 2, 0);
    } 

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x ;i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }
        return ans;
    }
};

void ovo() {
    int n; cin >> n;
    
    string a, b;
    cin >> a >> b;

    vector <vector <int> > p (26);
    // pos : 1-based, cnt : 0-based;

    for (int i = 1; i <= n; i ++) {
        int x = a[i - 1] - 'A';
        // cerr << "x : " << x << '\n';
        p[x].push_back (i);    

        // cerr << i << '\n';
    }

    // for (int i = 0; i < 26; i ++) {
    //     cerr << "i : " << i << '\n';
    //     for (auto x : p[i]) {
    //         cerr << x << ' ';
    //     }
    //     cerr << '\n';
    // }

    vector <int> ps (26);
    vector <int> pos (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        int x = b[i - 1] - 'A';
        pos[i] = p[x][ps[x]];
        ps[x]++;
    }

    BIT bit (n);

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += (i - 1 - bit.sum (pos[i]));
        bit.point_add (pos[i], 1);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}