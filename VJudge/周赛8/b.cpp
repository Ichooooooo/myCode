
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n;
    cin >> n;
    
    int sm = 0;
    for (int i = 0; i < n; i ++) {
        int t; cin >> t;
        
        vector <int> tmp;
        while (t) {
            tmp.push_back (t & 1);
            t >>= 1;
        }

        // for (auto x : tmp) cerr << x; 

        int ok = 0, bit = 0, pos;
        for (int j = 0; j < (int)(tmp.size()); j ++) {
            if (tmp[j] != 0) {
                pos = j;
                break;
            }
        }

        // cerr << pos << '\n';

        bit = tmp.size() - pos - 1;
        // cerr << bit << '\n';

        for (int j = pos; j < (int) (tmp.size()); j ++) {
            sm += tmp[j] * (1LL << bit);
            bit--;
        }
    }

    cout << sm << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}