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
    // int n;
    // cin >> n;
    // vector<int> a(n + 1);
    // if(n & 1){
    //     for(int i = 1; i <= n; i ++){
    //         if(i & 1){
    //             cout << i << ' ';
    //         }else {
    //             cout << n - i + 1 << ' ';
    //         }
    //     }
    // }else {
    //     for(int i = 1; i <= n; i ++){
    //         if(i & 1){
    //             cout << i << ' ';
    //         }else {
    //             cout << n - i + 2 << ' ';
    //         }
    //     }
    // }
    // cout << endl;
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    int cnt = 1;
    for(int i = 1;i<=n;i+=2){
        a[i] = cnt++;
    }
    for(int i = 2;i<=n;i+=2){
        a[i] = cnt++;
    }
    for(int i = 1;i<=n;i++){
        cout << a[i] << ' ';
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
