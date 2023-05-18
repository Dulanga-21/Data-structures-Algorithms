#include <iostream>
#include<list>
using namespace std;
struct Node{
// A node will 2 entities
//1. data type int called label
//2. a int type list called neighbours
    int label;
    list<int> neighbours;
};
struct Graph{
//graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];
    void intializenodes(){
        for(int j=0;j<n;j++){
            nodes[j].label=j+1;
        }
    }
//iterate through the nodes and assign labels
    void addedge(int u, int v){
//select node u and push v into u's neighbour
//select node v and push u into v's neighbour
        nodes[u-1].neighbours.push_back(v);
        nodes[v-1].neighbours.push_back(u);
    }
    void print(){
//lets iterate through each node and print its neighbours
        for (int i = 0; i < n; i++) {
            cout << " Node-> " << nodes[i].label << " -- neighbours-> ";
            for (int neighbour_node : nodes[i].neighbours) {
                cout << neighbour_node << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph * g = new Graph;
    g->intializenodes();
    g->addedge(2, 1);
    g->addedge(3, 1);
    g->addedge(4, 1);
    g->addedge(5, 1);
    g->addedge(3, 2);
    g->addedge(6, 2);
    g->addedge(6, 4);
    g->addedge(7, 4);
    g->addedge(8, 4);
    g->addedge(6, 5);
    g->addedge(7, 5);
    g->addedge(8, 5);
//add edges for the graphs here.
//print the graph adjaceny list
    g->print();
}