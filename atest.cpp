#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N + 1);
    vector<int> vals;
    vals.reserve(N);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    // 1) 离散化
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();

    vector<int> id(N + 1);
    for (int i = 1; i <= N; i++) {
        id[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1; // 1-based
    }

    // 2) 值域分块
    int B = (int)sqrt(m) + 1;                  // 块长
    int numBlock = (m + B - 1) / B;            // 块数

    vector<int> cnt(m + 1, 0);                 // cnt[x]: 离散值 x 的出现次数
    vector<int> sum(numBlock + 1, 0);          // sum[b]: 第 b 块的总出现次数
    vector<int> bel(m + 1, 0), L(numBlock + 1), R(numBlock + 1);

    for (int b = 1; b <= numBlock; b++) {
        L[b] = (b - 1) * B + 1;
        R[b] = min(m, b * B);   
        for (int i = L[b]; i <= R[b]; i++) bel[i] = b;
    }

    auto add = [&](int x) {
        cnt[x]++;
        sum[bel[x]]++;
    };

    auto kth = [&](int k) {
        // 先按块找第 k 小所在块
        int b = 1;
        while (b <= numBlock && k > sum[b]) {
            k -= sum[b];
            b++;
        }
        // 再在块内找具体位置
        for (int x = L[b]; x <= R[b]; x++) {
            if (k > cnt[x]) k -= cnt[x];
            else return x; // 返回离散下标
        }
        return -1; // 理论不会到这里
    };

    for (int i = 1; i <= N; i++) {
        add(id[i]);
        if (i & 1) {
            int rank = (i + 1) / 2;     // 当前奇数前缀的中位数 = 第 rank 小
            int pos = kth(rank);        // 离散下标
            cout << vals[pos - 1] << '\n';
        }
    }

    return 0;
}