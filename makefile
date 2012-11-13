
# Variable contains directories which contains source files
SOURCEDIRS=app data

SOURCE=${foreach var,${SOURCEDIRS},${wildcard ${var}/*.c}}
HEADER=${foreach var,${SOURCEDIRS},${wildcard ${var}/*.h}}
OBJ=${SOURCE:%.c=%.o}
INCLUDEDIRS=${foreach var,${SOURCEDIRS},-I ${var}}

LIBS      = -lGL -lGLEW -lSDL
BIN       = jakokdybyholub.bin
CFLAGS=-std=c99

#everything
all: $(BIN)

#cleanin rule
clean:
	rm -f ${OBJ} $(BIN)

<<<<<<< HEAD
#binary rule dormon
=======
#bin rule
>>>>>>> 2978409220c8eefce0e802d726a192fa6530d465
${BIN}: ${OBJ}
	gcc ${OBJ} -o ${BIN} $(LIBS) 

#compilation rules
%.o: %.c %.h
	gcc -o $@ -c $< -std=c99


run: ${BIN}
	./${BIN}

