#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, k;  cin >> n >> k;

    auto check = [](int & x) -> int {
        string xx = to_string(x);
        int sum = 0;
        for (char & j : xx) sum += (j - '0');
        return sum;
    };

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (check(i) == k) {
            ans ++;
        }
    }

    cout << ans << '\n';
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