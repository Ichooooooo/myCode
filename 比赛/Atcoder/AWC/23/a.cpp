
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, r;
    cin >> n >> m >> r;
    vector <int> a (n);
    int sum = 0;
    for (int & i : a) {
        cin >> i;
        sum += i;
    }

    cout << sum + m * r << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}