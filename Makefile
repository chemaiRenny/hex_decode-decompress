cc=gcc

all:main client

#main file(combination of decode and decompress)

main.o:main.c
	$(cc) -c main.c -lz

main:main.o
	$(cc) main.o -o main -Wall -Wextra -std=c18 -pedantic -lz

#make client
client:client.c
	$(cc) client.c -o client -Wall -Wextra -std=c18 -pedantic 


decompress:decmp #make decompress standalone

#clean files
files="main client"

clean:
	rm *.o $(files) 
