#include<iostream>
#include<fstream>
using namespace std;
template<typename T>
class Queue{

   T *arr;
   int front;
   int rear;
   int size;
   int capacity;
    public:

   Queue(int n){
      arr=new T[n];
      capacity=n;
      front=0;
      rear=-1;

      size=0;
   }


   bool isFull(){

    return size==capacity;

   }
   bool isempty(){

    return size==0;

   }
   void push(T x){
       if(isFull()){
        cout<<"queue is full";
        return ;

       }
       rear=(rear+1)%capacity;
       arr[rear]=x;
       size++;
       
   }
   void pop(){
    if(isempty()){
        cout<<"queue is empty";
        return ;

    }

    front=(front+1)%capacity;
    size--;

   }
   T Front(){
        if(isempty()){
            cout<<"queue is empty";
            return T();


        }

        return arr[front];

   }

   int getsize(){
    return size;

   }
};

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

    void bfs(int startnode,vector<bool>&visited){

        queue<int>q;
        q.push(startnode);
        visited[startnode]=1;

        while(!q.empty()){

            int node=q.front();
            cout<<node<<" ";
            q.pop();


            for(int i=0;i<v;i++){
                if(mat[node][i]==1 && !visited[i]){
                    visited[i]=1;
                    q.push(i);

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

    void topologicalSort(){
        vector<int>indeg(v,0);

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
               if(mat[i][j]==1){
                indeg[j]++;
                
               }

            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);

            }
        }


        while(!q.empty()){
            int x=q.front();
            q.pop();
            cout<<x<<" ";

            for(int i=0;i<v;i++){
                if(mat[x][i]==1){
                    indeg[i]--;
                    if(indeg[i]==0)q.push(i);

                }
            }
        }

    }

};

int main(){

     ifstream file("input.txt");
     int v=6;
     graph g(v);

     int x,y;
     while(file>>x>>y){
        g.addEdge(x,y);

     }
     g.topologicalSort();
    return 0;

}