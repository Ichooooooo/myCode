
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 505, O = 4, C = 2;
const int INF = 1e5;
int dp[N][O][C] = {INF};

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    dp[0][0][0] = (s[0] == '0');
    dp[0][0][1] = (s[0] == '1');
    // 位置, 次数, 选择

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 4; j ++) {
            for (int z = 0; z < 2; z ++) {
                dp[i][j][z] = INF;
            }
        }
    }

    dp[0][0][0] = (s[0] == '1');
    dp[0][0][1] = (s[0] == '0');

    for (int i = 1; i < n; i ++) {
        int x = s[i] - '0';
        
        // 不修改
        dp[i][0][x] = min (dp[i][0][x], dp[i - 1][0][x]);
        dp[i][1][x] = min (dp[i][1][x], dp[i - 1][1][x]);
        dp[i][2][x] = min (dp[i][2][x], dp[i - 1][2][x]);  
        dp[i][3][x] = min (dp[i][3][x], dp[i - 1][3][x]);  
        
        dp[i][1][x] = min (dp[i][1][x], dp[i - 1][0][(1 ^ x)]);
        dp[i][2][x] = min (dp[i][2][x], dp[i - 1][1][(1 ^ x)]);  
        dp[i][3][x] = min (dp[i][3][x], dp[i - 1][2][(1 ^ x)]); 
        
        // 修改
        dp[i][0][(1 ^ x)] = min (dp[i][0][(1 ^ x)], dp[i - 1][0][(1 ^ x)] + 1);
        dp[i][1][(1 ^ x)] = min (dp[i][1][(1 ^ x)], dp[i - 1][1][(1 ^ x)] + 1);
        dp[i][2][(1 ^ x)] = min (dp[i][2][(1 ^ x)], dp[i - 1][2][(1 ^ x)] + 1); 
        dp[i][3][(1 ^ x)] = min (dp[i][3][(1 ^ x)], dp[i - 1][3][(1 ^ x)] + 1); 
        
        dp[i][1][(1 ^ x)] = min (dp[i][1][(1 ^ x)], dp[i - 1][0][x] + 1);
        dp[i][2][(1 ^ x)] = min (dp[i][2][(1 ^ x)], dp[i - 1][1][x] + 1); 
        dp[i][3][(1 ^ x)] = min (dp[i][3][(1 ^ x)], dp[i - 1][2][x] + 1); 

        // cerr << "i : " << i << ' ' << x << '\n';
        // cerr << dp[i][0][x] << ' ' << dp[i][1][x] << ' ' << dp[i][2][x] << ' ' << dp[i][3][x] << '\n';

        // x = (1 ^ x);

        // cerr << "i : " << i << ' ' << x << '\n';
        // cerr << dp[i][0][x] << ' ' << dp[i][1][x] << ' ' << dp[i][2][x] << ' ' << dp[i][3][x] << '\n';
    }

    cout << min ({dp[n - 1][3][0], dp[n - 1][3][1]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}