#include<iostream>
#include<fstream>
using namespace std;
struct Edge{
    int dest;
    Edge*next;

};

struct AdjsList{
    Edge*head;
};

class graph{
    private:
    int v;
    AdjsList*arr;

    public:
    graph(int v){
        this->v=v;
        arr=new AdjsList[v];
        for(int i=0;i<v;i++){
            arr[i].head=nullptr;

        }
    }
    void addEdge(int u,int v){
        // for u->v connection 
        Edge*newEdge=new Edge;
        newEdge->dest=v;
        newEdge->next=arr[u].head;
        arr[u].head=newEdge;


        // for v->u connection 
        Edge*newEdge2=new Edge;
        newEdge2->dest=u;
        newEdge2->next=arr[v].head;
        arr[v].head=newEdge2;

    }

    void printGraph(){

        for(int i=0;i<v;i++){
            cout<<"Vertex "<<i<<"->";
            Edge*temp=arr[i].head;

            while(temp){
                cout<<temp->dest<<",";
                temp=temp->next;

            }
            cout<<endl;

        }

    }
    
    
    void bfs(int node){
         vector<bool>visited(v,0);

         queue<int>q;
         q.push(node);
         visited[node]=1;

         while(!q.empty()){

            int x=q.front();
            q.pop();

            cout<<x<<" ";

            Edge*temp=arr[x].head;
            while(temp){
                if(visited[temp->dest]==0){
                    q.push(temp->dest);
                    visited[temp->dest]=1;

                }
                temp=temp->next;

            }
          
        
         }
        
    }
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    void dfs(int start,vector<bool>&visited){

        cout<<start<<" ";
        visited[start]=1;
        Edge*temp=arr[start].head;
        while(temp){

            if(!visited[temp->dest]){
                visited[temp->dest]=1;
                dfs(temp->dest,visited);

            }
            temp=temp->next;

        }
    }

    void startdfs(int node){

        vector<bool>visited(v,0);
        dfs(node,visited);

    }
};


int main(){
    graph g(5);
    ifstream file("input.txt");

    int x,y;
    while(file>>x>>y){
        g.addEdge(x,y);

    }


    g.bfs(0);




    return 0;

}