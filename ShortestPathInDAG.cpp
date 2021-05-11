#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;} 
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
#define NFS(nitro) ios_base::sync_with_stdio(false);cin.tie(0);
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long
#define vivek main
#define all(x) (x).begin(),(x).end()
#define vec_p vector<pair<int,int>>
#define v vector<int>

void Topo(int node, vec_p adj[], stack<int> &st, v &vis)
{
    vis[node] = 1;
    for (auto x : adj[node])
    {
        if (!vis[x.first])
            Topo(x.first, adj, st, vis);
    }
    st.push(node);
}

void shortestPath(vector<pair<int,int>> adj[],int n,int source){
    v vis(n+1);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(!vis[i]){
           Topo(i,adj,st,vis);
        }
    }

    v dist(n,1e9);
    dist[source] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(dist[node]!=1e9){
            for(auto x:adj[node]){
                if(dist[node] + x.second < dist[x.first])   dist[x.first] = dist[node] + x.second;
            }
        }
    }

}

void solve(){
    int m,n;cin>>m>>n;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
    int source;cin>>source;
    shortestPath(adj,n,source);

}
int32_t vivek(){
NFS(NITRO);
int t;
cin>>t;
while(t-->0)
    solve();
return 0;
}

// ___.   .__                 __          .__              __    
// \_ |__ |  | _____    ____ |  | _____  _|__|__  __ ____ |  | __
//  | __ \|  | \__  \ _/ ___\|  |/ /\  \/ /  \  \/ // __ \|  |/ /
//  | \_\ \  |__/ __ \   \___|    <  \   /|  |\   /\  ___/|    < 
//  |___  /____(____  /\___  >__|_ \  \_/ |__| \_/  \___  >__|_ \
//      \/          \/     \/     \/                    \/     \/
