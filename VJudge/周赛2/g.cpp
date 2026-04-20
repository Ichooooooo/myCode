#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    vector <int> cnt (26);

    int n = 0;
    for (int i = 0; i < 16; i ++) {
        cin >> cnt[i];
        n += cnt[i];
    }

    vector <vector <arr2> > dp (n + 1, vector <arr2> (26));

    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j <= n; j ++) {
            
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}