#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    vector <int> a (n);

    map <int, int> mp;
    for (int i = 0; i < n; i ++)  {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (mp[a[i]] == i) {
            int gx = (i + 1) * (1 + n  - 1 - i + 1) * (n - 1 - i + 1) / 2;
            ans += gx; 
            // cout << gx << ' ';
        } else {
            int p = mp[a[i]], gx;
            gx = (i - p) * (1 + n - 1 - i + 1) * (n  - 1 - i + 1) / 2;
            ans += gx;
            mp[a[i]] = i;
            // cout << gx << ' ';
        }
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