NAME = so_long
FUNC = init_map.c\
	   check_map.c\
	   check_finish.c\
	   so_long.c\
	   movements.c\
	   open_images.c\
	   utils.c\
	   free_mem.c\
	   get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c\
	   ft_printf/ft_aux.c\
	   ft_printf/ft_hex.c\
	   ft_printf/ft_itoa_u.c\
	   ft_printf/ft_itoa.c\
	   ft_printf/ft_printf.c\
	   ft_printf/ft_ptr.c\
	   ft_printf/ft_putchar_fd.c\
	   ft_printf/ft_select.c\
	   

all: $(NAME)

$(NAME): $(FUNC) 
	$(CC) $(FUNC) -Wall -Wextra -Werror -I/usr/include -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

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
	