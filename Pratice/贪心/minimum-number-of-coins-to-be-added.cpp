// 常见模拟错误
// 1. 注意过程中可能存在while才能满足的情况, 不是仅+-
// 2. 注意判断模拟完整个数组是否已经到达最终情况
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

class Solution {
public:
    int minPatches (vector<int>& nums, int n) {
        sort (nums.begin(), nums.end());

        int ans = 0;
        int sz = nums.size();
        int now = 1;
        for (int i = 0; i < sz; i ++) {
            if (nums[i] <= now) {
                now += nums[i];
            } else {

                // cout << "i : " << i << ' ' << nums[i] << '\n';
                while ((now - 1) < n && nums[i] > now) {
                    now += now;
                    ans++;

                    // cout << now << '\n';
                }

                now += nums[i];
            }

            if ((now - 1) >= n) {
                break;
            }
        }

        while (now - 1 < n) {
            now += now;
            ans ++;
        }
        return ans;
    }
};

void ovo() {
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}

