
all:
	g++ -c -DBUILDING_MYLIB example.cc
	g++ -shared -o example.dll example.o -Wl,--out-implib,libexample.a
	g++ main.cc example.dll -o main

clean:
	-rm *.dll *.o *.a *.exe