#
CC=g++
RM=rm -f
#
#CFLAGS = -c -Wall -I/usr/include/mysql 
#LFLAGS = -L/usr/lib/mysql -lmysqlclient
CFLAGS = -c -Wall -std=c++11
LFLAGS = 


all: studentMain

studentMain: studentMain.o student.o printMeFirst.o
	$(CC) studentMain.o student.o printMeFirst.o -o studentMain $(LFLAGS)

studentMain.o: studentMain.cpp 
	$(CC) $(CFLAGS) studentMain.cpp  
	
student.o: student.cpp  student.h
	$(CC) $(CFLAGS) student.cpp  

printMeFirst.o: printMeFirst.cpp printMeFirst.h
	$(CC) $(CFLAGS) printMeFirst.cpp  


clean:
	$(RM) *.o studentMain

run:
	./studentMain



