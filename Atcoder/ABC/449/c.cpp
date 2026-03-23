
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    s = ' ' + s;

    vector <vector <int>> a (26, vector<int> (n + 1)), pre (26, vector <int> (n + 1));

    for (int i = 1; i <= n; i++) {
        a[s[i] - 'a'][i] ++;
    }

    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j <= n; j ++) {
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n - 1; i ++) {
        int x = s[i] - 'a';
        if (i + l > n) break;
        int ll = i + l;
        int rr = min (n, i + r);
        ans += pre[x][rr] - pre[x][ll - 1];
    }

    cout << ans << '\n';
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}