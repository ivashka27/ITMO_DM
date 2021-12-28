#include <bits/stdc++.h>
  
#define int long long
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
  
using namespace std;
  
int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1], ans += a[i];
        int pos1 = i, pos2 = n - 1;
        sort(all(a));
    }
    cout << ans;
    return 0;
}