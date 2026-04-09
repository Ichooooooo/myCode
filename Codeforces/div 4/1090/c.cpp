#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int n; cin >> n;
    vector <int> a (3 * n + 1);
    
    int now = 1, back = 3 * n;
    for (int i = 1; i <= n; i ++) {
        a[now] = i;
        a[now + 1] = back - 1;
        a[now + 2] = back;
        now += 3;
        back -= 2;
    }

    for (int i = 1; i <= 3 * n; i ++) {
        cout << a[i] << " \n"[i == 3 * n];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}