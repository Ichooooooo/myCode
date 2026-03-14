#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, k;  cin >> n >> k;
    vector <int> a (2 * n + 2); deque <int> dq;
    for (int i = 1; i <= n; i ++)  {
        cin >> a[i];
    }
    a[n + 1] = k;
    for (int i = n + 2; i <= 2 * n + 2; i ++) a[i] = a[i - n - 1];

    // for (int & i : a) cout << i << ' ';
    // cout << endl;
    int ans = k + a[1];
    for (int i = 1; i <= n + 1; i ++) {
        ans = max (ans, a[i] + a[i + n]);
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}