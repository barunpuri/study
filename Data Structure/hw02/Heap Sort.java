import java.util.*;

// Name : 조정근
// Student ID : 20153235 


class HeapSort {
	int [] heap;	// Heap Array
	int heapSize;	// number of elements in the Heap
	int capacity;	// Array size

	HeapSort(int cap) {
		capacity = cap;
		heap = new int[capacity + 1];
		heapSize = 0;
	}

	public String toString() { 
		// Convert heap array into a string
		String str;
		str = "Heap : - ";

		for(int i = 1; i <= heapSize; i++)
			str +=  heap[i] + "  ";

		return str;
	}

	void  Init(int [] es, int n) {	
		// fill the heap array by the input
		// we need to create heap structure when we call Sort()
		heapSize = n;
		for(int i = 1; i <= n; i++)
			heap[i] = es[i];
	}


	void  Adjust(int root, int n) {	
		// adjust binary tree with root "root" to satisfy heap property.
		// The left and right subtrees of "root" already satisfy the heap
		// property. No node index is > n.

		int ptr = root;
		int child = ptr *2;
		
		while( child <= n )
		{
			
			if( child + 1 <= n && heap[child] < heap[child+1] )
				child = child +1 ;
				
			if( heap[ptr] < heap[child] ) 
			{	
				int temp = heap[ptr];
				heap[ptr] = heap[child];
				heap[child] = temp;
			}
			ptr = child;
			child = ptr*2;
		}
	}

	void  Sort() {	
		// sort heap[1:n] into nondecreasing order
		
		for(int i=heapSize; i>=1; --i)
			Adjust(i, heapSize);
		
		System.out.println(this);

		int maxheapsize = heapSize;

		while( maxheapsize > 1)
		{
		//System.out.println(this);
			int temp = heap[1];
			heap[1] = heap[maxheapsize];
			heap[maxheapsize] = temp;
		//System.out.println(this);
			maxheapsize -= 1;
			
			Adjust(1, maxheapsize);
		
			System.out.println(this);
		}
		
	}
}

