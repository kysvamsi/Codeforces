#include <bits/stdc++.h>
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define vint vector<int>
#define mint map<int, int>
#define qint queue<int>
#define sint set<int>
#define pb push_back
#define pf push_front
using namespace std;

void solve(){
    int n, c;
    cin >> n;

    vint adj[n];
    vint inDegree(n, 0);
    qint q;
    vint cost(n, 0);

    f(i, 0, n){
        int x;
        cin >> x;
        adj[i].pb(x-1);

        inDegree[x-1]++;
    }

    f(i, 0, n) cin >> cost[i];

    f(i, 0, n){
        if(inDegree[i] == 0) q.push(i);
    }

    c = n;
    vint ans;
    vint vis(n, 0);

    while(!q.empty() || c){
        if(q.empty()){
            int mini = -1;

            f(i, 0, n){
                if(vis[i] == 0 && mini == -1){
                    mini = i;
                    continue;
                }
                if(vis[i] == 0 && cost[mini] > cost[i]) mini = i;
            }

            for(auto it : adj[mini]){
                inDegree[it]--;

                if(inDegree[it] == 0) q.push(it);
            }
        }

        auto node = q.front();
        q.pop();
        ans.pb(node);
        c--;
        vis[node] = 1;

        for(auto it : adj[node]){
            inDegree[it]--;

            if(inDegree[it] == 0) q.push(it);
        }
    }

    for(auto it : ans){
        cout << it+1 << " ";
    }

    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}