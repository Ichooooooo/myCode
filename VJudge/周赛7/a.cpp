
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1e4;

void ovo() {
    int n, sum;
    cin >> n >> sum;

    int sm = 0;
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sm += a[i];
    }

    if (sm == sum){
        cout << 0 << '\n';
        return;
    }

    if (sm > sum) {
        sort (a.rbegin(), a.rend());
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (sm - a[i] - N <= sum) {
                cnt++;
                cout << cnt << '\n';
                return;
            }
            sm = sm - a[i] - N;
            cnt++;
        }
    } else {
        sort (a.begin(), a.end());
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (sm - a[i] + N >= sum) {
                cnt++;
                cout << cnt << '\n';
                return;
            }
            sm = sm - a[i] + N;
            cnt++;
        }        
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}