#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

// int qpow (int a, int b, int n)//a的b次方
// {
//     int res = 1;
//     while (b) {
//         if (b & 1) {
//             if (res >= n / a) return 2 * n;
//             res = res * a;
//         }
//         if (a >= (1e18 / a)) return 2 * n;
//         a *= a;
//         b >>= 1;
//     }
//     // cout << a << ' ' << res << endl;
//     return res;
// }

inline int qpow(int a, int b, int n) {
    if (a <= 1) return a;
    int ans = 1;
    while (b) {
        if (b & 1) {
            //三级防御：底数a溢出防御以及ans溢出防御
            if (a<=0||ans > 2*n / a) return 2*n;//只有进行本次运算才溢出判断
            ans = (ans * a);
        }
        a *= a;//这里溢出判断会丢解
        b >>= 1;
    }
    return ans;
}

void ovo(){   
    int n, k;  cin >> n >> k;
    if (k >= 60) {
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << n << endl;
        return;
    }
    int l = 1, r = pow(1e18, 1.0 / k);
    while (l <= r) {
        int mid = l + (r - l) / 2;
        auto check = [&] (int mid) -> bool {
            int t =  qpow(mid, k, n);
            if (t >= n) return true;
            else return false;
        };
        if (check (mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        // cout << l << ' ' << r << endl;
        // cout << l << ' ';
    }
    int ans = 0;
    if (l == 1) ans = 1;
    else {
        int a = qpow(l, k, n) - n, b = n - qpow (l - 1, k, n);
        if (a > b) ans = l - 1;
        else ans = l;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}