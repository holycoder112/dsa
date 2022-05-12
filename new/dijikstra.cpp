#include <iostream> 
using namespace std;  
#define V 5
#define INT_MAX 9999

int minDistance(int dist[], bool visited[]) 
{
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (visited[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
   
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; 
    bool visited[V]; 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, visited[i] = false; 
    dist[src] = 0; 
    for (int count = 0; count < V - 1; count++)
	{ 
        int u = minDistance(dist, visited); 

        visited[u] = true; 
  
        for (int v = 0; v < V; v++) 
  
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 

	for(int i = 0; i < V; i++)
		cout<<"\n Shortest distance from "<<src<<" to "<<i<<" is - "<<dist[i];
} 
  
void addEdges(int g[V][V])
{
	for(int i = 0;i<V;i++)
		for(int j = 0;j<V;j++)
			g[i][j] = 0;

	for(int i = 0;i < V;i++)
	{
		for(int j = 0;j < V;j++)
		{
			if(i != j){
				cout<<"Enter weight for the edge from "<<i<<" to "<<j<<" : ";
				cin>>g[i][j];
			}
			else
				g[i][j] = 0;
		}
	}
}

int main() 
{ 
    int graph[V][V];

	addEdges(graph);

    dijkstra(graph, 0); 
  
    return 0; 
} 