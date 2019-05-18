import java.util.*;

// Name : 조정근 
// Student ID :20153235


@SuppressWarnings("unchecked")
class BST <T extends KeyValue> {

	class TreeNode <U extends KeyValue> {
		U data;	// storage for data : in HW 3, T will be Item
		TreeNode<U> leftChild;	// link to the left Child
		TreeNode<U> rightChild;	// link to the right Child

		// constructors come here
		TreeNode() {
			leftChild = rightChild = null;
		}
		TreeNode(U d) {
			// data is given
			data = d;
			// the leftChild and rightChild field are null
			leftChild = rightChild = null;
		}
	};

	TreeNode <T> root;// the reference to the root node

	BST() { 
		// BST constructor. 
		root = null;
	}

	void  Show()  {
		System.out.print( "Pre  Order : ");
		PreOrder(root);
		System.out.println("");
		System.out.print("In   Order : ");
		InOrder(root);
		System.out.println("");
		System.out.print("Post Order : ");
		PostOrder(root);
		System.out.println("");
		System.out.print("Count      : ");
		System.out.print( Count(root) +1);
		System.out.println("");
		System.out.print("Height      : ");
		System.out.println( Height(root));
		System.out.println("");
	}


	boolean  Insert(T item)  {				
		// first search the key
		if(root == null) {
			root = new TreeNode(item);

			return true;
		}

		TreeNode<T> ptr, parent;
		ptr = root;
		int keyItem = item.GetKey();

		while(true)
		{
			if( ptr.data.GetKey() > keyItem )
			{
				if( ptr.leftChild != null){
					ptr = ptr.leftChild;
				}	
				else {
					ptr.leftChild = new TreeNode(item);
					break;
				}
			}
			else if( ptr.data.GetKey() < keyItem )
			{
				if( ptr.rightChild != null){
					ptr = ptr.rightChild;
				}
				else {
					ptr.rightChild = new TreeNode(item);
					break;
				}
			}
			else{  // parent.data.GetKey() == keyItem;
				
				ptr.data = item;
				return false;
			}
		}
		
		return true;
	}

	T Get(T item)  {					
		// use the key field of item and find the node
		// do not use val field of item
		TreeNode<T> ptr;
		ptr = root;

		if( root == null ) 
			return null;
	
		int keyItem = item.GetKey();
		while(true){
			if( keyItem > ptr.data.GetKey() )
				if( ptr.rightChild != null )
					ptr = ptr.rightChild;
				else
					return null;
			else if( keyItem < ptr.data.GetKey() )
				if( ptr.leftChild != null )
					ptr = ptr.leftChild;
				else
					return null;
			else // keyItem == ptr.data.GetKey() )
				return ptr.data;
			
		 }
	} 


	boolean Delete(T item)  {
		if(root == null)
			return false;	// non existing key

		TreeNode parent = root;
		TreeNode ptr = root;
		boolean isLeftChild = false;
		while(ptr.data.GetKey()!=item.GetKey()){
			parent = ptr;
			if(ptr.data.GetKey()>item.GetKey()){
				isLeftChild = true;
				ptr = ptr.leftChild;
			}else{
				isLeftChild = false;
				ptr = ptr.rightChild;
			}
			if(ptr ==null){
				return false;
			}
		}
		//if i am here that means we have found the TreeNode
		//Case 1: if node to be deleted has no children
		if(ptr.leftChild==null && ptr.rightChild==null){
			if(ptr==root){
				root = null;
			}
			if(isLeftChild ==true){
				parent.leftChild = null;
			}else{
				parent.rightChild = null;
			}
		}
		//Case 2 : if node to be deleted has only one child
		else if(ptr.rightChild==null){
			if(ptr==root){
				root = ptr.leftChild;
			}else if(isLeftChild){
				parent.leftChild = ptr.leftChild;
			}else{
				parent.rightChild = ptr.leftChild;
			}
		}
		else if(ptr.leftChild==null){
			if(ptr==root){
				root = ptr.rightChild;
			}else if(isLeftChild){
				parent.leftChild = ptr.rightChild;
			}else{
				parent.rightChild = ptr.rightChild;
			}
		}else if(ptr.leftChild!=null && ptr.rightChild!=null){
			
			//now we have found the minimum element in the right sub tree
			TreeNode minimum = getSuccessor(ptr);

			if(ptr==root){
				root = minimum;
			}else if(isLeftChild){
				parent.leftChild = minimum;
			}else{
				parent.rightChild = minimum;
			}			
			minimum.leftChild = ptr.leftChild;
		}		
		return true;
	}
	
	TreeNode getSuccessor(TreeNode deleteNode){
		TreeNode successor = null;
		TreeNode parent = null;
		TreeNode current = deleteNode.rightChild;
		while(current!=null){
			parent = successor;
			successor = current;
			current = current.leftChild;
		}
		//check if successor has the right child, it cannot have left child for sure
		// if it does have the right child, add it to the left of Parent.
//		parent
		if(successor!=deleteNode.rightChild){
			parent.leftChild = successor.rightChild;
			successor.rightChild = deleteNode.rightChild;
		}
		return successor;
	}
		
//키에 해당하는 노드가 없다
//degree ==0(leaf node)(no child)
//	degree ==1  
//	1개의 child 를 parent 와 연결
//		degree ==2
//		left sub tree 중 가장 큰 key || right sub tree중 가장 작은 key
//		정렬했을때 자신 바로 앞의 key  || 정렬했을때 자신 바로 뒤의 key
//		left -> right -> right..... || right -> left -> left ....
	

	void  PreOrder(TreeNode<T> t)  {				 
		if( t != null ){
	
			System.out.print(t.data.GetKey() + "(" + t.data.GetValue() + ") ");			
			PreOrder(t.leftChild);
			PreOrder(t.rightChild);
		}
	}

	void  InOrder(TreeNode<T> t)  {				 
		if( t != null ){
					
			InOrder(t.leftChild);
			System.out.print(t.data.GetKey() + "(" + t.data.GetValue() + ") ");	
			InOrder(t.rightChild);
		}
	}

	void  PostOrder(TreeNode<T> t)  {				
		if( t != null ){
	
			PostOrder(t.leftChild);
			PostOrder(t.rightChild);
			System.out.print(t.data.GetKey() + "(" + t.data.GetValue() + ") ");	
		}
	}

	int  Count(TreeNode<T> t)  {
		if( t == null)
			return -1;
		
		if( ( t.leftChild == null )&&( t.rightChild == null ) )
			return 0;
		else if( t.leftChild == null ) 
			return 1 + Count(t.rightChild);
		else if( t.rightChild == null )
			return 1 + Count(t.leftChild);
		else 
			return 2 + Count(t.leftChild) + Count(t.rightChild);
	}

	int  Height(TreeNode<T> t)  {
		if( t == null)
			return 0;
		
		int leftHeight;
		int rightHeight;
		
		if( t.leftChild != null )
			leftHeight = Height(t.leftChild);
		else 
			leftHeight = 0;
		if( t.rightChild != null)
			rightHeight = Height(t.rightChild);
		else
			rightHeight = 0;
		
		if( leftHeight >= rightHeight )
			return leftHeight+1;
		else //leftHeight < rightHeight
			return rightHeight+1;

	}
}

