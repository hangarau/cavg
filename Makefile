all: compile-linux-mac compile-windows-32bit compile-windows-64bit

compile-linux-mac:
	gcc src/Main.c -o dist/cavg

compile-windows-32bit:
	i686-w64-mingw32-gcc -o dist/cavg\ \(32-bit\).exe src/Main.c

compile-windows-64bit:
	x86_64-w64-mingw32-gcc -o dist/cavg\ \(64-bit\).exe src/Main.c