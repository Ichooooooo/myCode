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
    int ok = 1;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (i != 0) {
            if (a[i] != a[0]) ok = 0; 
        }
    }

    if (ok && (n & 1)) {
        cout << a[0] << '\n';
    } else if (ok) {
        cout << a[0] << ' ' << 2 * a[0] << '\n';
    } else {
        ranges :: sort (a);
        int tr = a[n - 1];
        int pos = lower_bound(a.begin(), a.end(), tr) - a.begin();
        int ko = 1;
        if (((pos) & 1) == 0) {
            for (int i = 0; i < pos; i ++) {
                if (a[i] + a[pos - 1 - i] != tr) {
                    ko = 0; break;
                }
            }
            if (ko) cout << tr << ' ';
        }
        

        if ((n & 1) == 0) {
            int ok = 1, tar;
            for (int i = 0; i < n / 2; i ++) {
                if (i == 0) {
                    tar = a[i] + a[n - 1 - i];
                } else if (a[i] + a[n - 1 - i] != tar) {
                    ok = 0; break;
                }
            }
            if (ok) cout << tar << ' ';
        }cout << '\n';
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