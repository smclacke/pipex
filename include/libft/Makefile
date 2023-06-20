# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/12 14:53:21 by smclacke      #+#    #+#                  #
#    Updated: 2023/06/20 18:25:19 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
ARCHIVE		= ar rcs
RM			= rm -f

SRCS		=	ft_isalpha.c			\
    			ft_isalnum.c			\
    			ft_isascii.c			\
    			ft_isdigit.c			\
    			ft_isprint.c			\
				ft_isquote.c			\
    			ft_strchr.c				\
    			ft_strrchr.c			\
    			ft_strlen.c				\
    			ft_strnstr.c			\
    			ft_strncmp.c			\
    			ft_strlcat.c			\
    			ft_strlcpy.c			\
    			ft_atoi.c				\
    			ft_bzero.c				\
    			ft_memset.c				\
    			ft_memcpy.c				\
    			ft_memcmp.c				\
    			ft_memmove.c			\
    			ft_memchr.c				\
    			ft_tolower.c			\
    			ft_toupper.c			\
    			ft_calloc.c				\
    			ft_strdup.c				\
    			ft_putchar_fd.c			\
    			ft_putendl_fd.c			\
    			ft_putnbr_fd.c			\
    			ft_putstr_fd.c			\
    			ft_strjoin.c			\
    			ft_substr.c				\
    			ft_striteri.c			\
    			ft_strtrim.c			\
    			ft_strmapi.c			\
    			ft_itoa.c				\
    			ft_split.c				\
    			ft_lstadd_back.c		\
    			ft_lstadd_front.c		\
    			ft_lstclear.c			\
    			ft_lstdelone.c			\
    			ft_lstiter.c			\
    			ft_lstlast.c			\
    			ft_lstmap.c				\
    			ft_lstnew.c				\
    			ft_lstsize.c			\
				ft_atof.c				\
				ft_ishex.c				\
				ft_isspace.c			\
				ft_strcmp.c				\
				ft_lower_str.c			\
				ft_upper_str.c			\
				ft_putendl.c			\
				ft_putstr.c				\
				ft_putchar.c			\
				ft_arrlen.c				\
				ft_error.c				\
				ft_free_arr.c			\
				get_next_line.c			\
				get_next_line_utils.c	\
				ft_printf_utils.c		\
				ft_printf.c

SRC_DIR		= src
SRC			= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=%.o)
OBJ			= $(addprefix $(OBJ_DIR)/, $(OBJS))

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

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "${YELLOW} >>> libft compiling...${RESET}"
	@ $(ARCHIVE) $(NAME) $(OBJ)
	@ echo "${GREEN} ---> libft Made!${RESET}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@ $(RM) -rf $(OBJ_DIR)

fclean: clean
	@ $(RM) $(NAME)
	@ echo "${YELLOW} // libft fCleaned!${RESET}"

re: fclean all

.PHONY: all clean fclean re
