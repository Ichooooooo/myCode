
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int nums[30001]; // 数字访问

void ovo(){   
    int n;  cin >> n;
    vector <vector <int>> a (n);

    memset(nums, 0, sizeof (nums));
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x; a[i].reserve(x);
        int t;
        for (int j = 0; j < x; j ++) {
            cin >> t;
            a[i].push_back(t);
            nums[t] = 1;
        }
    }

    vector <int> vis (n, 1); // 博客访问
    int cnt = n;
    
    
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}