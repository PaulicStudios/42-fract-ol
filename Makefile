SRCDIR = src
OBJDIR = build
SRCS = fract-ol.c algorithm.c input_parser.c mlxmanager.c util.c
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = lib/libft/libft.a lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
INC = -I lib/libft -I lib/MLX42/include/MLX42
EXEC = fractol
.PHONY: all run clean fclean re build

all: $(EXEC)

$(EXEC): $(OBJS)
	mkdir -p $(OBJDIR)
	make -C lib/libft
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	make -C lib/libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C lib/libft fclean
	rm -rf $(EXEC)

re: fclean all
