
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

int a[4][4] = {
    {0, 2, 5, 9},
    {1, 4, 8, 12},
    {3, 7, 11, 14},
    {6, 10, 13, 15}
};

int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

vector <int> op{1};

int win[1LL << 16];

void init () {
    for (int i = 1; i < 16; i ++) {
        op.push_back (1LL << i);
    }

    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            for (int k = 0; k < 4; k ++) {
                int x = i + dx[k];
                int y = j + dy[k];
                
                int cur = op[a[i][j]];
                if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
                cur |= op[a[x][y]];
                op.push_back (cur);

                x = x + dx[k];
                y = y + dy[k];                
                if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
                cur |= op[a[x][y]];
                op.push_back (cur);               
            }
        }
    }

    for (int i = (1LL << 16) - 1; i >= 0; i --) {
        if (win[i] == 1) continue;
        win[i] = 2;
        for (int j : op) {
            if ((i & j) == j) {
                win[i ^ j] = 1;
            }
        }
    }
}

void ovo() {
    int x;
    int now = 0;
    for (int i = 0; i < 16; i ++) {
        char c; 
        cin >> c;
        if (c == '*') now |= (1LL << i);
    }

    cout << (win[now] == 1 ? "Alice" : "Bob") << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    init();
    while (_--) ovo();
}