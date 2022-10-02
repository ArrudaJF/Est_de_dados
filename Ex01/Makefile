all:
	gcc -Wall -g main.c ponto.c caminho.c -o main -lm

run:
	./main

debug:
	gcc -DDEBUG -Wall main.c ponto.c caminho.c -o main

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./main

clean:
	@rm *.o

