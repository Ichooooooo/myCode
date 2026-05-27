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
    const int MAX = 2 * 1e5 + 10;

    void solve(){   
        int n, k, t;
        cin >> n >> k;
        vector<int> a(n);
        vector<vector<int>> yz(MAX);
        
        for (int & i : a) cin >> i;
        for (int i = 0; i < n; i ++) {
            t = a[i];
            int cn = 0;
            while (t) {
                yz[t].push_back(cn);
                t >>= 1;
                cn ++;
            }
        }

        ll cnt = 1e16;
        for (int i = 1; i < MAX; i ++) {
            if(yz[i].size() < k) {continue;}
            ranges::sort(yz[i]);
            ll cn = accumulate(yz[i].begin(), yz[i].begin() + k, 0LL);
            cnt = min(cnt, cn);
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