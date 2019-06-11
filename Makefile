objects = main.o toArray.o execute.o exeFunctions.o print.o prntFunctions.o
executable = VM
cflags = -g3 -fsanitize=address -fsanitize=undefined -std=gnu89 -pedantic-errors -Wall -Wextra
libs = -lm

$(executable) : $(objects)
	gcc $(cflags) -o $(executable) $(objects) $(libs)

clean:
	rm $(executable)  $(objects)

.c.o :
	gcc -c $(cflags) $<
.h.c :
	touch $<
