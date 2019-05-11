CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS) 

runtest:
	make testme 
	- ./testme
	gcov -b -c testme.c &> testmeresult.out
	cat testmeresult.out

clean:
	rm -f *.o testme.exe testme *.gcov *.gcda *.gcno *.so *.out 
