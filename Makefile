NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = fractol.h

SRC = fractol.c utils.c init.c mandelbrot.c render.c julia.c burningship.c keyhandle.c

OBJS = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re