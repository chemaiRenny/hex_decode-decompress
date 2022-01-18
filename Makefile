cc=gcc

all:main client

#main file(combination of decode and decompress)
#object files

main.o:main.c
	$(cc) -c main.c 

hex_decode.o:hex_decode.c 
	$(cc) -c hex_decode.c

decmp.o:decmp.c main.h
	$(cc) -c  decmp.c

main:main.o hex_decode.o decmp.o
	$(cc) main.o  hex_decode.o decmp.o -o main -Wall -Wextra -std=c18 -pedantic -lz

#make client
client:client.c
	$(cc) client.c -o client -Wall -Wextra -std=c18 -pedantic 


decompress:decmp #make decompress standalone

#clean files
files="main client"

clean:
	rm *.o "$(files)"
