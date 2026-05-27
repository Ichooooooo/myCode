
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n);
    map <int, vector <int> > mp;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        int nm = 0, o1 = 0, o2 = 0;
        if (a[i] % 2 == 0) {
            nm++;
            o1 = 1;
        }
        if (a[i] % 3 == 0) {
            nm++;
            o2 = 1;
        }

        if (nm == 2) {
            mp[6].push_back (a[i]);
        } else if (nm == 1 && o1) {
            mp[2].push_back (a[i]);
        } else if (nm == 1 && o2) {
            mp[3].push_back (a[i]);
        } else if (nm == 0) {
            mp[0].push_back (a[i]);
        }
    }

    for (auto x : mp[2]) {
        cout << x << ' ';
    }
    
    // cout << "   ";
    for (auto x : mp[0]) {
        cout << x << ' ';
    }

    // cout << "   ";
    for (auto x : mp[3]) {
        cout <<x << ' ';
    }

    // cout << "   ";
    for (auto x : mp[6]) {
        cout << x << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}