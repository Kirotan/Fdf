#***************************************************************************#
#									FDF										#
#***************************************************************************#

#---------------------------------------------------------------------------#
#	Variables																#
#---------------------------------------------------------------------------#

NAME		:= fdf
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iinc -Ilibft/inc
AR			:= ar rcs
RM			:= rm -f
MAKE_SILENT	:= @

# 👉 Adjust these if your MiniLibX install path differs
MLX_LIBS	:= -lmlx -lXext -lX11 -lm -lz
MLX_PATH	:=	# e.g. -L/usr/local/lib
MLX_INC		:=	# e.g. -I/usr/local/include
LDFLAGS		:= $(MLX_PATH) $(MLX_LIBS)
CFLAGS 		+= $(MLX_INC)

#---------------------------------------------------------------------------#
#	Directories & files														#
#---------------------------------------------------------------------------#

SRC_DIR		:= srcs
OBJ_DIR		:= obj
LIBFT_DIR	:= libft
LIBFT_AR	:= $(LIBFT_DIR)/libft.a

SRC			:= $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#---------------------------------------------------------------------------#
#	Rules																	#
#---------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT_AR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_AR) $(LDFLAGS) -o $(NAME)
	@echo "\033[32m[LD]	$@\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_SILENT)mkdir -p $(OBJ_DIR)

libft: $(LIBFT_AR)

$(LIBFT_AR):
	@echo "\033[36m[MAKE] libft\033[0m"
	$(MAKE_SILENT)$(MAKE) -C $(LIBFT_DIR)

#---------------------------------------------------------------------------#
#	Cleaning																#
#---------------------------------------------------------------------------#

clean:
	$(MAKE_SILENT)$(RM) $(OBJ)
	$(MAKE_SILENT)$(RM) -r $(OBJ_DIR) 2>/dev/null || true
	$(MAKE_SILENT)$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[33m[RM]	object files removed\033[0m"

fclean: clean
	$(MAKE_SILENT)$(RM) $(NAME)
	$(MAKE_SILENT)$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[33m[RM]	$(NAME) + libft.a removed\033[0m"

re: fclean all

.PHONY: all clean fclean re libft
