#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename vertexType>
class graph
{
	int** adjMatrix; //2D matrix representing adj vertices
	vertexType* v_list; //list of vertices
	int n_vert; //total number of vertices in graph
	int v_index; //index of vertices to store the data
public:
	graph(int v)
	{
		n_vert = v; //7
		v_list = new vertexType[n_vert];
		adjMatrix = new int* [n_vert]; //7*7 = 49
		for (int i = 0; i < n_vert; i++)
			adjMatrix[i] = new int[n_vert];
		for (int i = 0; i < n_vert; i++)
		{
			for (int j = 0; j < n_vert; j++)
				adjMatrix[i][j] = 0;
		}
		v_index = 0; //
	}
	void addVertex(vertexType v_info)
	{
		if (v_index < n_vert)
		{
			v_list[v_index++] = v_info;
		}
	}
	void addEdge(vertexType src, vertexType dest, int w=1)
	{
		int r = getIndex(src);
		int c = getIndex(dest);
		if (r == -1 || c == -1)
			cout << "either src or dest does not exist\n";
		else
			adjMatrix[r][c] = w;
			//adjmatric[c][r] = w; //for undirected graph
	}
	int getIndex(vertexType info)
	{
		for (int i = 0; i < n_vert; i++)
		{
			if (v_list[i] == info)
				return i;
		}
		return -1;
	}
	void printAdj()
	{
		for (int i = 0; i < n_vert; i++)
		{
			for (int j = 0; j < n_vert; j++)
			{
				if (adjMatrix[i][j] != 0)
				{
					cout << v_list[i] << " and " << v_list[j] << " are adjacent\n";
					cout << "dist between the vert is " << adjMatrix[i][j] << endl;
				}
			}
		}
	}
	void BFS(vertexType start) {
		int startIdx = getIndex(start);
		if (startIdx == -1) {
			cout << "Start vertex not found in graph.\n";
			return;		
		}
		//initialize the visitied array with false
		//All nodes are unvisited
		vector<bool> visited(n_vert, false); 
		//create a queue for BFS traversal		
		queue<int> q;
		//mark source vertex as visited
		visited[startIdx] = true;
		q.push(startIdx);

		cout << "BFS Traversal starting from vertex " << start << ": ";
		while (!q.empty()) 
		{
			int current = q.front();
			q.pop();
			cout << v_list[current] << ",";
			// Visit all the neighbors of the current vertex and push the unvisited vertices in queue
			for (int i = 0; i < n_vert; i++) {
				if (adjMatrix[current][i] != 0 && !visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
		cout << endl;
	}
	// DFS - Depth First Search (Recursive)
	void DFS(vertexType start) {
		int startIdx = getIndex(start);
		if (startIdx == -1) {
			cout << "Start vertex not found in graph.\n";
			return;
		}
		vector<bool> visited(n_vert, false);
		cout << "DFS Traversal starting from vertex " << start << ": ";
		DFSVisit(startIdx, visited);
		cout << endl;
	}
	// Helper function for DFS (recursive)
	void DFSVisit(int v, vector<bool>& visited) {
		visited[v] = true;
		cout << v_list[v] << ",";

		// Visit all the neighbors of the current vertex
		for (int i = 0; i < n_vert; i++) {
			if (adjMatrix[v][i] != 0 && !visited[i]) {
				DFSVisit(i, visited);
			}
		}
	}
};
int main()
{
	graph<string> g1(7);
	g1.addVertex("Austin");
	g1.addVertex("Dallas");
	g1.addVertex("Washington");
	g1.addVertex("Denver");
	g1.addVertex("Atlanta");
	g1.addVertex("Chicago");
	g1.addVertex("Houston");
	g1.addEdge("Austin", "Dallas", 200);
	g1.addEdge("Austin", "Houston", 160);
	g1.addEdge("Dallas", "Austin", 200);
	g1.addEdge("Dallas", "Denver", 780);
	g1.addEdge("Washington", "Dallas", 1300);
	g1.addEdge("Washington", "Atlanta", 600);
	g1.addEdge("Atlanta", "Washington", 600);
	g1.addEdge("Atlanta", "Houston", 800);
	g1.addEdge("Houston", "Atlanta", 800);
	g1.addEdge("Chicago", "Denver", 1000);
	g1.addEdge("Denver", "Chicago", 1000);
	g1.addEdge("Denver", "Atlanta", 1400);
	//g1.printAdj();
	//cout << endl;
	//g1.BFS("Austin");
	g1.DFS("Washington");

}