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

    char trump;
    cin >> trump;
    unordered_map<char, vint> mp;

    f(i,0,2*n){
        string s;
        cin >> s;
        mp[s[1]].pb(s[0] - '0');
    }

    for(auto it : mp){
        if(it.first != trump) c += it.second.size() % 2;
    }

    if(c > mp[trump].size()){
        cout << "IMPOSSIBLE\n";
        return;
    }

    auto temp = mp[trump];
    sort(all(temp));
    int ind = 0;

    for(auto it : mp){
        if(it.first == trump) continue;

        auto vec = it.second;
        char suit = it.first;
        sort(all(vec));
        int j = vec.size() % 2;

        if(j){
            cout << vec[0] << suit << " " << temp[ind++] << trump << endl;
        }

        for(int i = j; i < vec.size()-1; i += 2){
            cout << vec[i] << suit << " " << vec[i+1] << suit << endl;
        }
    }
    
    int size = temp.size();
    
    while(ind <= size-2){
        cout << temp[ind] << trump << " " << temp[ind+1] << trump << endl;
        ind += 2;
    }
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
