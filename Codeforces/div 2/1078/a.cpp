#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, m;  cin >> n >> m;
    
    if (n % m == 0) {
        cout << n / m * (m - 1) << '\n';
    } else {
        cout << n / m * (m - 1) + (n % m) << '\n';
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