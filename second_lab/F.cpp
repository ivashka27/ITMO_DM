#include<bits/stdc++.h>
 
#define int long long
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    map<int, string> mp;
    int alp = 26;
    for (int i = 0; i < alp; i++)
        mp[i] = (char)('a' + i);
    string s, res, cur;
    s = res = mp[a[0]];
    for (int i = 1; i < n; i++) {
        int k = a[i];
        if (mp.count(k)) cur = mp[k];
        else if (k == alp) cur = s + s[0];
        res += cur;
        mp[alp++] = s + cur[0];
        s = cur;
    }
    cout << res;
    return 0;
}