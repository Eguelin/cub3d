# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:20:28 by eguelin           #+#    #+#              #
#    Updated: 2023/11/01 13:17:07 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
BNS_DIR	= bonus/
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
LIB_DIR	= lib/
NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Werror -Wextra $(LIB_INC) -I $(INC_DIR)# -g3 -march=native -flto -O3# -fsanitize=address
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

DISPLAY_DIR		= display/
DISPLAY_FILES	= ft_display.c
ALL_FILES		+= $(addprefix $(DISPLAY_DIR), $(DISPLAY_FILES))

HOOK_DIR		= hook/
HOOK_FILES		= ft_hitbox.c ft_key.c ft_move.c
ALL_FILES		+= $(addprefix $(DISPLAY_DIR)$(HOOK_DIR), $(HOOK_FILES))

MAP_DIR			= mapping/
MAP_FILES		= ft_minimap.c pixel_manager.c
ALL_FILES		+= $(addprefix $(DISPLAY_DIR)$(MAP_DIR), $(MAP_FILES))

MLX-P_DIR		= mlx-plug-in/
MLX-P_FILES		= ft_put_image_to_image.c ft_put_pixel_to_image.c ft_clear_image.c
ALL_FILES		+= $(addprefix $(DISPLAY_DIR)$(MLX-P_DIR), $(MLX-P_FILES))

VISUAL_DIR		= visual/
VISUAL_FILES	= ft_visual.c
ALL_FILES		+= $(addprefix $(DISPLAY_DIR)$(VISUAL_DIR), $(VISUAL_FILES))

RAY-C_DIR		= ray-casting/
RAY-C_FILES		= ft_ray_casting.c
ALL_FILES		+= $(addprefix $(DISPLAY_DIR)$(VISUAL_DIR)$(RAY-C_DIR), $(RAY-C_FILES))

EXIT_DIR		= exit/
EXIT_FILES		= ft_close_win.c ft_exit.c
ALL_FILES		+= $(addprefix $(EXIT_DIR), $(EXIT_FILES))

INIT_DIR		= init/
INIT_FILES		= ft_init.c
ALL_FILES		+= $(addprefix $(INIT_DIR), $(INIT_FILES))

PARS_DIR		= parsing/
PARS_FILES		= ft_diffusion.c ft_check_map.c ft_get_map.c ft_open_file.c ft_parser.c texture_parser.c colors_parser.c
ALL_FILES		+= $(addprefix $(INIT_DIR)$(PARS_DIR), $(PARS_FILES))

UTILS_DIR		= utils/
UTILS_FILES		= ft_perror.c ft_strndup.c
ALL_FILES		+= $(addprefix $(UTILS_DIR), $(UTILS_FILES))

INC_FILES		= $(NAME).h

OBJS			= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS			= $(addprefix $(INC_DIR), $(INC_FILES))

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
