#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, l, r; cin >> n >> l >> r;
    vector <PII> a (n);
    vector <int> b (n);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i - 1].first;
        b[i - 1] = a[i - 1].first;
        a[i - 1].second = i;
    }

    ranges :: sort (a);
    ranges :: sort (b);

    int p1 = lower_bound(b.begin(), b.end(), l) - b.begin();
    int p2 = upper_bound(b.begin(), b.end(), r) - b.begin();

    if (p1 == n || p2 == 0) {
        cout << -1 << '\n';
    } else {
        int mx = max_element(b.begin() + p1, b.begin() + p2) - b.begin();
        cout << a[mx].second << '\n';
    }

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