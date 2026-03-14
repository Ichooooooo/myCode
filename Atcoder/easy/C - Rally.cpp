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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    // cout << accumulate(a.begin(), a.end(), 0) << endl;
    int m = double(accumulate(a.begin(), a.end(), 0) + 0.5) / n;
    ll an1 = 0, an2 = 0;
    for (int i = 0; i < n; i ++) {
        an1 += pow(a[i] - m, 2);
    }
    // m ++;
    // for (int i = 0; i < n; i ++) {
    //     an2 += pow(a[i] - m, 2);
    // }
    cout << an1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}