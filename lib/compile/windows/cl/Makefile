#-DBUILDING_EXAMPLE_DLL

all:
	cl /DBUILDING_MYLIB /LD example.cc
	cl main.cc /link example.lib

clean:
	-rm *.dll *.obj *.lib *.exp *.exe