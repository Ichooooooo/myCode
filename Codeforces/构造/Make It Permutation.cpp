// 1h + answer
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;  cin >> n;

    cout << 2 * n << '\n';
    for (int i = 1; i <= n; i ++) {
        cout << i << ' ' << 1 << ' ' << i << '\n';
        cout << i << ' ' << min (n, i + 1) << ' ' << n << '\n';
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}