#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class directedGraph
{

    vector < vector < int > >adList;

public:

    void addNode (int a);
    void addEdge (int source, int target);
    int hasEdge (int source, int target);
    void BFS (int startNode);
    void DFS (int startNode);
    int twoCycles ();
};


void directedGraph::addNode (int a)
{
    if (a >= adList.size())
        adList.resize(a + 1, vector<int>());
    adList[a] = vector<int>();
}

void directedGraph::addEdge (int source, int target)
{
    adList[source].push_back (target);
}

int directedGraph::hasEdge (int source, int target)
{
    if ( find(adList[source].begin(), adList[source].end(), target) != adList[source].end() ) return 1;
    return 0;
}

void directedGraph::BFS (int startNode)
{
    cout<<"Parcurgere in latime: ";
    queue < int > q;
    int viz[10001]= {0};
    q.push (startNode);
    viz[startNode] = 1;
    while (q.size () > 0)
    {
        int v = q.front ();
        for (int i = 0; i < adList[v].size (); i++)
            if (viz[adList[v][i]] == 0)
            {
                q.push (adList[v][i]);
                viz[adList[v][i]] = 1;
            }
        cout << v << " ";
        q.pop ();
    }
    cout<<endl;
}

int viz[10001];
void directedGraph::DFS (int startNode)
{
    cout << startNode << " ";
    viz[startNode] = 1;
    for (int i = 0; i < adList[startNode].size (); i++)
        if (viz[adList[startNode][i]] == 0)
            DFS (adList[startNode][i]);
}

int directedGraph::twoCycles ()
{
    int nr = 0;
    for (int i = 0; i < adList.size () - 1; i++)
        for (int j = i + 1; j < adList.size (); j++)
            if (hasEdge (i, j) == 1 && hasEdge (j, i) == 1)
                nr++;
    return 2*nr;
}

int main ()
{
    directedGraph g;
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"Parcurgere in adancime: ";
    g.DFS(2);
    cout << endl;
    g.BFS(1);
    cout<<g.hasEdge(1,2)<<endl;
    cout<<g.hasEdge(3,2)<<endl;
    cout<<g.twoCycles();
    return 0;
}
