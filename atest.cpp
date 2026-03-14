#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> dp(W + 1, INF); // INF?
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        int L, C;
        cin >> L >> C;

        // 二进制拆分：把 C 拆成 1,2,4,...,rest
        for (int k = 1; C > 0; k <<= 1) {
            int take = min(k, C);
            C -= take;

            int totalLen = take * L;   // 这一组提供的总长度
            int totalCnt = take;       // 这一组用了多少根绳子

            // 0/1 背包：每组最多选一次
            for (int j = W; j >= totalLen; --j) {
                if (dp[j - totalLen] != INF) {
                    dp[j] = min(dp[j], dp[j - totalLen] + totalCnt);
                }
            }
        }
    }

    cout << (dp[W] == INF ? -1 : dp[W]) << '\n';
    return 0;
}