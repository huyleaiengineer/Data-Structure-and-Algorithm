#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int n, m;

int pi[100];
string color[100];

void readFile(string s);
void showAdjLinkedList(vector<vector<int>> graph);

void dfs_visit(int u)
{
    color[u] = "gray";
    for (int v : graph[u])
    {
        if (color[v].compare("white")==0)
        {
            pi[v]=u;
            dfs_visit(v);
        }
    }
    cout << u << " -> ";
    color[u] = "brown";
}

void dfs (vector<vector<int>> graph)
{
    for (int i = 1; i <= n; ++i)
    {
        color[i] = "white";
        pi[i] = NULL;
    }
    cout << "Graph Search using DFS: \n";
    for (int i = 1; i <= n; ++i)
        if (color[i].compare("white")==0){
            dfs_visit(i);
            cout << endl;
        }
    cout << endl;
}

int GraphComponents()
{
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        color[i] = "white";
        pi[i] = NULL;
    }
    cout << "Graph Search using DFS: \n";
    for (int i = 1; i <= n; ++i){
        if (color[i].compare("white")==0){
            dfs_visit(i);
            cout << endl;
            d++;
        }
    }
    cout << endl;
    return d;
}

int main()
{
    string s = "graph2.txt";
    readFile(s);
    cout << "Adjancent List:\n";
    showAdjLinkedList(graph);
    dfs(graph);
    int d = GraphComponents();
    if (d == 1)
        cout << "Connected graph\n";
    else
        cout << "Numbers of graph components = " << d << '\n';
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
