
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N =2005;
int p[N];

void ovo() {
    int n, h;
    cin >> n >> h;
    
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector <int> hh (n);
    int mxxx = 0;
    for (int i = 0; i < n; i ++) {
        int l = a[i], r = a[i];
        // cerr << "i : " << '\n';

        for (int j = i; j >= 0; j --) {
            l = max (l, a[j]);
            hh[i] += h - l;
            // cerr << "l : " << l << '\n';
        }

        for (int j = i + 1; j < n; j ++) {
            r = max (r, a[j]);
            hh[i] += h - r;
            // cerr << "r : " << r << '\n';
        }

        // cerr << "i : " << hh[i] << '\n'; 

        mxxx = max (mxxx, hh[i]);
    }

    vector <vector <int> > mxx (n, vector <int> (n));
    int mx = 0, mpos = 0;
    for (int i = 0; i < n; i ++) {
        mx = 0;
        mx = max (mx, a[i]);
        mpos = i;
        // cerr << "i :" << i << '\n';
        for (int j = i + 1; j < n; j ++) {
            if (mx < a[j]) {
                // cerr << "mxx : " << j << ' ' << a[j] << '\n';

                mx = a[j];
                mpos = j;
            }

            mxx[i][j] = mpos;
            // cerr << "ij : " << i << ' ' << j << ' ' << mxx[i][j] << '\n';
        }
    }

    int ans = mxxx;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            ans = max(ans, hh[i] + hh[j] - hh[mxx[i][j]]);
            // cerr << "ij : " << hh[i] << ' ' << hh[j] << ' ' << mxx[i][j] << ' ' << hh[mxx[i][j]] << '\n';
            // cerr << "ij : " << i << ' ' << j << ' ' <<  hh[i] + hh[j] - hh[mxx[i][j]] << '\n';
            // cerr << "ans : " << ans << '\n';
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}