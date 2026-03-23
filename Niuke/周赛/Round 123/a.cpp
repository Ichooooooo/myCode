#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n1, n2;
    char c1, c2;
    cin >> n1 >> c1;
    cin >> n2 >> c2;
    if(n1 > n2 || (n1 == n2 && c1 < c2)) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
