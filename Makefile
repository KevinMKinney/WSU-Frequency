.SUFFIXES: .c .o
CCFLAGS = -std=c99 -pedantic -Wall
OBJS = freq.o func.o
EXEC = freq

build: ${OBJS}
	gcc ${CCFLAGS} -o ${EXEC} ${OBJS}
	
${EXEC}.o: freq.c func.h
	gcc ${CCFLAGS}  -c freq.c
	
func.o: func.c func.h
	gcc ${CCFLAGS}  -c func.c
	
run: ${EXEC}
	./${EXEC}
	
clean:
	rm -f ${EXEC} ${OBJS}
