#project2: reservation.o passenger.o PTHash.o PSHash.o PHash.o main.o
#	g++ -o project2 reservation.o passenger.o PTHash.o PSHash.o PHash.o main.o

project2: PTHash.o PSHash.o PHash.o main.o
	g++ -o project2 PTHash.o PSHash.o PHash.o main.o
	
#reservation.o: reservation.cpp reservation.h
#	g++ -c reservation.cpp
	
#passenger.o: passenger.cpp passenger.h
#	g++ -c passenger.cpp

PTHash.o: PTHash.cpp PTHash.h
	g++ -c PTHash.cpp
	
PSHash.o: PSHash.cpp PSHash.h
	g++ -c PSHash.cpp
	
PHash.o: PHash.cpp PHash.h
	g++ -c PHash.cpp
	
#main.o: main.cpp PTHash.h PSHash.h PHash.h passenger.h
#	g++ -c main.cpp

main.o: main.cpp PTHash.h PSHash.h PHash.h
	g++ -c main.cpp
	
clean:
	rm *.o project2