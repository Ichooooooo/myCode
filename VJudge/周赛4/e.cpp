
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; 
    cin >> s;

    map <arr2, int> mp;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'D') c1++;
        else c2++;

        int c = gcd (c1, c2);
        int tc1 = c1 / c;
        int tc2 = c2 / c;

        mp[{tc1, tc2}]++;

        cout << mp[{tc1, tc2}] << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}