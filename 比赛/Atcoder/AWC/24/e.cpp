#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> dp(W + 1, INF); // dp表示长度为W的时候的最小的数量cnt
    dp[0] = 0; // 1. 我们dp求的是最小值 2. 长度W不一定能够到达 -> 初始化dp[0] = 0, 其他为INF

    for (int i = 0; i < N; ++i) {
        int w, cnt;
        cin >> w >> cnt;

        for (int k = 1; cnt > 0; k <<= 1) {
            int take = min(k, cnt);
            cnt -= take;

            // 二进制优化
            // 因为每个被拆分出来的组只能选择一次, 相当于01背包
            int weight = take * w; // 这一组的总重量
            int cost = take;       // 这一组的总代价

            // 01背包, 最小化版(逻辑都一样)
            for (int j = W; j >= weight; --j) {
                if (dp[j - weight] != INF) {
                    dp[j] = min(dp[j], dp[j - weight] + cost);
                }
            }
        }
    }

    cout << (dp[W] == INF ? -1 : dp[W]) << '\n';
    return 0;
}