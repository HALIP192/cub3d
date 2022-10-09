all : lib
	clang cub3d_algo.c utils/* src/globals.c -Lminilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit -O0 -g3 -lm -lz
clean:
	make -C minilibx_opengl_20191021/ clean
	rm -rf a.out*
lib:
	make -C minilibx_opengl_20191021/ all 

