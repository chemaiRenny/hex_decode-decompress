# Hex decode and decompress encoded and compressed string
what a word play!!

This is program decodes and decompresses hex-encode compressed string from a server through a client

## Requirements
- make 
- c compiler preferably gcc. Using another compiler will require editing of the makefile
## How it works

The main file combines the hex_decode and  decmp files which decode and decompress hex-encoded string respectively

The makefile  compiles the main and the client files producing two outputs main and 
client files

- command: 
- make all

Independent hex-decoder and gzip decompressor and main objects can be also produced  

- make hex_decode.o, make decmp.o and make main.o

Cleaning object and executable files can be done using 

- make clean 

Regards
