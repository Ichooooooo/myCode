
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <vector<int>> a (m, vector<int> (n));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[j][i];
        }
    }

    int ans = 0;
    for (auto & b : a) {
        ranges :: sort (b);
        int an = 0;
        for (int i = 0; i < n; i ++) {
            // cout << b[i] << ' ';
            an += (i - (n - 1 - i)) * b[i];
            // cout << i - (n - 1 - i - 1) << ' ';
        }
        // cout << '\n';
        ans += an;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}