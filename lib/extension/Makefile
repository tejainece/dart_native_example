#"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64

all:
	cl /DDART_SHARED_LIB /I"C:/Program Files/Dart/dart-sdk/include" /LD extension.cpp extension_dllmain.win.cpp "C:/Program Files/Dart/dart-sdk/bin/dart.lib"

clean:
	-rm *.dll *.obj *.exp *.lib
