#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
//시험점수

void q24(std::ifstream& fin);
void print(std::vector<int>& Ints, int numInts);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q24(fin);
	fin.close();
	
	return 0;

}

void q24(std::ifstream& fin)
{
	int numInts;
	fin >> numInts;
	
	std::vector<int> Ints;
	int temp;
	for(int i=0; i<numInts; ++i)
	{
		fin >> temp;
		Ints.push_back(temp);
	}
	
	std::sort( Ints.begin(), Ints.end() ); //#include <algorithm>

	print(Ints, numInts);

}

void print(std::vector<int>& Ints, int numInts)
{	
	int count;
	for(int i=0; i<numInts; ++i)
	{	
		
		count = 1;
		std::cout << Ints[i] << " ";
		for(int j=i+1; i<numInts; ++j)
		{
			if( (Ints[i]==Ints[j])&&(j!=numInts) )
			{
				count += 1;
				Ints[j]=-1;
			}
			else
			{	
				std::cout << count << " ";
				i += count -1 ;			
				break;
			}
		}
	}
	std::cout << std::endl;	

}




