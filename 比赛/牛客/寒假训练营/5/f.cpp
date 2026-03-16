
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, a, b;
    cin >> n >> a >> b;

    int all = n / 56, ans = 0, res = n % 56;
    int x = 8 * a, y = 28 * b, z = 7 * (a + b);
    
    if (all > 1) {
        all -= 1;
        res += 56;
    }

    int mx = max ({x, y, z});
    ans = all * mx;

    int rans=0;
    for (int i = 0; i * 7 <= res; i ++) {
        int tres = res - i * 7; // res
        int ab = min (tres, i); // i
        int tot = i * a + (ab + (tres - ab) / 2) * b;
        rans = max (rans, tot);
    }

    
    cout << ans + rans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}