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
        for(int & i : a)cin >> i;
        vector<int> b(n, 0);
        ll sum = 0;
        for(int i = 1; i < n; i ++) {
            b[i] = a[i] - a[i - 1];
            sum += abs(b[i]);
        }
        int mx = -1, t, p;
        for(int i = 1; i < n - 1; i ++) {
            t = abs(b[i]) + abs(b[i + 1]);
            p = abs(b[i] + b[i + 1]);
            if((t - p) > 0 && (t - p) > mx) {
                mx = t - p;
            }
        }
        // cout << mx << endl;
        // cout << sum << endl;
        ll tsum = sum;
            if(abs(b[1]) > abs(b[n - 1])) {
                tsum -= abs(b[1]);
            }else {
                tsum -= abs(b[n - 1]);
            }
        if(mx != -1) {
            sum -= mx;
        }
        sum = min(sum, tsum);
        cout << sum << endl;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0),cout.tie(0);
        int n=1;
        cin>>n;
        while(n--){
            solve();
        }
        return 0;
    }
