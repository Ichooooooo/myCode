#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

struct Node {
    int x, y;
    int frc;

    bool operator<(const Node& it) const {
        return tie (frc, x, y) > tie (it.frc, it.x, it.y);
    }
};

void ovo(){   
    int n, m, q; cin >> n >> m >> q;
    vector <vector <int>> a (n, vector <int> (m)), b (n, vector <int> (m));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }

    set <Node> st;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int sum  = 0;
            // cout << i << ' ' << j << ' ';
            for (int k = -2; k <= 2; k ++) {
                for (int h = -2; h <= 2; h ++) {
                    if (abs(k) + abs (h) > 2) continue;
                    int xx = i + k, yy = j + h;
                    
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                        // cout << xx << ' ' << yy << ' ' << sum << '\n';
                        sum += a[xx][yy];
                    }
                }
            }
            
            b[i][j] = sum;
            st.insert({i, j, sum});
        }
    }

    // for (const auto v : st) {
    //     cout << v.frc << ' ' << v.x << ' ' << v.y << '\n';
    // }

    int x, y, z;
    while (q --) {
        cin >> x >> y >> z;
        x--; y--;
        a[x][y] += z;
        for (int k = -2; k <= 2; k ++) {
            for (int h = -2; h <= 2; h ++) {
                if (abs(k) + abs (h) > 2) continue;
                int xx = x + k, yy = y + h;
                
                if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    // cout << xx << ' ' << yy << ' ' << sum << '\n';
                    st.erase({xx, yy, b[xx][yy]});
                    b[xx][yy] += z;
                    st.insert({xx, yy, b[xx][yy]});
                }
            }
        }

        auto d = *st.begin();
        cout << d.x + 1 << ' ' << d.y + 1 << '\n';
    }
}

    

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}