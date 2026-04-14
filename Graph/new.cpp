#include<iostream>
#include<fstream>
using namespace std;

struct Edge{
    int dest;
    Edge*next;

};
struct AdjList{
    Edge*head;

};
class graph{
    private:
    int v;
    AdjList *arr;
    public:
    

    graph(int v){
        this->v=v;
        arr=new AdjList[v];

        for(int i=0;i<v;i++){
            arr[i].head=nullptr;
        }
    }

    void addEdge(int u,int v){
        // for u->v

        Edge*newNode=new Edge;
        newNode->dest=v;
        newNode->next=arr[u].head;
        arr[u].head=newNode;

        // for v->u

        Edge*temp=new Edge;

        temp->dest=u;
        temp->next=arr[v].head;
        arr[v].head=temp;

    }


    void printGraph(){


        for(int i=0;i<v;i++){
            Edge*temp=arr[i].head;
            cout<<"vertex "<<i<<"-> ";
            while(temp){
                cout<<temp->dest<<" ";
                temp=temp->next;

            }
            cout<<endl;

        }
    }


    void BFS(int start){

        bool*visited=new bool[v];
        for(int i=0;i<v;i++)visited[i]=false;

        queue<int>q;

        q.push(start);
        visited[start]=true;


        while(!q.empty()){
            int node=q.front();
            q.pop();

            cout<<node<<" ";

            Edge*temp=arr[node].head;

            while(temp){

                int x=temp->dest;
                

                if(visited[x]==false){
                    visited[x]=true;
                    q.push(x);

                }

                temp=temp->next;

            }
        

        
    }

    }

    void dfs(int node,vector<bool>&visited){

        cout<<node<<" ";
        visited[node]=true;


        Edge*temp=arr[node].head;


        while(temp){

            if(visited[temp->dest]==false){
               
                dfs(temp->dest,visited);

                


            }
            temp=temp->next;

        }
    
}

    bool detectCycle(int node,vector<bool>&visited,int parent){

        visited[node]=1;

        Edge*temp=arr[node].head;

        while(temp){

            if(temp->dest==parent){
                temp=temp->next;
                continue;

            }
            if(visited[temp->dest]==1){
                return 1;

            }

            if(detectCycle(temp->dest,visited,node))return 1;


            temp=temp->next;

        }
        return 0;


    }

};


int main(){
    graph g(5);
    ifstream file("input.txt");


    int x;int y;

    while(file>>x>>y){
        g.addEdge(x,y);
    }
    g.printGraph();
    g.BFS(0);
    cout<<endl;

    vector<bool>visited(5,false);

    cout<<g.detectCycle(0,visited,-1);






    return 0;

}