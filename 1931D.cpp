#include<bits/stdc++.h>
#define int long long
#define f(i,a,b) for (int i=a;i<b;i++)
#define all(a) a.begin(),a.end()
#define vint vector<int>
#define mint map<int,int>
#define sint set<int>
#define qint queue<int>
#define pb push_back
#define pf push_front
const int MOD = 1e9 + 7;
using namespace std;

void solve(){
    int n, x, y, ans = 0;
    cin >> n >> x >> y;

    vint a(n);
    map<int, map<int, int>> mp;

    f(i,0,n){
        cin >> a[i];
        mp[a[i] % x][a[i] % y]++;
    }

    f(i,0,n){
        int m = a[i] % x, n = a[i] % y;

        mp[m][n]--;
        if(mp[m][n] == 0) mp[m].erase(n);

        if(m == 0) m = x;

        if(mp[x-m].find(n) != mp[x-m].end()) ans += mp[x-m][n];
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}