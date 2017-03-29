#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

#define UNVISITED -1
#define MAX 10010

vector<int> graph[MAX], scc;
int qt_vertex, dfs_num[MAX], dfs_low[MAX], numSCC, dfsCount, qt_edges;
bool visited[MAX], has_edge[30][30];
map<string, int> namess;
map<int, string> namesInt;

void clear(){
	for (int i = 0; i <= qt_vertex; i++){
		graph[i].clear();
		dfs_num[i] = UNVISITED;
		visited[i] = 0;
	}
	dfsCount = 0;
	numSCC = 0;
    scc.clear();
    memset(has_edge, 0, sizeof has_edge);
    namess.clear(); namesInt.clear();
}

void tarjanSCC(int vertex){
	dfs_num[vertex] = dfs_low[vertex] = dfsCount++;
	scc.push_back(vertex);
	visited[vertex] = 1;
    for (int i = 0; i < graph[vertex].size(); i++){
    	int new_vertex = graph[vertex][i];
    	if (dfs_num[new_vertex] == UNVISITED)
    		tarjanSCC(new_vertex);
    	if (visited[new_vertex])
    		dfs_low[vertex] = min(dfs_low[vertex], dfs_low[new_vertex]);
    }

    //get SCC
    if (dfs_low[vertex] == dfs_num[vertex]){
      numSCC++;
      while(1){
       int vcc = scc.back(); scc.pop_back();
       visited[vcc] = 0;

       if (vcc == vertex){
       	cout<<namesInt[vcc]<<endl;
        break;
       }else
        cout<<namesInt[vcc]<<", ";
      }
    }
}

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
	int cases = 1;
	string u, v;
	while( (cin >>qt_vertex>>qt_edges) && qt_vertex){
           clear();
           int count = 1;
           if (cases>1) cout<<endl;
           for (int i = 0; i < qt_edges; i++){
        	cin >> u >> v;
        	if (namess[u]==NULL) {namess[u] = count; namesInt[count++] = u;}
        	if (namess[v]==NULL) {
        		namess[v] = count;
        		namesInt[count++] = v;
        	}
        	int iu = namess[u], iv = namess[v];
        	if (!has_edge[iu][iv]){
        	 graph[iu].push_back(iv);
        	 has_edge[iu][iv] = 1;
        	}
            }
            cout<<"Calling circles for data set "<<cases++<<":\n";
            for (int i = 1; i <= qt_vertex; i++)
            if (dfs_num[i] == UNVISITED)
              tarjanSCC(i);
	}
	return 0;
}
