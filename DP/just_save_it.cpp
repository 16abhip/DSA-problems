#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class edge{
    public:
    int source, destination, weight;
    edge(int source, int destination, int weight)
    {
        this -> source = source;
        this -> destination = destination;
        this -> weight = weight;;
    }
};

bool cmp(edge a, edge b){
    return a.weight < b.weight;
}

vector<edge>* f(vector<edge>& graph, int n){
    sort(graph.begin(), graph.end(), cmp);
    int count = 0;
    vector<int> parent;
    vector<edge>* mst = new vector<edge>();
    for(int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
    int edgei = 0;
    while (count != n - 1)
    {
        int s = graph[edgei].source;
        int d = graph[edgei].destination;
        int sp = s, dp = d;
        while(parent[sp] != sp)
        {
            sp = parent[sp];
        }
        while(parent[dp] != dp)
        {
            dp = parent[dp];
        }
        if(sp != dp)
        {
            mst->push_back(graph[edgei]);
            parent[dp] = parent[sp];
            count++;
        }
        edgei++;
    }
    return mst;
}

int main()
{
    vector<edge> graph;
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edge e(s, d, w);
        graph.push_back(e);
    }
    vector<edge>* mst = f(graph, n);
    cout << "Graph: " << endl;
    for(auto i : graph)
    {
        cout << i.source << " " <<  i.destination << " " << i.weight << endl; 
    }
    cout << "MST: " << endl;
    for(int i = 0; i < mst -> size(); i++)
    {
        cout << mst->at(i).source << " " << mst->at(i).destination << " " << mst->at(i).weight << endl;
    }
}

// 4 6
// 0 1 1
// 1 3 2
// 3 2 4
// 2 0 3
// 0 3 5
// 1 2 6