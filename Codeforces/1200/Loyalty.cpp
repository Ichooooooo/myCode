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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int & i : a){
        cin >> i;
    }
    sort(a.begin(), a.end());
    ll sum = 0, l = 0, r = n - 1, ans = 0;
    vector<int> b;
    while(l < r){
        if((sum + a[r]) / x > sum / x) {
            ans += a[r];
            sum += a[r];
            b.push_back(a[r]);
            r --;
        }else {
            sum += a[l];
            b.push_back(a[l]);
            l ++;
        }
    }
    if((sum + a[r]) / x > sum / x){
        ans += a[r];
    }
    b.push_back(a[r]);
    cout << ans << endl;
    for(int i = 0; i < b.size(); i ++){
        cout << b[i] << ' ';
    }
    cout << endl;
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
