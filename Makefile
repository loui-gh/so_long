NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lglut -lGLU -lGL
INCL = -I/usr/include -Imlx_linux -O3
INCL_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -f

		
OBJ = $(SRC:.c=.o)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
SRC = main.c utils.c ft_split.c close_window_linux.c readmap.c \
		map_imgs_to_win.c discover_map_errors.c map_errors1.c \
		move_linux.c ft_itoa.c utils1.c

%.o: %.c
	$(CC) $(CFLAGS) $(LIBS) $(INCL) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INCL_LINUX) -o $(NAME)

endif

ifeq ($(UNAME), Darwin)
SRC = main.c utils.c ft_split.c close_window_mac.c readmap.c \
		map_imgs_to_win.c discover_map_errors.c map_errors1.c \
		move_mac.c ft_itoa.c

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

endif

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)


all: $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus