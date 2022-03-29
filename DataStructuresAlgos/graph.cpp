#include <iostream>
using namespace std;

struct adjNode 
{
    int val, cost;
    adjNode* next;
};

struct graphEdge 
{
    int start_ver, end_ver, weight;
};

class DiaGraph
{
    private:
        int N_nodes;
        adjNode* getAdjListNode(int value, int weight, adjNode* head)   
        {
            adjNode* newNode = new adjNode;
            newNode->val = value;
            newNode->cost = weight;
            newNode->next = head;
            return newNode;
        }
    
    public:
        adjNode **head;
    
        DiaGraph(graphEdge edges[], int n, int N_nodes)  
        {
            head = new adjNode*[N_nodes]();
            this->N_nodes = N_nodes;

            for (int i = 0; i < N_nodes; ++i)
                head[i] = nullptr;

            for (int i = 0; i < n; i++)  
            {
                int start_ver = edges[i].start_ver;
                int end_ver = edges[i].end_ver;
                int weight = edges[i].weight;

                // insert of first element
                adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
                
                // point head pointer to new node
                head[start_ver] = newNode;
            }
    }

};

void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != NULL) 
    {
        cout<<"("<<i<<", "<<ptr->val<<", "<<ptr->cost<<") ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    // graph edges array.
    graphEdge edges[] = {
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int N_nodes = 6; 

    // number of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    DiaGraph diagraph(edges, n, N_nodes);

    cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
    for (int i = 0; i < N_nodes; i++)
    {
        display_AdjList(diagraph.head[i], i);
    }
    return 0;
}