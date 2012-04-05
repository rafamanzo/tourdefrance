COMPILER_FLAGS=-ansi -Wall -pedantic -g
.PHONY: clean

tourdefrance: main.o input.o checkpoint.o estrada.o ciclista.o placar.o
	gcc ${COMPILER_FLAGS} -lpthread -lm main.o input.o checkpoint.o estrada.o ciclista.o placar.o -o tourdefrance

main.o: main.c input.h ciclista.h
	gcc ${COMPILER_FLAGS} -c main.c
	
input.o: input.c input.h checkpoint.h estrada.h
	gcc ${COMPILER_FLAGS} -c input.c
	
checkpoint.o: checkpoint.c checkpoint.h
	gcc ${COMPILER_FLAGS} -c checkpoint.c
	
estrada.o: estrada.c estrada.h
	gcc ${COMPILER_FLAGS} -c estrada.c
	
ciclista.o: ciclista.c ciclista.h checkpoint.h estrada.h placar.h
	gcc ${COMPILER_FLAGS} -c ciclista.c
	
placar.o: placar.c placar.h
	gcc ${COMPILER_FLAGS} -c placar.c
	
clean:
	rm *.o tourdefrance
