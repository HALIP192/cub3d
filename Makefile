all :
	clang cub3d_algo.c utils/get_next_line.c utils/get_next_line_utils.c utils/split.c utils/ft_list.c utils/ft_atoi.c -Lminilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit -O0 -g3 -lm -lz
clean:
	make -C minilibx_opengl_20191021/ clean
	rm -rf a.out*
lib:
	make -C minilibx_opengl_20191021/ all 

