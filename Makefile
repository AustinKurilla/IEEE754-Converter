# "PHONY" targets are ones that do not result in a new file
.PHONY : clean

#### Main executable program:
FP: main.o fp.o fp.h
	gcc -Wall -Wextra -O2 main.o fp.o -o FP -lm

main.o: main.c fp.h
	gcc -c -Wall -Wextra main.c -o main.o -lm

fp.o: fp.c fp.h
	gcc -c -Wall -Wextra fp.c -o fp.o -lm

clean:
	rm *.o FP


