#include<bits/stdc++.h>

//#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define X first
#define Y second

using namespace std;

vector<vector<int>> a, ans, vec;
vector<int> ok;
int n, k;

void upd1(int pos, int cur) {
    int pos2 = 0, len = (1 << cur);
    for (int i = 0; i < len; i++) {
        int len2 = (1 << (k - cur - 1));
        for (int j = 0; j < len2; j++) {
            ans[pos][pos2] = 0;
            pos2++;
        }
        for (int j = 0; j < len2; j++) {
            ans[pos][pos2] = 1;
            pos2++;
        }
    }
}

void upd2(int cur) {
    if (ok[cur]) return;
    
    ok[cur] = 1;
    int len = (1 << k);
    for (int i = 0; i < len; i++) {
        int len2 = vec[cur].size(), cnt = 0;
        for (int j = 0; j < len2; j++) {
            cnt += (1 << (len2 - j - 1)) * ans[vec[cur][j]][i];
        }
        ans[cur][i] = a[cur][cnt];
    }
    
}

int dfs(int cur) {
    int cnt = 0;
    for (int i = 0; i < vec[cur].size(); i++) {
        cnt = max(cnt, dfs(vec[cur][i]));
    }
    upd2(cur);
    return ++cnt;
}

int32_t main() {
    cin >> n, k = 0;
    int vertex = 0;
    a.resize(n), vec.resize(n), ans.resize(n), ok.resize(n);
    
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (!m) k++, ok[i] = 1;
        else {
            for (int j = 0; j < m; j++) { 
                int x; cin >> x; x -= 1;
                vec[i].push_back(x);
            }
            for (int j = 0; j < (1 << m); j++) {
                int x; cin >> x;
                a[i].push_back(x);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        int len = (1 << k);
        ans[i].resize(len);
        if (!ok[i]) continue;
        upd1(i, vertex++);
    }
    
    int res = dfs(n - 1), len = (1 << k);
    res--;
    cout << res << "\n";
    for (int i = 0; i < len; i++)
        cout << ans[n - 1][i];
    
    return 0;
}