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
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n);
    unordered_map<int, vector<int>> mp;
    for(int & i : a){
        cin >> i;
        mp[i % p].push_back(i);
    }
    int ans = LLONG_MAX;
    for(auto & v : mp){
        auto vi = v.se;
        if(vi.size() < k){
            continue;
        }
        sort(vi.begin(), vi.end());
        vector<int> pre(vi.size());
        for(int i = 0; i < vi.size(); i ++){
            if(i == 0){
                pre[i] = vi[i];
            }else {
                pre[i] = pre[i - 1] + vi[i];
            }
        }
        int t;
        for(int i = k - 1; i < vi.size(); i ++){
            if(i == k - 1){
                t = (k * vi[i] - pre[i]) / p;
            }else {
                t = (k * vi[i] - (pre[i] - pre[i - k])) / p;
            }
            ans = min(t, ans);
        }
    }
    if(ans == LLONG_MAX){
        cout << "wuwuwu" << endl;
    }else {
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
