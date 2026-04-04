#include<iostream>
#include<fstream>
using namespace std;
template<typename T>
class Queue{
    T *arr;
    int count;
    int first;
    int second;
    int capacity;
    public:
    Queue(int size){
        arr=new T[size];

        capacity=size;
        count=0;
        first=0;
        second=0;

    }

    bool empty(){
        return count==0;

    }
    bool full(){
        return count==capacity;

    }

    void push(T val){
        if(full()){
            cout<<"Queue is full"<<endl;
            return ;

        }
        count++;
        arr[second]=val;
        second=(second+1)%capacity;
        return ;



    }

    void pop(){

        if(empty()){
            cout<<"queue is empty"<<endl;
            return;

        }
        first=(first+1)%capacity;
        count--;
        return ;

    }

    T front(){
        if(full()){
            cout<<"Queue is full"<<endl;
            return -1;

        }
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;

        }

        return arr[first];

    }
    ~Queue(){
        delete[]arr;

    }
};




























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
    AdjList*array;
    public:
    graph(int v){
        this->v=v;
        array=new AdjList[v];

        for(int i=0;i<v;i++){
            array[i].head=nullptr;

        }
    }

    void addEdge(int u,int v){
        // for connection u->v

        Edge*newNode=new Edge;
        newNode->dest=v;
        newNode->next=array[u].head;
        array[u].head=newNode;

        // for connectiomn v->u;
        Edge*newNode2=new Edge;
        newNode2->dest=u;
        newNode2->next=array[v].head;
        array[v].head=newNode2;
        
    }
    void BFS(int start){
        bool *visited=new bool[v];

        for(int i=0;i<v;i++)visited[i]=false;

        queue<int>q;
        q.push(start);
        visited[start]=true;


        while(!q.empty()){

            int currNode=q.front();
            q.pop();
            cout<<currNode<<" ";

            Edge*temp=array[currNode].head;

            while(temp){
                int neighbour=temp->dest;

                if(visited[neighbour]==false){
                    visited[neighbour]=true;
                    q.push(neighbour);

                }
                temp=temp->next;

            }

        }
        cout<<endl;
        delete[] visited;
    }
    void printGraph(){

        for(int i=0;i<v;i++){
           cout<<"Vertex:"<<i<<" -> ";

            Edge*curr=array[i].head;
            while(curr){
                cout<<curr->dest<<",";
                curr=curr->next;

            }
            cout<<endl;


        }
    }

    void dfs(int node,vector<bool>&visited){

        cout<<node<<" ";
        visited[node]=1;

        Edge*temp=array[node].head;
        while(temp){
            if(visited[temp->dest]==0){
                dfs(temp->dest,visited);

            }
            temp=temp->next;

        }

    }
};


int main(){

   Queue<char>q(5);
   q.push('f');
   q.push('g');
   while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
    
   }

    



    return 0;

}