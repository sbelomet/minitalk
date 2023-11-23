# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:12:12 by sbelomet          #+#    #+#              #
#    Updated: 2023/11/23 12:22:52 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	minitalk/
SERVER		=	server
CLIENT		=	client
HEADERS		=	-I includes
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/
LIBFTPRINTF	=	ft_printf/libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Colors

RED 		=	\033[1;91m
YELLOW		=	\033[1;93m
GREEN		=	\033[1;92m
BLUE		=	\033[1;94m
PURPLE		=	\033[1;95m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
MAGENTA		=	\033[0;95m
CYAN		=	\033[1;96m
WHITE		=	\033[0;97m
RAINBOW		=	$(RED)-$(YELLOW)-$(GREEN)-$(CYAN)-$(BLUE)-$(PURPLE)-

#Emojis

CLOWN		=	\xf0\x9f\xa4\xa1
DROOLING	=	\xf0\x9f\xa4\xa4
STEAMY		=	\xf0\x9f\xa5\xb5
UMACCTULY	=	\xf0\x9f\xa4\x93
POINT_UP	=	\xe2\x98\x9d\xef\xb8\x8f
MOONBOY		=	\xf0\x9f\x8c\x9d
CHILLY		=	\xf0\x9f\xa5\xb6

#Sources

FILES_EXT	=	utils

SV_FILES	=	server $(FILES_EXT)
SRC_SV		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SV_FILES)))
OBJ_SV		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SV_FILES)))

CL_FILES	=	client $(FILES_EXT)
SRC_CL		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CL_FILES)))
OBJ_CL		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CL_FILES)))

###

all:			$(OBJ_DIR) $(NAME)

$(LIBFTPRINTF):
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@make -C ft_printf

$(NAME):		$(LIBFTPRINTF) $(OBJ_SV) $(OBJ_CL)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@mkdir -p $(NAME)
				$(CC) $(CFLAGS) $(OBJ_SV) $(HEADERS) $(LIBFTPRINTF) -o $(NAME)$(SERVER)
				$(CC) $(CFLAGS) $(OBJ_CL) $(HEADERS) $(LIBFTPRINTF) -o $(NAME)$(CLIENT)
				@echo ""
				@echo "$(GREEN)$(NAME) est compilé !$(DEF_COLOR)$(CHILLY)$(CHILLY)$(CHILLY)"
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c	
				@echo "$(YELLOW)$< est dans le four...$(DEF_COLOR)$(STEAMY)$(STEAMY)$(STEAMY)"
				@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@make clean -C ft_printf
				@rm -rf $(OBJ_DIR)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@echo "$(BLUE)à la poubelle les .o$(DEF_COLOR)$(UMACCTULY)$(UMACCTULY)$(UMACCTULY)"

fclean:			clean
				@make fclean -C ft_printf
				@rm -rf $(NAME)
				@echo "$(CYAN)à la poubelle l'exec$(DEF_COLOR)$(DROOLING)$(DROOLING)$(DROOLING)"

re:				fclean all

.PHONY:			all clean fclean re
