#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    vector <int> a (n);

    for (int & i : a)  cin >> i;
    
    int sum = accumulate(a.begin(), a.end(), 0LL);
    int ans = 0;

    auto cacu = [&](int t, int idx) -> int {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            else if (a[i] > t) ans += a[i] - t;
        }

        return ans;
    };

    if (sum % n == 0) {
        ans = cacu(sum / n, -1);
    } else {
        int a1 = 0, a2 = 0, mn, mx;
        mn = min_element (a.begin(), a.end()) - a.begin();
        mx = max_element (a.begin(), a.end()) - a.begin();

        a1 = cacu((sum - a[mn]) / (n - 1), mn);
        a1 = min (a1, cacu ((sum - a[mn] + n - 2) / (n - 1), mn) + n - 1 - (sum - a[mn]) % (n - 1));
        a2 = cacu((sum - a[mx]) / (n - 1), mx);
        a2 = min (a2, cacu((sum - a[mx] + n - 2) / (n - 1), mx) + n - 1 - ((sum - a[mx]) % (n - 1)));

        ans = min (a1, a2);
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}