
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n; cin >> n;
    vector <int> a (n), cont (n);

    for (int & i : a) cin >> i;
    
    int ll = a[0], rr = a[0];
    cont[0] = 1;
    for (int i = 1; i < n; i ++) {
        if (a[i] > ll && a[i] <= rr + 1) {
            if (a[i] == rr + 1) {
                rr++;
            }
            cont[i] = 0;
        } else {
            ll = rr = a[i];
            cont[i] = 1;
        }

        cerr << cont[i] << '\n';
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (cont[i] == 0) continue;
        ans += (i + 1) * (n - 1 - i + 1);
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}