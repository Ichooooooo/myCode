
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s; cin >> s;
    
    int n = s.size();

    int l = 0, r = n - 1;
    while (l <= r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            if (s[l] == 'm') {
                if (s[r] == 'n' && s[r - 1] == 'n') {
                    l ++;
                    r -= 2;
                } else {
                    cout << "NO" << '\n';
                    return;
                }
            } else {
                if (s[l] == 'n' && s[l + 1] == 'n') {
                    l += 2;
                    r --;
                } else {
                    cout << "NO" << '\n';
                    return;
                }                
            }
        }
    }

    cout << "YES" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}