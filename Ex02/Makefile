all:
	gcc main.c jogo.c catalogo.c -o main -lm

run:
	./main

debug:
	gcc -DDEBUG -Wall main.c jogo.c catalogo.c -o main

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./main

clean:
	@rm *.o

