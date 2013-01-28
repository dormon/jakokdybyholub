# Variable contains directories which contains source files
# dont forget / !!!
SOURCEDIRS=app/ data/ shader/ standard/ window/

DIR0:=${SOURCEDIRS}
DIRA0:=${foreach var,${DIR0},${dir ${wildcard ${var}*/}}} ${DIR0}
DIR1:=${sort ${DIRA0}}
DIRA1:=${foreach var,${DIR1},${dir ${wildcard ${var}*/}}} ${DIR1}
DIR2:=${sort ${DIRA1}}
DIRA2:=${foreach var,${DIR2},${dir ${wildcard ${var}*/}}} ${DIR2}
DIR3:=${sort ${DIRA2}}
DIRA3:=${foreach var,${DIR3},${dir ${wildcard ${var}*/}}} ${DIR3}
DIR4:=${sort ${DIRA3}}
SRCDIR=${DIR4}

SOURCE=${foreach var,${SRCDIR},${wildcard ${var}/*.cpp}}
HEADER=${foreach var,${SRCDIR},${wildcard ${var}/*.hpp}}
OBJ=${SOURCE:%.cpp=%.o}
INCLUDEDIRS=${foreach var,${SRCDIR},-I ${var}}

LIBS      = -lGL -lGLEW -lSDL
BIN       = jakokdybyholub.bin
CFLAGS    = -std=c++98 ${INCLUDEDIRS}
CPP       = g++

all:${BIN}

#everything
${BIN}: ${OBJ}
	${CPP} ${OBJ} -o ${BIN} ${LIBS} -g


#compilation rules
%.o: %.cpp %.hpp
	${CPP} -o $@ ${CFLAGS} -c $< -g

#cleanin rule
clean:
	rm -f ${OBJ} $(BIN)

run: ${BIN}
	./${BIN}

mem: ${BIN}
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --suppressions=file.supp ./${BIN}
