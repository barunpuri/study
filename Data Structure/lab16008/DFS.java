// Lab 008	: Graph 
// Name :  조정근
// Student ID : 20153235

import java.util.*;


class Graph {
	int numofnodes;  // the number of nodes in the graph
	private int[][] Adj; // Adjacency matrix
	private int[] mark; // mark the visitied node


	Graph() { 
		// Graph constructor. 
		numofnodes = 0;
	}

	void Init(int n) { 
		numofnodes = n;
		// now create 2 dimensional array of numofnodes * numofnodes
		Adj = new int[numofnodes][numofnodes];
		for(int i = 0; i < numofnodes; i++) {
			// initialize all entries to 0
			for(int j = 0; j < numofnodes; j++)
				Adj[i][j] = 0;  // initialize the adjacency matrix
		}
	}

	void InitVisited() { 
		// initialize the mark array
		mark = new int[numofnodes];
		for(int i = 0; i < numofnodes; ++i)
			mark[i] = 0;	// initialize the mark vector
	}

	void Edge(int e1, int e2) { 
		Adj[e1][e2] = 1;
		Adj[e2][e1] = 1;
	}

	void Dfs(int v) { 

		if( mark[v] != 1)
		{	
			mark[v] = 1;
			System.out.print(v + " ");
			
			for(int i=0; i<numofnodes; ++i)
			{
				if( Adj[v][i] != 0 )
				{	
					Dfs(i);			
				}

			}		
			
		}
	}
}





