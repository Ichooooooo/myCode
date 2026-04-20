
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 45;
int ans[N][N][N][N];

void ovo() {
    int n, m;
    cin >> n >> m;

    int a = 0, b = 0, c = 0, d = 0;
    vector <int> e (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> e[i];
    }

    for (int i = 0; i < m; i ++) {
        int x; cin >> x;
        if (x == 1) {
            a++;
        } else if (x == 2) {
            b++;
        } else if (x == 3) {
            c++;
        } else {
            d++;
        }
    }

    ans[0][0][0][0] = e[1];
    
    for (int i = 0; i <= a; i ++) {
        for (int j = 0; j <= b; j ++) {
            for (int k = 0; k <= c; k ++) {
                for (int z = 0; z <= d; z ++) {
                    int s = i * 1 + j * 2 + k * 3 + z * 4;

                    if (s == 0) continue;
                    if (i >= 1) ans[i][j][k][z] = max (ans[i][j][k][z], ans[i - 1][j][k][z] + e[s + 1]);
                    if (j >= 1) ans[i][j][k][z] = max (ans[i][j][k][z], ans[i][j - 1][k][z] + e[s + 1]);
                    if (k >= 1) ans[i][j][k][z] = max (ans[i][j][k][z], ans[i][j][k - 1][z] + e[s + 1]);
                    if (z >= 1) ans[i][j][k][z] = max (ans[i][j][k][z], ans[i][j][k][z - 1] + e[s + 1]);
                }
            }
        }
    }

    cout << ans[a][b][c][d] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}