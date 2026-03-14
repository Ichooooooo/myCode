
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int x;  cin >> x;

    int ans = 0;
    auto check = [](int y, int i) -> bool {
        string s = to_string(y);
        int sum = 0;
        for (char & ss : s)  sum += (ss - '0');
        if (sum == i) return true;
        else return false;
    };
    for (int i = 0; i <= 81; i ++) {
        int y = x + i;
        if (check (y, i)) ans ++;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}