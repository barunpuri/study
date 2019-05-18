import java.util.*;

/**
 */

class ArrayTree  {
	int[] tree; // tree

	int treeSize;	// number of elements in tree
	int capacity;	// size of the tree tree


	ArrayTree(int theCapacity)
	{ // ArrayTree constructor. 
		capacity = theCapacity;
		tree = new int[capacity];	// tree[0] is not used
		treeSize = 0;
	}

	public String toString() { // Show all the element in sequence
		String str = new String();
		str = "Tree : - ";

		// print all the nodes in the tree
		for(int i = 1; i <= treeSize; i++)
			str += tree[i] + "  ";
		return str;
	}

	void  Init(int[] es, int n)
	{	// initialize the tree by using the input
		treeSize = n;
		for(int i = 1; i <= n; i++)
			tree[i] = es[i];
	}

	void  PreOrder(int node)
	{
		if(node > treeSize)
			return;
		if(tree[node] == 0 ) 
			return;
		System.out.print(tree[node] + " ");
		PreOrder(node*2);
		PreOrder(node*2+1);
	}

	void  InOrder(int node)
	{
		if(node > treeSize)
			return;
		if(tree[node] == 0 ) 
			return;
		InOrder(node*2);
		System.out.print(tree[node] + " ");
		InOrder(node*2+1);

	}

	void  PostOrder(int node)
	{
		if(node > treeSize)
			return;
		if(tree[node] == 0 ) 
			return;
		PostOrder(node*2);
		PostOrder(node*2+1);
		System.out.print(tree[node] + " ");	
	
	}

}

