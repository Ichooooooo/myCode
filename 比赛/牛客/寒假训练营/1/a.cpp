#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

int qpow (int a, int b, int m)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow(x, mod - 2, mod);
}

void ovo(){   
    int c;  cin >> c;
    vector <int> p(8), yp(8), fp(8);
    for (int i = 1; i <= 7; i ++) {
        cin >> p[i]; 
        yp[i] = p[i] * inv (100) % mod;
        fp[i] = (100 - p[i]) * inv (100) % mod;
    }

    vector <int> ym(10), nm(10);
    ym[0] = (1<< 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6) | (1 << 7);
    ym[1] = (1 << 3) | (1 << 6);
    ym[2] = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7);
    ym[3] = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 6) | (1 << 7);
    ym[4] = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6);
    ym[5] = (1 << 1) | (1 << 2) | (1 << 4) | (1 << 6) | (1 << 7);
    ym[6] = (1 << 1) | (1 << 2) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    ym[7] = (1 << 1) | (1 << 3) | (1 << 6);
    ym[8] = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    ym[9] = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6) | (1 << 7);

    for (int i = 0; i < 10; i ++) {
        int t = 1;
        for (int bt = 1; bt <= 7; bt ++) {
            if (ym[i] & (1 << bt)) {
                t = t * yp[bt] % mod;
            } else {
                t = t * fp[bt] % mod;
            }
        }
        nm[i] = t;
    }

    auto cacu = [&](int x) -> int {
        int t = 1;
        for (int i = 1; i <= 4; i ++) {
            t = t * nm[x % 10] % mod;
            x /= 10;
        }
        return t;
    };

    int ans = 0;
    for (int A = 0; A <= c; A ++) {
        int B = c - A;
        ans = ans + cacu(A) * cacu(B) % mod;
        ans %= mod;
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