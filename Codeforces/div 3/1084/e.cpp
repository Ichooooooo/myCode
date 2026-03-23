
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

bool isPrime(long long n) {             
    if (n <= 1) return true;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i <= n / i; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

array <int, 3> fjprime (int x) {
    vector <pair<int, int>> fac;

    int mn = x, mx = 0;
    int cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
        mn = 2;
        mx = 2;
    }
    if (cnt) fac.push_back({2, cnt});

    for (long long i = 3; i <= x / i; i += 2) {
        if (x % i == 0) {
            int c = 0;
            while (x % i == 0) {
                x /= i;
                c++;
            }
            fac.push_back({i, c});
            mn = min (mn, i);
            mx = max (mx, i);
        }
        if (fac.size() > 1) return {1, mn, mx};
    }
    if (x > 1) {
        fac.push_back({x, 1});
        mn = min (mn, x);
        mx = max (mx, x);
    }
    
    if (fac.size() > 1) return {1, mn, mx};

    return {0, mn, mx};
}
     
void ovo(){   
    int n;  cin >> n;
    vector <int> a(n);
    int ok = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (i != 0 && a[i] < a[i - 1]) ok = 1;
    }
    
    if (!ok) {
        cout << "Bob" << '\n';
    } else {
        int mxx = -1, okk = 0, okkk = 0;
        for (int i = 0; i < n; i ++) {
            if (isPrime(a[i])) {
                if (mxx > a[i]) {
                    okk =  1; 
                }
                mxx = max (mxx, a[i]);
            } else {
                auto [bl, mn, mx] = fjprime(a[i]);
                // cout << bl << ' ' << mn << ' ' << mx << '\n';
                if (bl == 1) okkk = 1;
                else {
                    if (mn < mxx) okkk = 1;
                    mxx = max (mx, mxx);
                }
            }
        }

        // cout << okk << ' ' << okkk << '\n';
        if (okk || okkk) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}