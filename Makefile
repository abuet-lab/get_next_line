# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuet <abuet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 11:34:31 by abuet             #+#    #+#              #
#    Updated: 2025/11/11 11:44:27 by abuet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= get_next_line
CFLAGS	= -Wall -Wextra -Werror -g
cc 	= cc

################################################################################
## SOURCES

HEADER = get_next_line.h

OPTION = -c -I $(HEADER)

SRC_FILES = get_next_line.c get_next_line_utils.c\

OBJ_FILES =  $(SRC_FILES:.c=.o)

################################################################################
## RULES

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(OPTION) $(SRC_FILES)
	@ar rc $(NAME) $(OBJ_FILES)
	

clean: 
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

launch : all 
	@$(CC) $(NAME)
	@./a.out
	@make fclean
.PHONY: all clean fclean launch re