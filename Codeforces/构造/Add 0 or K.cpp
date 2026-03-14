// 2h(with answer)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k; cin >> n >> k;

    vector <int> a (n);
    for (int & i : a) cin >> i;

    for (int i = 0; i < n; i++) {
        a[i] = a[i] + (a[i] % (k + 1)) * k;
    }

    for (int & i : a) cout << i << ' '; cout << '\n';
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