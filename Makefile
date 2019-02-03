# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jackson <jbeall@student.42.us.org>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 14:21:53 by jbeall            #+#    #+#              #
#    Updated: 2019/02/02 14:38:05 by jackson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
FLAGS = -Wall -Werror -Wextra -lcurses
SRC_DIR = ./src/
SRC = op_handlers.c op_handlers2.c op_handlers3.c op_handlers4.c utils1.c \
utils2.c
CHECK_SRC = checker.c
PS_SRC = push_swap.c sub_sort.c sub_sort2.c sub_sort_helpers1.c ps_visual.c \
ps_visual2.c sub_sort_helpers2.c utils3.c
INC_DIR = ./includes/
LIB_INC_DIR = ./libft/includes/
LIB = ./libft/libft.a

$(NAME):
	@make -C ./libft --no-print-directory
	@echo "Creating $(NAME) executable..."
	@clang -o $(NAME) $(FLAGS) $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(SRC_DIR), $(PS_SRC)) $(LIB) -I$(LIB_INC_DIR) -I$(INC_DIR) -O3
	@echo "\033[92mdone!\033[0m"
$(NAME2):
	@make -C ./libft --no-print-directory
	@echo "Creating $(NAME2) executable..."
	@clang -o $(NAME2) $(FLAGS) $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(SRC_DIR), $(CHECK_SRC)) $(LIB) -I$(LIB_INC_DIR) -I$(INC_DIR) -O3
	@echo "\033[92mdone!\033[0m"
all: $(NAME) $(NAME2)
dev:
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make -C ./libft --no-print-directory
	@echo "compiling dev build..."
	@clang -o $(NAME) $(FLAGS) -g $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(SRC_DIR), $(PS_SRC)) $(LIB) -I$(LIB_INC_DIR) -I$(INC_DIR)
	@clang -o $(NAME2) $(FLAGS) -g $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(SRC_DIR), $(CHECK_SRC)) $(LIB) -I$(LIB_INC_DIR) -I$(INC_DIR)
	@echo "\033[92mdone!\033[0m"
clean:
	@echo "cleaning..."
	@make clean -C ./libft --no-print-directory
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME2).dSYM
	@echo "$(NAME) executable removed!"
	@echo "$(NAME2) executable removed!"
	@make fclean -C ./libft --no-print-directory
re: fclean all
