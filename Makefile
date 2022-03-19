CC = gcc
FLAGS = 
FILES = memory.c chunk.c main.c
HEADERS = memory.h chunk.h
OUTNAME = a.out

$(OUTNAME) : $(FILES) $(HEADERS)
	$(CC) $(FLAGS) -o a.out $(FILES)

run : $(OUTNAME)
	./$(OUTNAME)
