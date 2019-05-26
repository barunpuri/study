#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const int MAX_SIZE = 100;

void q42(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<char>& room, int size);
int find_room (std::vector<char>& room, int row, int col, std::vector<int>& sizeOfRooms);
int count(std::vector<char>& room, int loc, int col);
int det_add(std::vector<char>& room, int loc, std::vector<int>& coords);
void print(std::vector<int> sizeOfRooms);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q42(fin);
	fin.close();
	
	return 0;

}

void q42(std::ifstream& fin)
{
	int row, col;
	fin >> col >> row;

	int maxSum=0;
	std::vector<char> room;

	inputData(fin, room, row*col);

	std::vector<int> sizeOfRooms;

	find_room(room, row, col, sizeOfRooms);

	sort( sizeOfRooms.begin(), sizeOfRooms.end() );

	print(sizeOfRooms);
}

void inputData(std::ifstream& fin, std::vector<char>& room, int size)
{
	char data;
	for(int i=0; i<size; ++i )
	{
		fin >> data;
		room.push_back(data);
	} 

}

int find_room (std::vector<char>& room, int row, int col, std::vector<int>& sizeOfRooms)
{
	for(int i=0; i<row*col; ++i )
	{
		if( room[i] == 'O')
			sizeOfRooms.push_back(count(room, i, col));
	}
}

int count(std::vector<char>& room, int loc, int col)
{	
	std::vector<int> coords;

	int temp=1;
	
	coords.push_back(loc);

	room[loc] = 'X';

		while(coords.size()!=0)
		{	
			int loc = coords[0];
			coords.erase(coords.begin());

			temp += det_add( room, loc - col, coords); //상
			temp += det_add( room, loc + 1, coords);	//우
			temp += det_add( room, loc + col, coords);  //하
			temp += det_add( room, loc - 1, coords);  //좌
	
		}
		
	return temp;
}

int det_add(std::vector<char>& room, int loc, std::vector<int>& coords)
{	
	if( room[loc]=='O' )
	{
		coords.push_back(loc);
		room[loc] = 'X';
		return 1;
	}
	return 0;
}

void print(std::vector<int> sizeOfRooms)
{
	std::cout << sizeOfRooms.size() << std::endl;

	for(int i=0; i<sizeOfRooms.size(); ++i)
		std::cout << sizeOfRooms[sizeOfRooms.size()-1-i] << " ";

	std::cout << std::endl;
}
