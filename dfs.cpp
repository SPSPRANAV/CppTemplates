#include <bits/stdc++.h>

using namespace std;
#define N 1000


vector<int> v[N];
int visited[N];
queue<int> q;

void dfs(int x){
    if(visited[x]==0)
    {
        visited[x]=1;
        cout<<x<<endl;
        for(int u:v[x])
        {
        dfs(u);
        }
    }
}


void bfs(int x){
    visited[x]=1;
    q.push(x);


    while(!q.empty())
    {
    int s = q.front(); q.pop();

    for(int u : v[s]){
    if(visited[u]==1) continue;
    visited[u]=1;
    cout<<u<<endl;

    q.push(u);
    }
    }

}
void addEdge(int a, int b)
    {
    v[a].push_back(b);
    v[b].push_back(a);
    }

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        addEdge(x,y);
    }

    dfs(1);
return 0;
}
