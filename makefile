
# Variable contains directories which contains source files
# dont forget / !!!
SOURCEDIRS=app/ data/

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

SOURCE=${foreach var,${SRCDIR},${wildcard ${var}/*.c}}
HEADER=${foreach var,${SRCDIR},${wildcard ${var}/*.h}}
OBJ=${SOURCE:%.c=%.o}
INCLUDEDIRS=${foreach var,${SRCDIR},-I ${var}}

LIBS      = -lGL -lGLEW -lSDL
BIN       = jakokdybyholub.bin
CFLAGS=-std=c99 ${INCLUDEDIRS}

#everything
all: $(BIN)

#cleanin rule
clean:
	rm -f ${OBJ} $(BIN)

#bin rule
${BIN}: ${OBJ}
	gcc ${OBJ} -o ${BIN} $(LIBS) 

#compilation rules
%.o: %.c %.h
	gcc -o $@ -c $<


run: ${BIN}
	./${BIN}

