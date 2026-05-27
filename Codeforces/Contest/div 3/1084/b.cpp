
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;  cin >> n;
    vector <int> a (n + 1);
    
    int ok = 0;
    for (int i = 1; i <= n; i ++)  {
        cin >> a[i];
        if (i != 1 && a[i] < a[i - 1]) ok = 1;
    }

    if (ok) {
        cout << 1 << '\n';
    } else {
        cout << n << '\n';
    }

    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}