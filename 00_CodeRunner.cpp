#include<bits/stdc++.h>
using namespace std;

bool DetectCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[node] = true;
	for(auto i: adj[node]) {
		if(i==parent) {
			return true;
		}
		if(visited[i]) {
			return true;
		}
		if(DetectCycle(i, node, adj, visited)) {
			return true;
		}
	}
	return false;
}

int main() {
	int v, e;
	char n, x, y;
	unordered_map<char, int>node;
	unordered_map<int, char>inverse_node;
	cout<<"Enter the number of the vertices and the edges: ";
	cin>>v>>e;
	vector<vector<int>>adj(v);
	cout<<"Enter the name of the nodes: ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	cout<<"Enter the nodes (from to): "<<endl;
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
	}
	vector<bool>visited(v, false);
	// vector<bool>recStack(v, false);
	bool hasCycle = false;
	for(int i=0; i<v; i++) {
		if(!visited[i]) {
			if(DetectCycle(0, -1, adj, visited)) {
				hasCycle = true;
			}
		}
	}
	if(hasCycle) {
		cout<<"Cycle Detected in the Graph!"<<endl;
	} else {
		cout<<"No Cycle Detected in the Graph!"<<endl;
	}
	return 0;
}