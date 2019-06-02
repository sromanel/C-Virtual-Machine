objects = main.o toArray.o execute.o exeFunctions.o print.o prntFunctions.o
eseguibile = VM
cflags = -g3 -fsanitize=address -fsanitize=undefined -std=gnu89 -pedantic-errors -Wall -Wextra
libs = -lm

$(eseguibile) : $(objects)
	gcc $(cflags) -o $(eseguibile) $(objects) $(libs)

clean:
	rm $(eseguibile)  $(objects)

.c.o :
	gcc -c $(cflags) $<
.h.c :
	touch $<
