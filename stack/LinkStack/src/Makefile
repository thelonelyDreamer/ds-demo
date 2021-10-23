

linkstackheadsample:linkstackheadsample.o liblinkstackhead.a
	gcc linkstackheadsample.o liblinkstackhead.a -o linkstackheadsample
linkstackheadsample.o:linkstackheadsample.c
	gcc -c linkstackheadsample.c -o linkstackheadsample.o
	
liblinkstackhead.a: linkstackhead.o
	ar -rcs liblinkstackhead.a linkstackhead.o
linkstackhead.o:linkstackhead.c 
	gcc -c linkstackhead.c -o linkstackhead.o
.PHONY:
clean:
	rm -fr *.o *.a