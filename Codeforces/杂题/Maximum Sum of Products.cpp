// 反转l, r的方式和l和r都有关, 不应该直接一次性预处理
// how to预处理反转l, r后的结果

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 5005;

int c[N][N], d[N][N];

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1), b (n + 1), pre (n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        pre[i] = pre[i - 1] + a[i] * b[i];
    }

    // vector <vector <int> > c (n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i ++) {
        int l = i, r = i, len = 1, sum = 0;
        
        while (l >= 1 && r <= n) {
            if (l != r) 
            sum = sum + a[r] * b[l] + a[l] * b[r];
            else 
            sum = sum + a[r] * b[l];

            c[i][len] = sum;
            l--;
            r++;
            len += 2;
        }
    }

    // vector <vector <int> > d (n + 1, vector <int> (n + 1));

    for (int i = 1; i <= n - 1; i ++) {
        int l = i, r = i + 1, len = 2, sum = 0;

        while (l >= 1 && r <= n) {
            sum = sum + a[r] * b[l] + a[l] * b[r];

            d[i][len] = sum;
            l--;
            r++;
            len += 2;
        }
    }

    int ans = 0;
    for (int l = 1; l <= n; l ++) {
        for (int r = l; r <= n; r ++) {
            int an = 0, len = r - l + 1;
            if ((r - l + 1) & 1) {
                int mid = l + (r - l) / 2;
                an = pre[n] - pre[r] + pre[l - 1] + c[mid][len];
            } else {
                int m1 = l + (r - l) / 2;
                an = pre[n] - pre[r] + pre[l - 1] + d[m1][len];
            }

            ans = max (ans, an);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}