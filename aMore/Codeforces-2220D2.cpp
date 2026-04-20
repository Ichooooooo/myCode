#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v;
    int l = 1, r = 2 * n + 1;

    auto query = [&] (vector <int> &v) -> int {
        cout << "? " << v.size() << ' ';
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << endl;
        int t;
        cin >> t;
        return t;
    };

    for (int i = 0; i < 3; i++) {
        int pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            vector <int> a = v;
            for (int j = 1; j <= mid; j++) {
                a.push_back(j);
            }
            int res = query(a);
            if (((mid + i) & 1) != (res & 1)) {
                pos = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        v.push_back(pos);
        l = 1;
        r = pos - 1;
    }

    cout << "! ";
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << endl;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}