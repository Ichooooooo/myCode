#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    vector <int> b (n);
    int cnt = 0;
    for (int & i : b)  {
        cin >> i;   
        if (i > 0) cnt ++;
    }
    
    int sum = accumulate(b.begin(), b.end(), 0LL);
    
    cout << min (cnt, sum - n + 1) << endl;
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