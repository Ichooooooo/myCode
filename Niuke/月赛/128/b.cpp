#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++)  cin >> a[i];


    auto check = [](int x) -> bool {
        vector <PII> fac;
        if (x <= 1) return true;

        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }
        if (cnt) fac.push_back({2, cnt});

        for (long long i = 3; i <= x / i; i += 2) {
                if (x % i == 0) {
                    int c = 0;
                    while (x % i == 0) {
                        x /= i;
                        c++;
                    }
                    fac.push_back({i, c});
                }
            }
        if (x > 1) fac.push_back({x, 1}); // 剩下的大质因子

        if (fac.size() <= 1) return true;
        else return false;
    };

    for (int i = 1; i <= n; i ++) {
        if (check (a[i])) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}