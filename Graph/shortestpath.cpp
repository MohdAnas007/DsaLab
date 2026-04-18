#include<iostream>
#include<fstream>
using namespace std;
struct Pair{
    int first;
    int second;
};

class graph{

    int **mat;
    int v;
    public:

    graph(int v){
        this->v=v;
        mat=new int*[v];
        for(int i=0;i<v;i++){
            mat[i]=new int[v];
        }

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                mat[i][j]=0;

            }
        }



    }

    void addEdge(int u,int v,int wt){
        if(u>=this->v || v>=this->v)return;

        mat[u][v]=wt;
        mat[v][u]=wt;


    }


   
    void shortestPath(int startNode){
        
        int *ans=new int[v+1];
        for(int i=0;i<v;i++){
            ans[i]=INT_MAX;

        }

        queue<int >q;
        q.push(startNode);
        ans[startNode]=0;


       while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int i=0;i<v;i++){
                int wt=mat[node][i];

                if( wt!=0 && ans[node]!=INT_MAX && ans[node]+wt<ans[i]){
                    ans[i]=ans[node]+wt;
                    q.push(i);

                }
            }
       }


        for(int i=0;i<v;i++){
            cout<<ans[i]<<" ";

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
    graph g(6);

    int x,y,z;

    ifstream file("input.txt");

    while(file>>x>>y>>z){

        g.addEdge(x,y,z);

    }
   
    g.shortestPath(1);




    
    return 0;

}