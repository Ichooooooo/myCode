
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int x;  cin >> x;

    int cnt = 0, ans = 1;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }
    if (cnt) ans *= 2;

    for (long long i = 3; i <= x / i; i += 2) {
            if (x % i == 0) {
                int c = 0;
                while (x % i == 0) {
                    x /= i;
                    c++;
                }
                ans *= i;
            }
        }
    if (x > 1) ans *= x; // 剩下的大质因子

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}