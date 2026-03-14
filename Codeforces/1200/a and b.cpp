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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a, b;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == 'a'){
            a.push_back(i - c1);
            c1 ++;
        }else {
            b.push_back(i - c2);
            c2 ++;
        }
    }
    if(a.size() == 0 || b.size() == 0){
        cout << 0 << endl;
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll a1 = 0, a2 = 0, t1 = a[a.size() / 2], t2 = b[b.size() / 2];
    for(int i = 0; i < a.size(); i ++){
        a1 += abs(a[i] - t1);
    }
    for(int i = 0; i < b.size(); i ++){
        a2 += abs(b[i] - t2);
    }
    cout << min(a1, a2) << endl;
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
