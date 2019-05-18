// Lab 010	: Natural Merge
// Name : 조정근
// Student ID : 20153235

import java.util.*;


class NaturalMerge {
	int noe;  // the number of elements
	private int[] inputArray; // input array 
	int[] outputArray; // output array 


	NaturalMerge() { 
		// Graph constructor. 
		noe = 0;
	}

	void Init(int [] arr, int n) { 
		noe = n;
		inputArray = new int[noe];
		System.arraycopy(arr, 0, inputArray, 0, n);

		outputArray = new int[noe];
	}

	void Merge() { 
		
		int m = 0;
		
		for(int i=1; i<noe; ++i)
			if( inputArray[i-1] > inputArray[i] )
				m = i;

		System.out.println("n = " + noe + ", m = " + m);

		int x_pos = 0;
		int y_pos = m; 
		int out_pos = 0;
		while( x_pos < m && y_pos < noe )
		{
			if( inputArray[x_pos] < inputArray[y_pos])
				outputArray[out_pos++] = inputArray[x_pos++];
				
			else if( inputArray[x_pos] > inputArray[y_pos] )
				outputArray[out_pos++] = inputArray[y_pos++];
				
			else // inputArray[x_pos] == inpuArray[y_pos] 
			{
				outputArray[out_pos++] = inputArray[x_pos++];
				outputArray[out_pos++] = inputArray[y_pos++];
			}
		}
		
		for( ; x_pos < m; ++x_pos)
			outputArray[out_pos++] = inputArray[x_pos];
	
		for( ; y_pos<noe; ++y_pos)
			outputArray[out_pos++] = inputArray[y_pos];


	}
}


