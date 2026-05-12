linux_make:
	gcc source/main.c -o main -I include/ -lm
	gcc tests/tests.c source/main.c -o tests/tests -I include/ -DTESTER -lm
windows_msys2_make:
	gcc source/main.c -o main.exe -I include/ -lm
	gcc tests/tests.c source/main.c -o tests/tests.exe -I include/ -DTESTER -lm
windows_vs_nmake:
	cl source/main.c -I include/
	cl tests/tests.c source/main.c -I include/ -DTESTER -lm