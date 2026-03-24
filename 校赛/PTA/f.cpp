#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    int m, q, t, sum;
    vector <int> sums;

    while (n --) {
        cin >> m;
        vector<int> a(m);
        for(int & i : a) cin >> i;
        
        cin >> t;
        ranges :: sort(a);
        // for(int & i : a) cout << i << ' ';
        sum = accumulate(a.begin(), a.begin() + t, 0LL);
        // cout << sum << ' ';
        sums.push_back(sum);
    }
    // cout << endl;
    cout << *max_element(sums.begin(), sums.end()) << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}