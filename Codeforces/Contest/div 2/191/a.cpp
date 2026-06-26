
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int t1 = (n + x + y - 1) / (x + y);
    
    int s1 = x, sum = 0, t2 = 0;
    while (sum < n) {
        sum += s1;
        t2++;
        if (t2 == z) {
            s1 += 10 * y;
        }
    }

    cout << min (t1, t2) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}