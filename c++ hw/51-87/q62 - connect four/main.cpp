#include <iostream>
#include <fstream>
#include <vector>

void connect_Four(std::ifstream& fin);
void input_data(std::ifstream& fin, std::vector<std::vector<int> >& gameBoard);
int det_res(const std::vector<std::vector<int> >& gameBoard);
bool check_conti(const std::vector<std::vector<int> >& gameBoard, int i, int j, const int& player);
bool check_dir(const std::vector<std::vector<int> >& gameBoard, int i, int j, int x_dir, int y_dir);

int main()
{
	std::ifstream	fin;
	int		numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i< numTestCase; ++i)
		connect_Four(fin);
	fin.close();
	
	return 0;

}


void connect_Four(std::ifstream& fin)
{
	std::vector<std::vector<int> > gameBoard(7, std::vector<int>(0) );
	int res=0;

	input_data(fin, gameBoard);

	res = det_res(gameBoard);

	std::cout << res << std::endl;

}

void input_data(std::ifstream& fin, std::vector<std::vector<int> >& gameBoard)
{
	int numInputs;
	int coordBoard;
	int player=1;
	fin >> numInputs;
	
	for(int i=0; i<numInputs; ++i)
	{
		fin >> coordBoard;
		if( player%2 ==1 )
			gameBoard[coordBoard-1].push_back(1);
		else
			gameBoard[coordBoard-1].push_back(2);	

		++player;
	}

}

int det_res(const std::vector<std::vector<int> >& gameBoard)
{

	for(int i=0; i<gameBoard.size(); ++i)
	{
		for(int j=0; j<gameBoard[i].size(); ++j)
		{
			if( check_conti(gameBoard, i, j, gameBoard[i][j]) )
				return gameBoard[i][j];
		}
	}

	return 0;
}

bool check_conti(const std::vector<std::vector<int> >& gameBoard, int i, int j, const int& player)
{
//std::cout << i << " " << j << std::endl;
	if(check_dir(gameBoard, i, j, -1, 1) || check_dir(gameBoard, i, j, 0, 1)
 	|| check_dir(gameBoard, i, j,  1, 1) || check_dir(gameBoard, i, j, 1, 0) )
		return true;
	else 
		return false;
}

bool check_dir(const std::vector<std::vector<int> >& gameBoard, int i, int j, int x_dir, int y_dir)
{

	for(int cnt=0; cnt<4; ++cnt)
	{
		if( (i+x_dir*cnt < 0)||(gameBoard.size() < i+x_dir*cnt+1 )||( gameBoard[i+x_dir*cnt].size() < j+y_dir*cnt+1 ) )
			return false;
		if(gameBoard[i][j] != gameBoard[i+x_dir*cnt][j+y_dir*cnt])
			return false;
	}
	return true;
}

