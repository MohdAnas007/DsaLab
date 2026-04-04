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
};


int main(){

    graph g(5);
    ifstream file("input.txt");

    int x,y;
    while(file>>x>>y){
        g.addEdge(x,y);

        
    }
    g.printGraph();

    return 0;

}