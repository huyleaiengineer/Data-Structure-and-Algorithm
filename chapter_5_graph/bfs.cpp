#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int n, m;

int pi[100];
string color[100];

void readFile(string s);
void showAdjLinkedList(vector<vector<int>> graph);

void bfs(vector<vector<int>> graph, int s)
{
    for (int u = 1; u <= n; ++u){
        color[u] = "white";
        pi[u] = NULL;
    }
    color[s] = "gray";
    pi[s] = NULL;
    queue<int> Q;
    Q.push(s);
    //cout << "BFS:\n";
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : graph[u])
            if (color[v].compare("white")==0)
            {
              //  cout << "list: " << v << "-> ";
                color[v] = "gray";
                pi[v] = u;
                Q.push(v);
            }
        //cout << "\n";
        cout << " -> " << u;
        color[u] = "brown";
    }
    cout << '\n';
}



void printPath(int s, int v)
{
    vector<int> path;
    cout << "bfs from " << s << "\n";
    bfs(graph, s);
    for (int i = v; i!=NULL; i = pi[i])
    {
        path.push_back(i);
    }
    if (path[path.size()-1]!=s)
        cout << "No path from " << s << " to " << v << endl;
    else
    {
        cout << "Path from " <<  s << " to " << v << ": ";
        reverse(path.begin(), path.end());
        for (int i : path)
            cout << i << ' ';
        cout << '\n';
    }
}

int main()
{
    string s = "graph1.txt";
    readFile(s);
    cout << "Adjancent List:\n";
    showAdjLinkedList(graph);
    bfs(graph, 1);
    vector<pair<int, int>> pairvertices = {{1, 2}, {1, 8}, {3, 10}, {2, 6}};
    for (auto i : pairvertices)
        printPath(i.first, i.second);
    return 0;
}

void readFile(string s)
{
    ifstream f(s);
    f >> n >> m;
    graph.resize(n+1);
    int x, y;
    for (int i = 1;  i <= m; ++i)
    {
        f >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void showAdjLinkedList(vector<vector<int>> graph)
{
    for (int i = 1; i < graph.size(); ++i)
    {
        cout << i << " -> ";
        for (int j : graph[i])
            cout << j << " -> ";
        cout << "NULL\n";
    }
}
