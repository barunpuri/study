// Lab 009	: Graph Floyd Algorithm 
// Name : 조정근	
// Student ID : 20153235

import java.util.*;


class Graph {
	int numofnodes;  // the number of nodes in the graph
	private int[][] CostAdj; // Adjacency matrix
	private int[][] c; // c matrix
	private int[][] kay; // kay matrix

	final int LargeCost = 999999;

	Graph() { 
		// Graph constructor. 
		numofnodes = 0;
	}

	int GetPathLength(int i, int j) { return c[i][j]; };

	void Init(int n) { 
		numofnodes = n;
		// now create 2 dimensional array of numofnodes * numofnodes
		CostAdj = new int[numofnodes][numofnodes];
		c = new int[numofnodes][numofnodes];
		kay = new int[numofnodes][numofnodes];

		for(int i = 0; i < numofnodes; i++) {
			// initialize all entries to 0
			for(int j = 0; j < numofnodes; j++)
				CostAdj[i][j] = LargeCost;  // initialize the adjacency matrix
			CostAdj[i][i] = 0;
			
		}
	}



	void Edge(int v1, int v2, int cost) { 
		
		CostAdj[v1][v2] = cost;
		
	}

	void Floyd() {
		
		for (int i = 0; i < numofnodes; ++i)
        	for (int j = 0; j < numofnodes; ++j)
        	{
        		c[i][j] = CostAdj[i][j];
				kay[i][j] = -1;
			}
			
        for (int k = 0; k < numofnodes; k++)
   			for (int i = 0; i < numofnodes; i++)
      			for (int j = 0; j < numofnodes; j++)
          			if ( c[i][j] > c[i][k] + c[k][j])
             		{	
             			kay[i][j] = k; 
             			c[i][j] = c[i][k] + c[k][j];
             		}
	}            

	void outputPath(int i, int j) { 

		if (i == j) return;
  	
  		if (kay[i][j] == -1)  
    		System.out.print("-" + j);
   		else { 
    		outputPath(i, kay[i][j]);
    	    outputPath(kay[i][j], j);
    	}
	
	}

}















