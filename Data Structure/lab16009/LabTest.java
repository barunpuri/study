// Lab 009	: 
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
					int v1, v2, cost;
					v1 = in.nextInt();
					v2 = in.nextInt();
					cost = in.nextInt();
					graph.Edge(v1, v2, cost);
				} else if(cmd.equals("floyd")) {
					graph.Floyd();
				} else if(cmd.equals("outpath")) {
					int v1, v2;
					v1 = in.nextInt();
					v2 = in.nextInt();
					System.out.print("Path from " + v1 + " " + v2 + " : ");
					System.out.print(v1);

					graph.outputPath(v1, v2);

					System.out.println(" => " + graph.GetPathLength(v1, v2));
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		System.err.println("");
	}
}




