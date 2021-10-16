#include<bits/stdc++.h>

#define int long long

using namespace std;

bool sym(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] && !a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool ansym(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (a[i][j] && a[j][i])
                    return false;
            }
        }
    }
    return true;
}

bool ref(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        if (!a[i][i])
            return false;
    }
    return true;
}

bool anref(vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i][i])
            return false;
    }
    return true;
}


bool tr(vector<vector<int>> &a, int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i][j] && a[j][k] && !a[i][k])
                    return false;
            }
        }
    }
    
    return true;
}

int32_t main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    vector<set<int>> ea(n), eb(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j])
                ea[i].insert(j);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
            if (b[i][j])
                eb[i].insert(j);
        }
    }
    
    vector<int> ans1(5), ans2(5);
    
    cout << (int)ref(a, n) << " " << (int)anref(a, n) << " " << (int)sym(a, n) << " " << (int)ansym(a, n) << " " << (int)tr(a, n) << "\n";
    cout << (int)ref(b, n) << " " << (int)anref(b, n) << " " << (int)sym(b, n) << " " << (int)ansym(b, n) << " " << (int)tr(b, n) << "\n";
    
    
    //compose
    
    vector<vector<int>> c(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] && b[k][j])
                    c[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}