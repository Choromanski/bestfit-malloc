All: mallocdrv mallocdrv2 mydrv remove

mallocdrv: mymalloc.o mallocdrv.o
	gcc -w -o mallocdrv mymalloc.o mallocdrv.o

mallocdrv2: mymalloc.o mallocdrv2.o
	gcc -w -o mallocdrv2 mymalloc.o mallocdrv2.o

mydrv: mymalloc.o mydrv.o
	gcc -w -o mydrv mymalloc.o mydrv.o

mymalloc.o: mymalloc.c mymalloc.h
	gcc -w -c mymalloc.c

mallocdrv.o: mallocdrv.c 
	gcc -w -c mallocdrv.c

mallocdrv2.o: mallocdrv2.c 
	gcc -w -c mallocdrv2.c

mydrv.o: mydrv.c 
	gcc -w -c mydrv.c

remove:
	rm -f *.o

clean:
	rm -f *.o mallocdrv mallocdrv2 mydrv
