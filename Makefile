NAME = so_long
FUNC = init_map.c\
	   check_map.c\
	   check_finish.c\
	   mlx_tests.c\
	   movements.c\
	   open_images.c\
	   utils.c\
	   free_mem.c\
	   get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c\
	   


INCLUDES	= 	-IHeaders -IHeaders/libft
OBJ		= 	$(FUNC:.c=.o)

MLX_LIB_DIR = minilibx-linux/
MLX_INCLUDE = mlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

%.o: %.c $(MLX_LIB)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -g -c $< -o $@

clean: 
		rm -rf *.o
		rm -rf */*.o

fclean: clean
		rm -rf $(NAME)
		rm -rf ./a.out

re: fclean
	make 
	make clean

.PHONY: all fclean clean re
	