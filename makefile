
# Variable contains directories which contains source files
SOURCEDIRS=app

SOURCE=${foreach var,${SOURCEDIRS},${wildcard ${var}/*.c}}
HEADER=${foreach var,${SOURCEDIRS},${wildcard ${var}/*.h}}
OBJ=${SOURCE:%.c=%.o}
INCLUDEDIRS=${foreach var,${SOURCEDIRS},-I ${var}}

LIBS      = -lGL -lGLEW -lSDL
BIN       = jakokdybyholub.bin
CFLAGS=-std=c99

all: $(BIN)

clean:
	rm -f ${OBJ} $(BIN)

${BIN}: ${OBJ}
	gcc ${OBJ} -o ${BIN} $(LIBS) 

#compilation rules
%.o: %.c %.h
	gcc -o $@ -c $< -std=c99


run: ${BIN}
	./${BIN}

