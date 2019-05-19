20153235
조정근


**************************
HOWTO install ncurses 
**************************
CentOS7:
	sudo yum install ncurses-dev
Ubuntu:
	sudo apt-get install libncurses5-devel libncursesw5-devel


**************************
FILE INFO.
**************************
main.cpp	a simple source file based on ncurses
Makefile	a make file
life_answer	an execution file (answer, compiled on CentOS7 amd64)
data/		data folder containing several examples


**************************
HOWTO Compile your code
**************************
make


**************************
HOWTO test your program
**************************
./life data/0.txt
./life data/pulsar.txt


**************************
HOWTO check the answer
**************************
./life_answer data/0.txt
./life_answer data/pulsar.txt

