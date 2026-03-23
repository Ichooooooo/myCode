#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int & i : a) cin >> i;
    for (int & j : b) cin >> j;

    int s1 = accumulate(a.begin(), a.end(), 0LL);
    int s2 = accumulate(b.begin(), b.end(), 0LL);

    if (s1 == s2) {
        cout << 1 << '\n';
        return;
    }

    int cnt = 0;
    if (s1 > s2) {
        sort (a.rbegin(), a.rend());
        // int cnt = 0;
        while (s1 > s2) {
            s1 -= a[cnt];
            cnt ++;
        }
    } else {
        sort (b.rbegin(), b.rend());
        // int cnt = 0;
        while (s1 < s2) {
            s2 -= b[cnt];
            cnt ++;
        }
    }

    cout << cnt << '\n';
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