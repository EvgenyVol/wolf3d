NAME = wolf3d
ECHO := echo -e
SRCS = *.c
SRCS_DIR = $(wildcard srcs/*/*.c srcs/*.c)
FLAGS = -Wall -Wextra -Werror
GNL_DIR = $(addprefix ./utils/gnl/, $(GNL))
GNL = get_next_line.c
LIB = -L./utils/libft/ -lft
INC = -I includes -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers \
		-I ./utils/libft -I ./utils/gnl -I TgaReader/includes -I frameworks/SDL2_mixer.framework/Versions/A/Headers
SDL = -F ~/Library/Frameworks -framework SDL2 -F frameworks/ -framework SDL2_mixer
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
OBJ_DIR = objs

all: $(NAME)

$(NAME):
	@echo "\033[0;33m LIBFT MAKE:\033[0;32m [OK]\033[0m" $<
	@make -sC ./utils/libft
	@echo "\033[0;33m GCC PRJ :\033[0;32m [OK]\033[0m" $<
	@gcc -c $(FLAGS) $(SRCS_DIR) $(GNL_DIR) $(INC)
	@echo "\033[0;33m OBJ DIR :\033[0;32m [OK]\033[0m" $<
	@mkdir -p $(OBJ_DIR) && mv $(SRCS:.c=.o) ./$(OBJ_DIR)
	@echo "\033[0;33m FINAL COMPILE:\033[0;32m [OK]\033[0m" $<
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(SDL) $(INC)
clean:
	@make clean -sC ./utils/libft
	@rm -rf $(OBJ_DIR)
fclean: $@clean
	@make fclean -sC ./utils/libft
	@rm -rf $(NAME)
re: fclean all