
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 1) {
            cnt ++;
            if (i == 1 && i + 1 <= n) a[i] = a[i + 1];
            else if (i == n) a[i] = a[i - 1];
            else {
                a[i] = lcm(a[i - 1], a[i + 1]);
            }
        } else if (i == 1) continue;
        else if (gcd(a[i], a[i - 1]) == 1) {
            cnt ++;
            if (i + 1 <= n) a[i] = lcm(a[i - 1], a[i + 1]);
        }
    }

    cout << cnt << '\n';
 }

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}