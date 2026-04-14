#include<iostream>
#include<fstream>
#include<map>
using namespace std;
vector<int>ans;

void Dfs(int u,vector<bool>&visited,map<int,vector<int>>&mp){
    if(visited[u]==1)return ;
    visited[u]=1;
    ans.push_back(u);
    
    for(int v:mp[u]){

        if(!visited[v])
        Dfs(v,visited,mp);

    }
}
int main(){

    ifstream file("input.txt");

    int x,y;
    map<int,vector<int>>mp;
    while(file>>x>>y){
       
        mp[x].push_back(y);

    }
    ans.clear();


    vector<bool>visited(5,0);
    Dfs(0,visited,mp);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";


    return 0;

}