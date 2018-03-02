NAME = fdf
LIBFT = libft
LIBMLX = minilibx
MAKE = make
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = main.o\
        rgb_to_int.o\
		draw_menu.o\
		img_draw_line.o\
		get_point.o\
		img_pixel_plot.o\
		get_app.o\
		get_map.o\
		map.o\
		print_int_rect_array.o\
		draw_map.o\
		rotate.o\
		transform.o\
		on_create.o\
		hextoi.o\
		render.o

INCLUDES = includes

.PHONY: all clean fclean re norm libs leaks test

all:$(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I$(INCLUDES)

libs:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(LIBMLX)
$(NAME):libs $(OBJ)

	$(CC) $(CFLAGS) -L $(LIBFT) -L $(LIBMLX) -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	norminette $(OBJ:.o=.c)
test:
	@echo "Compiling"
	@ $(MAKE) all && echo "Done" && ./$(NAME) maps/42.fdf || echo "Error"
leaks:
	leaks $(NAME)