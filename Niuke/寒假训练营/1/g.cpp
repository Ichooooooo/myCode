#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    string l, r, ans;  cin >> l >> r;

    if (r[0] == '1' && count(r.begin(), r.end(), '0') == (r.size() - 1)) {
        int t = r.size() - 1;
        while (t --) ans += '9';
    } else if (count(r.begin(), r.end(), '9') == (r.size())) {
        ans = r;
    } else {
        int n = r.size(), w = -1;
        for (int i = 0; i < n; i ++) {
            if (i == 0 && r[i] == '1') {ans += '1'; continue;}
            else if (r[i] > '0') {
                int cnt = count (r.begin() + i + 1, r.end(), '9');
                if (cnt == n - i) {
                    while (cnt --)  ans += '9';
                } else {
                    ans += r[i] - 1;
                    for (int i = i + 1; i < n; i ++) ans += '9';
                } 
                break;
            } else {
                ans += r[i];
            }
        }
    }
        if (ans[n - 1] == '0') ans[n - 1] = '1';
        if (w != -1) for (int i = w; i < n; i ++) ans += '9';
    }
    ranges :: reverse(ans);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}