CC		=	clang

CFLAGS	=  -O3 -g #-Wall -Wextra -Werror

LDFLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit -lm -lz

SRC_DIR = ./src

UTILS_DIR = ./utils

SRC = cub3d_algo	\
	   globals		\
	   hook			\
	   hook_2		\
	   init			\
	   init2		\
	   init3		\
	   init_1_1		\
	   init_2_1		\
	   init_algo	\
	   main			\
	   map_validate	\
	   minimap_draw	\
	   raycasting	\
	   texture_info

UTILS = free					\
		 ft_atoi				\
		 ft_list				\
		 ft_max					\
		 ft_memcmp				\
		 get_next_line			\
		 get_next_line_utils	\
		 split

HEADER =	./includes/cub3d.h			\
			./includes/printf_colors.h	\
			./src/utils/get_next_line.h		

OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:=.o))

UTILS_OBJ_DIR = utils_obj
UTILS_OBJ = $(addprefix $(UTILS_OBJ_DIR)/,$(UTILS:=.o))

NAME		=	cub3D

.PHONY:	all clean fclean re

all:	$(OBJ_DIR) $(UTILS_OBJ_DIR)
	make -C minilibx_opengl_20191021/ all
	$(MAKE) -j $(NAME)


clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(UTILS_OBJ_DIR)

fclean:	clean
	rm -rf $(NAME)
	make -C minilibx_opengl_20191021/ clean

re: fclean all

$(OBJ_DIR):
	mkdir -p $@

$(UTILS_OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c Makefile
	$(CC) $(CFLAGS) $< -c -o $@ 

$(UTILS_OBJ_DIR)/%.o: $(SRC_DIR)/$(UTILS_DIR)/%.c Makefile
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME):	$(UTILS_OBJ) $(OBJ) $(HEADER)
	$(CC) $(LDFLAGS) $(OBJ) $(UTILS_OBJ) -o $@

