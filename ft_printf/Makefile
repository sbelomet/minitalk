# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:12:12 by sbelomet          #+#    #+#              #
#    Updated: 2025/09/16 11:26:29 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	libftprintf.a
HEADERS		=	include
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIBFT		=	libft
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I

# Colors

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED 		=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#Sources

SRC_RAW		=	ft_printf ft_printformat ft_printstr ft_printptr ft_printhex ft_converthex ft_uitoa

SRCS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_RAW)))
OBJS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_RAW)))

###

OBJF		=	.cache_exists

all:			$(NAME)

$(NAME):		$(OBJF)
				@make -C $(LIBFT) all
				@cp $(LIBFT)/libft.a $(NAME)
				@ar rc $(NAME) $(OBJS)
				@echo "$(GREEN)All good$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJF)
				@echo "$(YELLOW)Working on $<...$(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@rm -rf $(OBJ_DIR)
				@make -C $(LIBFT) clean
				@echo "$(BLUE)Cleared .o files$(DEF_COLOR)"

fclean:			clean
				@make -C $(LIBFT) fclean
				@rm -f $(NAME)
				@echo "$(CYAN)All cleared$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Cleared all and remade$(DEF_COLOR)"

.PHONY:			all clean fclean re libft
