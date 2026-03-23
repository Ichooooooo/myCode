
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n);
    // fanwei n
    int m = sqrt(n);
    unordered_map <int, int> mp;
    vector <int> b; b.reserve(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] <= n) {
            mp[a[i]] ++;
            b.push_back(a[i]);
        }
    }

    ranges :: sort (b);
    b.erase(unique(b.begin(), b.end()), b.end());

    int pos = lower_bound(b.begin(), b.end(), sqrt(n)) - b.begin();
    int m = b.size();

    for (int i = 0; i < pos; i ++) {
        int p = upper_bound(b.begin(), b.end(), n / b[i]);
        for (int j = i; j < p; j ++) {
            if (j * i > n) break;
            else 
        }
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}