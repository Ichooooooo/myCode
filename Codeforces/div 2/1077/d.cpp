#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

static inline int64 absl(int64 x) { return x < 0 ? -x : x; }

// 在所有满足 (p & ban) == 0 的 p 中，找一个离 tar 最近的（按你原先的 lo/hi 两端夹逼）
static inline int64 nearest_no_and(int64 tar, int64 ban) {
    const int MAXB = 30;

    // lo: <= tar 的最大可行
    int64 lo = 0;
    for (int i = MAXB; i >= 0; --i) {
        if (((ban >> i) & 1LL) == 0) {
            int64 cand = lo + (1LL << i);
            if (cand <= tar) lo = cand;
        }
    }

    // hi: >= tar 的最小可行
    int64 hi = 0;
    for (int i = 0; i <= MAXB; ++i) {
        if (((ban >> i) & 1LL) == 0) hi += (1LL << i);
    }
    for (int i = MAXB; i >= 0; --i) {
        if (((ban >> i) & 1LL) == 0) {
            int64 cand = hi - (1LL << i);
            if (cand >= tar) hi = cand;
        }
    }

    // 选更近的（平局随便，这里选 hi/lo 都行）
    if (tar - lo < hi - tar) return lo;
    return hi;
}

static void solve() {
    int64 x, y;
    cin >> x >> y;

    int64 t1 = nearest_no_and(x, y); // 改 x
    int64 t2 = nearest_no_and(y, x); // 改 y

    if (absl(t1 - x) < absl(t2 - y)) {
        cout << t1 << ' ' << y << '\n';
    } else {
        cout << x << ' ' << t2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
