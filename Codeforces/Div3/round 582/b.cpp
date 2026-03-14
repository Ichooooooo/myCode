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
const int MAX = 1e6 + 10;

void solve(){   
    int n, mn = MAX, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int & i : a) cin >> i;
    for (int i = n - 1; i >= 0; i --) {
        if (a[i] > mn) {
            cnt ++;
            // cout << a[i] << ' ' << mn << endl;
        }else {
            mn = a[i];
        }
    }
    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}