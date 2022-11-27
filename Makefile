NAME = cub3d



all : lib
	clang src/* utils/*  -I./includes/ -Lminilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit -O0 -g3 -lm -lz
clean:
	make -C minilibx_opengl_20191021/ clean
	rm -rf a.out*
lib:
	make -C minilibx_opengl_20191021/ all 

