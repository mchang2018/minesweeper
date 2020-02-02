mine_sweeper.out: boards.o move.o win.o input.o main.o
	gcc -g -Wall -Werror -o mine_sweeper.out boards.o move.o win.o input.o main.o

boards.o: boards.c boards.h struct_def.h
	gcc -g -Wall -Werror -c boards.c

move.o: move.c move.h struct_def.h input.h
	gcc -g -Wall -Werror -c move.c

win.o: win.c win.h struct_def.h
	gcc -g -Wall -Werror -c win.c

input.o: input.c input.h
	gcc -g -Wall -Werror -c input.c

main.o: main.c boards.h struct_def.h move.h win.h
	gcc -g -Wall -Werror -c main.c

clean:
	rm -fr *.o *.out