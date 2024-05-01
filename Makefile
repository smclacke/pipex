# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/25 19:55:34 by smclacke      #+#    #+#                  #
#    Updated: 2024/05/01 12:45:28 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 			= pipex

INC_DIR			= -Iinclude -Iinclude/libft/src

MAKEFLAGS		= --no-print-directory
CFLAGS			= -Wall -Wextra -Werror 
CFLAGS			+= -g -fsanitize=address
CC				= cc

SRCS			= main.c		\
					pipex.c		\
					paths.c		\
					check.c		\
					error.c		\
					here_doc.c	\
					utils.c

SRC_DIR			= src
SRC				= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR			= obj
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

## Colours ##
RESET		:= \033[0m
RED			:= \033[1;91m
GREEN		:= \033[1;92m
YELLOW		:= \033[1;93m
BLUE		:= \033[1;94m
PURPLE		:= \033[1;95m
CYAN		:= \033[1;96m
WHITE		:= \033[1;97m
BLACK		:= \033[1;90m

all			: libft $(NAME)

libft		:
	@ make -C include/libft

$(NAME)		: $(OBJ)
	@ echo "${RED} >>> pipex compiling...${RESET}"
	@ $(CC) $^ $(CFLAGS) $(INC_DIR) include/libft/libft.a -o $(NAME)
	@ echo "${GREEN} ---> pipex Made!${RESET}"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean		:
	@ make $(MAKEFLAGS) -C include/libft clean
	@ rm -rf $(OBJ_DIR)

fclean		:
	@ make $(MAKEFLAGS) -C include/libft fclean
	@ rm -rf $(OBJ_DIR)
	@ rm -f $(NAME)
	@ echo "${RED} // pipex fCleaned!${RESET}"

re			: fclean all

.PHONY: all clean fclean re libft
