#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, x, y;  cin >> n >> x >> y;

    vector <int> a (n);
    for (int & i : a)  cin >>i;

    if (x == y) {
        cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    } else {
        int cnt = 0, mx = -1;
        for (int & i : a) {
            cnt += (i / x);
            mx = max (mx, i % x);
        }

        cout << cnt * y + mx << '\n';
    }
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