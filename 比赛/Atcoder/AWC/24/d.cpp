
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n, w, k;
    cin >> n >> w >> k;

    vector <int> diff (n + 1), pre (n + 1);
    
    int l;
    for (int i = 0; i < k; i ++) {
        cin >> l;
        diff[l] += 1;
        if (l + w <= n) diff[l + w] -= 1;
    }

    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + diff[i];
        cout << pre[i] << " \n"[i == n];
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}