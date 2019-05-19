#include <clocale>
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "lifegame.h"

int main(int argc, char* argv[])
{	
	if (argc != 2)
	{
		std::cout << "Usage: life <0th_gen.txt>" << std::endl;
		return	-1;
	}

	std::ifstream fin;
	
	fin.open(argv[1]);	
	lifegame game; 
	
	game = lifegame(fin);
	
	fin.close();

	WINDOW *win1;
	WINDOW *win2;

//	int x_term;
//	int y_term;

	int x_dir=0;
	int y_dir=0;

	setlocale(LC_CTYPE, "");		// for using UNICODE

	initscr();
	curs_set(0);
	start_color();
	erase();
	
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	
	// RED GREEN BLUE MAGENTA CYAN YELLOW BLACK WHITE
	
	char ch;
	while (true)
	{
		clear();
		
//////////////////border
		if(game.getRow() <= 18)
			resize_term(24, 2*game.getCol()+40);
		else
			resize_term(game.getRow()+6, 2*game.getCol()+40);
		mvprintw(1,2, "0.0");
		mvprintw(1,2*game.getCol()+4, "\u2192 y");
		mvprintw(game.getRow()+2, 2, "\u2193\n  x");
		attron(COLOR_PAIR(5));
		border('X','X','x','x','.','.','\'','\'');
		attroff(COLOR_PAIR(5));
		refresh();

//////////////////win 1
		win1 = newwin(game.getRow()+2, 2*game.getCol()+3, 2, 4);
		wbkgd(win1, COLOR_PAIR(0) );

		for( int i=0; i<game.getRow(); ++i)
		{
			for( int j=0; j<game.getCol(); ++j)
			{
				
				if( game(i,j) == 'O' )
				{	wattron(win1, COLOR_PAIR(game.color(i,j)%7));
					mvwprintw(win1, i+1, 2*j+2, "\u2B1B");
					wattroff(win1, COLOR_PAIR(game.color(i,j)%7));
				}
				else
				{
					mvwprintw(win1, i+1, 2*j+2, "\u2B1C");
				}
				
			}
		}

		wattron(win1, COLOR_PAIR(6));
		wborder(win1, '|','|','-','-','+','+','+','+');
		wattroff(win1, COLOR_PAIR(6));

//////////////////cursor
		wattron(win1, COLOR_PAIR(1));
		
		if( game.getRow() != 0 )
		{
		if( game(x_dir,y_dir) == 'X' )
			mvwprintw(win1, x_dir+1, 2*y_dir+2, "\u2B1C");
		else
			mvwprintw(win1, x_dir+1, 2*y_dir+2, "\u2B1B");
		}
		wattroff(win1, COLOR_PAIR(1));

		wrefresh(win1);

//////////////////win2  status
		win2 = newwin(20, 24, 2, 2*game.getCol()+11);
		wbkgd(win2, COLOR_PAIR(0) );
		wattron(win2, COLOR_PAIR(2));
		mvwprintw(win2, 1,1,"*** status ***"); 
		mvwprintw(win2, 7,1,"*** command ***");
		mvwprintw(win2, 13,1,"*** pointer ***");
		wattroff(win2, COLOR_PAIR(2));

		mvwprintw(win2, 2,1,"x_location : ");
		mvwprintw(win2, 2,20,"%d", x_dir);
		mvwprintw(win2, 3,1,"y_location : ");
		mvwprintw(win2, 3,20,"%d", y_dir);
		mvwprintw(win2, 4,1,"generation : ");
		mvwprintw(win2, 4,20,"%d", game.getGeneration());
		mvwprintw(win2, 5,1,"number of cells : ");
		mvwprintw(win2, 5,20,"%d", game.count_living_cells());

		mvwprintw(win2, 8,1, "q : quit\n o : open file\n n : next generation\n s : save");
		
		mvwprintw(win2, 14,1,"h : move left\n j : move down\n k : move up\n l : move right\n t : change state");

		wattron(win2, COLOR_PAIR(3));
		wborder(win2, '|','|','-','-','+','+','+','+');
		wattroff(win2, COLOR_PAIR(3));
		wrefresh(win2);
		


//////////////////option
		noecho();
		ch = getch();

		if (ch == 'q' || ch == 'Q')			
			break;
		else if (ch == 'o' || ch == 'O')
		{
			char	str[512] ;

			clear();
			echo();
			printw("Load file: ");
			getstr(str);

			fin.open(str);
			if(fin.fail()){
				mvprintw(1,0,"Cannot open a file:\nPress any key to continue");		
				getch();
				clear();
				refresh();
				continue;
			}

			game = lifegame(fin);
			fin.close();	

			refresh();
			noecho();
		}
		else if( ch== 'n' || ch == 'N' )
		{
			game.next();
		}
		else if( ch== 's' || ch == 'S' )
		{
			char str[512];

			clear();
			echo();
			printw("Save file: ");
			getstr(str);

			std::ofstream fout;
			fout.open(str); //rewrite
			fout << game.getRow() << " " << game.getCol() << std::endl;
			for(int i=0; i<game.getRow(); ++i)
			{			
				for(int j=0; j<game.getCol(); ++j)
					fout << game(i,j);
				fout << std::endl;
			}
			fout.close();

			clear();
			refresh();
			noecho();
		}
		else if( ch== 'h' || ch == 'H' )
		{
			//좌 
			if( y_dir != 0 )
				y_dir += -1;
	
		}
		else if( ch== 'j' || ch == 'J' )
		{
			//하 
			if( x_dir != game.getRow()-1 )
				x_dir += 1;

		}
		else if( ch== 'k' || ch == 'K' )
		{
			//상  
			if( x_dir != 0 )
				x_dir += -1;

		}
		else if( ch== 'l' || ch == 'L' )
		{
			//우  
			if( y_dir != game.getCol()-1 )
				y_dir += 1;
		}
		else if( ch== 't' || ch == 'T' )
		{
			//O->X, X->O	
			if( game(x_dir,y_dir) == 'O' )
				game(x_dir,y_dir) = 'X';
			else
				game(x_dir,y_dir) = 'O';
		}

		delwin(win1);
		delwin(win2);

	}
	endwin();

	return 0;
}
