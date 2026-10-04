all:
	nasm -f win64 src/math.asm -o src/math.o
	gcc -Iinclude src/core.c src/rasterizer.c src/renderer.c src/colors.c src/2d.c src/3d.c src/zbuffer.c src/input.c test.c src/math.o -o nv_app -O3 -lgdi32 -luser32 -lm

clean:
	rm -f src/*.o nv_app.exe nv_app