#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#define N 6
using namespace std;

vector< vector<int> > graph(N+1);
enum colors { white, gray, black };
int global_time = 0;
int vstart[N+1];
int vend[N+1];
int vcolor[N+1];

stack<int> topological_order;

void populate_graph()
{
    vector< pair<int, int> > P;
    P.push_back(make_pair(1, 4));
    P.push_back(make_pair(6, 2));
    P.push_back(make_pair(2, 4));
    P.push_back(make_pair(6, 1));
    P.push_back(make_pair(4, 3));

    for (int i = 0; i < P.size(); i++)
    {
        pair<int, int> edge;
        edge = P[i];
        vector<int> list = graph[edge.first];
        list.push_back(edge.second);
        graph[edge.first] = list;
    }
}

void print_graph()
{
    for (int i = 1; i <= N; i++)
    {
        vector<int> list = graph[i];
        cout << i << " : ";
        for (int j = 0; j < list.size(); j++)
        {
            cout << list[j] << " ";
        }
        cout << endl;
    }
}

void visit(int vertex) {
    
    stack<int> visitor;
    visitor.push(vertex);
    //cout<<vertex<<endl;
    while(visitor.empty()!=true) {
        int node = visitor.top();
        visitor.pop();

        if(vcolor[node] == white) {
            global_time += 1;
            vstart[node] = global_time;
            vcolor[node] = gray;
            visitor.push(node);
            for(int i=0; i<graph[node].size(); i++) {
                int neighbor = graph[node][i];
                if(vcolor[neighbor] == white) {
                    visitor.push(neighbor);
                }
            }
        }
        else if(vcolor[node] == gray) {
            vcolor[node] = black;
            global_time += 1;
            vend[node] = global_time;
            topological_order.push(node);
        }
    }

}

void dfs() {
    //cout<<N<<endl;
    for(int i=1; i<=N; i++) {
        vcolor[i] = white;
    }

    for(int i=1; i<=N; i++) {
        if(vcolor[i] == white) {
            visit(i);
        }
    }
}

void print_order() {
    while(topological_order.empty()!=true) {
        int v = topological_order.top();
        cout<<v<<" ";
        topological_order.pop();
    }
    cout<<endl;
}

int main()
{
    populate_graph();
    //print_graph();

    dfs();
    print_order();

    return 0;
}
