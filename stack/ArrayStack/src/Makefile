test:astack.o test.o
	gcc test.o astack.o -o test
	test
astack.o:astack.c
	gcc -c astack.c -o astack.o
test.o:test.c
	gcc -c test.c -o test.o

astack.a:astack.o
	ar rcs astack.a astack.o

