// Lab 008	: 
// Name :
// Student ID :

import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);

		Graph graph = new Graph();	// Graph

		while(true) {
			try {
				System.err.print("Graph > ");
	
				String cmd = in.next();
				if(cmd.equals("quit"))
					break;
				if(cmd.equals("init")) {
					int nn;
					nn = in.nextInt();

					graph.Init(nn);
				} else if(cmd.equals("edge")) {
					int e1, e2;
					e1 = in.nextInt();
					e2 = in.nextInt();
					graph.Edge(e1, e2);
				} else if(cmd.equals("dfs")) {
					graph.InitVisited();
					int nid;
					nid = in.nextInt();
					graph.Dfs(nid);
					System.out.println("");
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.err.println("");
	}
}




