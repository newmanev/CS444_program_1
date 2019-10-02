CC = gcc
CFLAGS = -Wall -std=c99

all: program_2 program_3 program_4 program_5

program_2: program_2.c
	$(CC) -o compiled_2 program_2.c -g $(CFLAGS)

program_3: program_3.c
	$(CC) -o compiled_3 program_3.c -g $(CFLAGS)

program_4: program_4.c
	$(CC) -o compiled_4 program_4.c -g $(CFLAGS)

program_5: program_5.c
	$(CC) -o compiled_5 program_5.c -g $(CFLAGS)

clean:
	rm -f compiled_2 compiled_3 compiled_4 compiled_5 JUNK.txt
