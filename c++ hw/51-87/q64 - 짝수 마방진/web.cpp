#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

void magic_square_2k(std::ifstream& fin);
void swap(int &num1,int &num2);
void print_mbj(int size, int mbj[][MAX_SIZE]);
void make_odd(int size, int mbj[][MAX_SIZE]);
void make_four(int size, int mbj[][MAX_SIZE]);
void make_even(int size,int mbj[][MAX_SIZE]);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		magic_square_2k(fin);
	fin.close();
	
	return 0;
}


void magic_square_2k(std::ifstream& fin)
{
	int size;
	fin >> size;
	int mbj[MAX_SIZE][MAX_SIZE];

	if ( size % 2 == 0 )
		if ( size % 4 == 0 ) 
			make_four(size,mbj);
		else 
			make_even(size,mbj);
	else
		make_odd(size,mbj);

	print_mbj(size,mbj);
}

// 단순히 두 수를 swap해주는 함수
void swap(int &num1,int &num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}
// 마방진 출력함수
void print_mbj(int size, int mbj[][MAX_SIZE])
{
	int i, j;
	for ( i = 0 ; i < size ; i++ ){
		for ( j = 0 ; j < size ; j++ ){
			std::cout << mbj[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
// 홀수 마방진 만드는 함수
void make_odd(int size, int mbj[][MAX_SIZE])
{
	int number;
	int row = 0;			//시작 위치 가로 세로
	int col = (int)size/2;

	for(number = 1 ; number <=size*size ; number++){
		mbj[row][col] = number;
		if ( number%size == 0 ){	// size의 배수일 경우
			row++;
		}else{						// 그 외의 경우
			row--;
			col++;
			if ( row < 0 ) row = size-1;	// 배열범위를 벗어나는 경우
			if ( col > size-1 ) col = 0;
		}
	}
}
// 4의배수 마방진 만드는 함수
void make_four(int size, int mbj[][MAX_SIZE])
{
	int number = 1;
	int count = size/4;
	int i, j;
	int row;
	for ( i = 0 ; i < size ; i++ ){		// 숫자를 순차적으로 입력
		for ( j = 0 ; j < size ; j++ ){
			mbj[i][j] = number;
			number++;
		}
	}
	for ( row = 0 ; row < count ; row++ ){	// 스왑실시
		int col1 = size/4;
		int col2 = size - size/4 - 1;
		for ( i = 0 ; i < size/2 ; i++ ){
			swap(mbj[row][col1],mbj[size-1-row][col2]);
			swap(mbj[col1][row],mbj[col2][size-1-row]);
			col1++;
			col2--;
		}
	}
}


void make_even(int size,int mbj[][MAX_SIZE])
{
	int tsize = size/2;
	int temp[MAX_SIZE][MAX_SIZE];		//size/2차 마방진 저장
	make_odd(tsize,temp);

	int set1[tsize][tsize];		// 오른쪽 위
	int set2[tsize][tsize];		// 오른쪽 아래
	int set3[tsize][tsize];		// 왼쪽 위
	int set4[tsize][tsize];		// 왼쪽 아래
	int i,j;
	for ( i = 0 ; i < tsize ; i++ ){	// 각 부분에 숫자를 입력
		for ( j = 0 ; j < tsize ; j++ ){
			if ( i == tsize/2 ){
				if ( j >= 1 && j <= ((int)size/4)){
					set1[i][j] = 3 * size * size / 4;
					set2[i][j] = 0;
				}else{
					set1[i][j] = 0;
					set2[i][j] = 3 * size * size / 4;
				}
			}else{ 
				if ( j < ((int)size/4) ){
					set1[i][j] = 3 * size * size / 4;
					set2[i][j] = 0;
				}else{
					set1[i][j] = 0;
					set2[i][j] = 3 * size * size / 4;
				}
			}
		}
	}
	for ( i = 0 ; i < tsize ; i++ ){
		for ( j = 0 ; j < tsize ; j++ ){
			if ( j >= tsize - (size/4) + 1 && j < tsize ) {
				set3[i][j] = 2 * size * size / 4;
				set4[i][j] = 1 * size * size / 4;
			}else{
				set3[i][j] = 1 * size * size / 4;
				set4[i][j] = 2 * size * size / 4;
			}
		}
	}
	for ( i = 0 ; i < size ; i++ ){		// 각부분과 홀수 마방진의 결합
		for ( j = 0 ; j < size ; j++ ){
			if ( i < size/2 && j < size/2 ) mbj[i][j] = temp[i][j] + set1[i][j];
			else if ( i < size/2 && j < size ) mbj[i][j] = temp[i%tsize][j%tsize] + set3[i%tsize][j%tsize];
			else if ( i < size && j < size/2 ) mbj[i][j] = temp[i%tsize][j%tsize] + set2[i%tsize][j%tsize];
			else mbj[i][j] = temp[i%tsize][j%tsize] + set3[i%tsize][j%tsize];
		}
	}
}


