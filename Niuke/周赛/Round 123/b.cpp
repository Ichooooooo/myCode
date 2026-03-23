#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int a[13], b[13];
    for(int & i : a) cin >> i;
    for(int & i : b) cin >> i;
    int ans = 0;
    for(int i = 0; i < 13; i ++) {
        ans += max(0, a[i] + b[i] - 4);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
