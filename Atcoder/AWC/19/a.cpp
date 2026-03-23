
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k;
    cin >> n >> k;
    vector <int> a (n);
    int cnt = 0;
    for (int & i : a) {
        cin >> i;
        if (i >= k) cnt ++;
    }

    cout << cnt << '\n';
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}