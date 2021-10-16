#include<bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define X first
#define Y second

using namespace std;

int32_t main() {
    
    int start = clock();
    
    int n, k; cin >> n >> k;
    
    vector<vector<int>> a(k, vector<int>(n));
    vector<int> neg(n + k, -1), cnt(n + k), res(n + k);
    
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j], cnt[i] += (int)(a[i][j] != -1);
    
    
    for (;;) {
        
        if (clock() - start > 1980) {
            cout << "NO\n";
            return 0;
        }
        
        int cur1 = 0;
        
        for (int pos = 0; pos < k; pos++) {
            
            if (clock() - start > 1980) {
                cout << "NO\n";
                return 0;
            }
            
            if (cnt[pos] != 1 || res[pos]) continue;
            int cur2 = 0;
            res[pos] = 1, cur1++;
            
            for (int i = 0; i < k; i++) {
                
                if (clock() - start > 1980) {
                    cout << "NO\n";
                    return 0;
                }
                
                if (a[pos][i] == -1) continue;
                cur2 = i, neg[i] = a[pos][i];
                break;
                
            }
            
            for (int i = 0; i < k; i++) {
                
                if (clock() - start > 1980) {
                    cout << "NO\n";
                    return 0;
                }
                
                if (res[i]) continue;
                
                int j = cur2;
                
                if (a[i][j] != -1) {
                    
                    if (a[i][j] - neg[j] == 0) res[i] = 1;
                    
                    else {
                        
                        if (!(cnt[i] - 1)) {
                            cout << "YES\n";
                            goto m;
                        }
                        
                        a[i][j] = -1; cnt[i] += a[i][j];
                        
                    }
                }
                
            }
            
        }
        
        if (cur1 == 0) {
            
            break;
            
        }
        
    }
    
    cout << "NO\n";
    
    m:;
    return 0;
}