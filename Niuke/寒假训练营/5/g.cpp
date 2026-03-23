
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    string s; cin >> s;
    char now = '0';
    for (char & i : s) {
        if (now == '0') {
            if (i == '0')
                now = '3';
            else if (i == '1') 
            now = '0';
            else if (i == '2')
            now = '1';
            else if (i == '3')
            now = '2';
            else if (i == '4')
            now = '1';
            else 
            now = '3';
        } else if (now == '1') {
            if (i == '0')
            now = '2';
            else if (i == '1')
            now = '3';
            else if (i == '2')
            now = '0';
            else if (i == '3')
            now = '1';
            else if (i == '4') 
            now = '2';
            else 
            now = '0';
        } else if (now == '2') {
            if (i == '0')
            now = '1';
            else if (i == '1')
            now = '2';
            else if (i == '2')
            now = '3';
            else if (i == '3')
            now = '0';
            else if (i == '4') 
            now = '3';
            else 
            now = '1';
        } else if (now == '3') {
            if (i == '0')
            now = '0';
            else if (i == '1')
            now = '1';
            else if (i == '2')
            now = '2';
            else if (i == '3')
            now = '3';
            else if (i == '4') 
            now = '0';
            else 
            now = '2';
        }
        cout << now;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}