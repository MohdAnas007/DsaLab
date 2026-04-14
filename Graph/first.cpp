#include<iostream>
#include<fstream>
using namespace std;


class graph{
    int v;
    bool **mat;
    public:
    graph(int v){
        this->v=v;

        mat=new bool*[v];

        for(int i=0;i<v;i++){
            mat[i]=new bool[v];
            
        }

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                mat[i][j]=0;

            }
        }

    }
    void addEdge(int u,int v){
        if(u>=this->v || v>=this->v )return ;

        mat[u][v]=1;
        mat[v][u]=1;

    }

    void dfs(int u,vector<bool>&visited){

        visited[u]=1;
        cout<<u<<" ";

        for(int i=0;i<v;i++){
            if(mat[u][i]==1){
                if(!visited[i]){
                    dfs(i,visited);

                }
            }
        }
    }

    void print(){

        for(int i=0;i<v;i++){

            for(int j=0;j<v;j++){
                cout<<mat[i][j]<<" ";

            }
            cout<<endl;

        }
    }

};

int main(){

    graph g(7);
    ifstream file("input.txt");

    int x,y;
    while(file>>x>>y){


        g.addEdge(x,y);


    }

    vector<bool>visited(7,0);

    for(int i=0;i<7;i++){
        if(!visited[i]){
            g.dfs(i,visited);

        }
    }





    return 0;

}