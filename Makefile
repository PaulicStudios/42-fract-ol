SRCDIR = src
OBJDIR = build
SRCS = fract-ol.c algorithm.c input_parser.c mlxmanager.c util.c
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
LIBMLX = lib/MLX42
LIBFT = lib/libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
LIBS = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -pthread -lm
INC = -I $(LIBFT) -I $(LIBMLX)/include/MLX42
EXEC = fractol
.PHONY: all run clean fclean re build

all: $(EXEC)

$(EXEC): $(OBJS)
	make -C $(LIBFT)
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	make -C lib/libft fclean
	rm -rf $(EXEC)

re: fclean all
