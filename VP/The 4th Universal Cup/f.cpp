
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, r;
    cin >> n >> r;
    
    vector <int> a (n + 1), c (n + 1), pre (n + 1);
    int fpos = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % r; 

        if (pre[i] == 0 && fpos == -1) {
            fpos = i;
        } 
    }

    for (int j = 1; j <= n; j ++) {
        cin >> c[j];
    }

    if (fpos == -1) {
        cout << 0 << '\n';
        return;
    }
    
    vector <int> expire (n + 1);
    expire[0] = fpos;

    unordered_map <int, int> last;
    set <arr2, greater <arr2> > st1;

    const int INF = 1e7;
    for (int i = n; i >= 1; i --) {
        auto pos = st1.find({last[pre[i]], pre[i]});
        if (pos == st1.end()) {
            last[pre[i]] = i;
            st1.insert ({i, pre[i]});
        } else {
            st1.erase (pos);          
            last[pre[i]] = i;
            st1.insert ({i, pre[i]});
        }

        if ((int)st1.size() < r) {
            expire[i] = INF;
        } else {
            expire[i] = (*st1.begin())[0];
        }
    }

    vector <int> dp (n + 1);
    multiset <arr2> st;

    st.insert ({0, expire[0]});
    
    for (int i = 1; i <= n; i ++) {
        st.insert ({dp[i - 1] + c[i], expire[i]});

        while (st.size() && (*st.begin())[1] <= i) {
            st.erase (st.begin());
        }

        dp[i] = (*st.begin())[0];
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}