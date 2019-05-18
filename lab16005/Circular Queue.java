import java.util.*;

/**
 * Generic version of the Queue class.
 * @param <T> the type of the value being queued
 */

class Queue <T> {
	private T[] queue;	// array for queue elements
	private int front, // one counterclockwise from front
	            rear, 	// array position of rear element
				capacity;	// capacity of queue array

	/**
	 * Create an empty queue whose initial capacity is cap
	 */
	Queue(int cap) {
		capacity = cap;
		queue = (T []) new Object [capacity];
		front = rear = 0;
	}

	/** 
	 * If number of elements in the queue is 0, return true else return false
	 */
	boolean IsEmpty() {

		if( rear == front )
			return true;	
		else
			return false;
	}

	/**
	 * Add x at rear of queue
	 */
	void Push (T x) throws Exception { 

		if((rear + 1) % capacity == front)
       		{
        	    // if queue full, throw the following message
         	   throw new Exception ("Queue is Full");
       		}	

       		rear = (rear + 1) % capacity;
       		queue[rear] = x;

	}

	/**
	 * Delete front element from queue
	 */
	T Pop() throws Exception {

		T res;

		if( rear == front)
		// if queue is empty, throw the following message
			throw new Exception("Queue is empty. Cannot delete.");

		else
		{	
			res = queue[front]	;
			front = (front +1) %capacity;
		}


		return res;

	}
	
	public String toString() {
		String a = new String();

		a = "Queue : ";

		int num_elem = (rear - front + capacity) % capacity;
	
		for(int i=0; i<num_elem; i++)
			a = a+ queue[(front+i+1)%capacity] + " ";

		a = a + "\nrear=" + rear + ", front=" + front ;

		return a;
	}
}; 

