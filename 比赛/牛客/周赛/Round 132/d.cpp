
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;  cin >> n;
    vector <int> a (n);

    int cnt = 0;
    for (int & i : a)  {
        cin >> i;
        if (i & 1) cnt ++;
    }

    int ans = 0, num = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] & 1) {
            num += (cnt - 1);
        }

        ans += (n - 1) * (a[i] / 2);
    }

    ans += num / 2;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}