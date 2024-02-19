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
    int n, c = 0;
    cin >> n;
    string a;
    cin >> a;

    c += (a[0] == '@');

    f(i,1,n){
        if(a[i] == a[i-1] && a[i] == '*') break;

        if(a[i] == '@') c++;
    }

    cout << c << endl;
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
