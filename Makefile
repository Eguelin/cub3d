# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:20:28 by eguelin           #+#    #+#              #
#    Updated: 2023/10/14 19:41:52 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
BNS_DIR	= bonus/
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
LIB_DIR	= lib/
NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Werror -Wextra $(LIB_INC) -I $(INC_DIR) -g3# -fsanitize=address
MLX		= -Lmlx_linux -lmlx_Linux -L $(LIB_DIR)$(MLX_DIR) -Imlx_linux -lXext -lX11 -lm -lz
RM		= rm -rf
ARC		= ar rcs

#Colors
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#Sentence
COMP_MSG		= "$(GREEN)Compilation $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
COMP_BNS_MSG	= "$(GREEN)Compilation of bonus $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"

#Sources
ALL_FILES = main.c

PARS_DIR		= parsing/
PARS_FILES		= ft_check_map.c ft_get_map.c ft_open_file.c ft_parser.c
ALL_FILES		+= $(addprefix $(PARS_DIR), $(PARS_FILES))

UTILS_DIR		= utils/
UTILS_FILES		= ft_exit.c ft_perror.c
ALL_FILES		+= $(addprefix $(UTILS_DIR), $(UTILS_FILES))

INC_FILES		= $(NAME).h

OBJS			= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS			= $(addprefix $(INC_DIR), $(INC_FILES))

#Sources bonus
# ALL_FILES = .c

# ..._DIR			= /
# ..._FILES		= .c
# ALL_FILES		+= $(addprefix $(..._DIR), $(..._FILES))

# BNS_INC_FILES	= $(NAME)_bonus.h

# BNS_OBJS	= $(addprefix $(OUT_DIR), $(ALL_BNS_FILES:.c=.o))
# BNS_HEADERS	= $(addprefix $(INC_DIR), $(BNS_INC_FILES))

#Lib
MYLIB_DIR		= mylib/
MYLIB_FILES		= mylib.a
LIB_FILES		= $(MYLIB_DIR)$(MYLIB_FILES)
LIB_INC			= -I $(LIB_DIR)$(MYLIB_DIR)$(INC_DIR)

MLX_DIR			= minilibx-linux/
LIB_INC			+= -I $(LIB_DIR)$(MLX_DIR)

LIB				= $(addprefix $(LIB_DIR), $(LIB_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)
	@echo $(COMP_MSG)
	@norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'
	@norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# bonus: $(OUT_DIR) $(BNS_OBJS) $(LIB)
# 	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIB) $(MLX) -o $(NAME)
# 	@echo $(COMP_BNS_MSG)
# 	@norminette $(INC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'
# 	@norminette $(SRC_DIR) | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

# $(OUT_DIR)%.o : $(SRC_DIR)%.c $(BNS_HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -sC $(LIB_DIR)$(MYLIB_DIR)
	$(MAKE) clean -sC $(LIB_DIR)$(MLX_DIR)
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean:
	$(MAKE) fclean -sC $(LIB_DIR)$(MYLIB_DIR)
	$(MAKE) clean -sC $(LIB_DIR)$(MLX_DIR)
	$(RM) $(NAME) $(OUT_DIR)
	@echo $(CLEAN_MSG)
	@echo $(FULL_CLEAN_MSG)

force:

$(LIB): force
	$(MAKE) -sC $(LIB_DIR)$(MYLIB_DIR)
	$(MAKE) -sC $(LIB_DIR)$(MLX_DIR)

$(OUT_DIR): force
	@mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

re: fclean all

exec: all
	./$(NAME)

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME)

.PHONY: all clean fclean force re exec leaks
.SILENT:
