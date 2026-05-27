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
    int n, k, t;
    cin >> n >> k;
    vector<int> a(n), hx;

    for (int & i : a) {
        cin >> i;
        t = i;
        while(t) {
            hx.push_back(t);
            t >>= 1;
        }
    }

    sort(hx.begin(), hx.end());
    hx.erase(unique(hx.begin(), hx.end()), hx.end());

    ll cnt = LLONG_MAX, ccnt = 0;
    for (int i = 0; i < hx.size(); i ++) {
        vector<int> b;
        for (int j = 0; j < n; j ++) {
            int cn = 0;
            t = a[j];
            while (t > hx[i]) {
                t >>= 1;
                cn ++;
            }
            if (t == hx[i]) {
                b.push_back(cn);
            }
        }

        if(b.size() < k) {continue;}
        sort(b.begin(), b.end());
        ccnt = accumulate(b.begin(), b.begin() + k, 0);
        // cout << "B : " << hx[i] << ' ' << ccnt << endl;
        cnt = min(cnt, ccnt);
    }

    cout << cnt << endl;
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