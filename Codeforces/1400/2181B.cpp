// 时间复杂度判断之后发现可以暴力
// 时间复杂度可以通过分类讨论, 发现最坏情况也还好

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    priority_queue<int> p1, p2;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        p1.push(x);
    }

    for (int i = 1; i <= m; i ++) {
        int x; cin >> x;
        p2.push(x);
    }

    int cnt = 1;
    while (p1.size() && p2.size()) {
        if (cnt & 1) {
            auto x1 = p1.top();
            auto x2 = p2.top(); p2.pop();
            if (x2 > x1) {
                p2.push(x2 - x1);
            }
        } else {
            auto x1 = p1.top(); p1.pop();
            auto x2 = p2.top();
            if (x1 > x2) {
                p1.push(x1 - x2);
            }            
        }
        cnt++;
    }
    
    if (p1.empty()) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}