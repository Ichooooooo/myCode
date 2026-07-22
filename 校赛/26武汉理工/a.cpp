
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int a, b, n, q;
    cin >> a >> b >> n >> q;

    vector <int> A (n);
    vector <vector <int> > B (a + 1);
    vector <int> pre (n);

    for (int i = 0; i < n; i ++) {
        cin >> A[i];
        B[A[i]].push_back(i);
        
        int sz = B[A[i]].size();
        if (sz >= b) {
            pre[i] = B[A[i]][sz - 1 + b  + 1];
        }
    }

    vector <arr3> C (q);
    for (int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        auto & [x, y, z] = C[i];
        
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
} 