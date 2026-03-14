#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1, 0);
    vector<int> a(n);
    for(int & i : a){
        cin >> i;
        cnt[i] ++;
    }
    for(int i = 1; i <= n; i ++){
        if(cnt[i] % k) {
            cout << 0 <<endl;
            return;
        }else {
            cnt[i] /= k;
        }
    }
    ll ans = 0;
    vector<int> cn(n + 1);
    // for(int l = 0, r = 0; r < n && r >= l; r ++) {
    //     cn[a[r]] ++;
    //     while(cn[a[r]] > cnt[a[r]]) {
    //         cn[a[l ++]] --;
    //     }
    //     ans += r - l + 1;
    // }
    for(int l = n - 1, r = n - 1 ; l >= 0 && r >= l ; l --) {
        cn[a[l]] ++;
        while(cn[a[l]] > cnt[a[l]]) {
            cn[a[r --]] --;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
