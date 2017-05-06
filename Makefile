CC=g++ -O2
INCLUDES=./include/Problema.hpp
OBJS=./obj/Problema.o ./obj/main.o


#BINARIOS:
./bin/recubrimiento: ${OBJS}
	${CC} $^ -o $@


#OBJS:
./obj/Problema.o: ./src/Problema.cpp ${INCLUDES}
	${CC} -I./include -c $< -o $@

./obj/main.o: ./src/main.cpp ${INCLUDES}
	${CC} -I./include -c $< -o $@


clean:
	rm -rf ./obj/*
	rm -rf ./bin/*
