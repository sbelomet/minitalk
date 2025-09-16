# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:12:12 by sbelomet          #+#    #+#              #
#    Updated: 2025/09/16 11:48:18 by sbelomet         ###   ########.fr        #
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

#Sources

FILES_EXT	=	utils

SV_FILES	=	server $(FILES_EXT)
SRC_SV		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SV_FILES)))
OBJ_SV		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SV_FILES)))

CL_FILES	=	client $(FILES_EXT)
SRC_CL		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CL_FILES)))
OBJ_CL		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CL_FILES)))

#Sources Bonus

FILES_EXT_B	=	utils_bonus

SV_FILES_B	=	server_bonus $(FILES_EXT_B)
SRC_SV_B	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SV_FILES_B)))
OBJ_SV_B	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SV_FILES_B)))

CL_FILES_B	=	client_bonus $(FILES_EXT_B)
SRC_CL_B	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CL_FILES_B)))
OBJ_CL_B	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CL_FILES_B)))

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
				@echo "$(GREEN)$(NAME) compiled$(DEF_COLOR)"
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

bonus:			$(LIBFTPRINTF) $(OBJ_SV_B) $(OBJ_CL_B)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@mkdir -p $(NAME)
				$(CC) $(CFLAGS) $(OBJ_SV_B) $(HEADERS) $(LIBFTPRINTF) -o $(NAME)$(SERVER)
				$(CC) $(CFLAGS) $(OBJ_CL_B) $(HEADERS) $(LIBFTPRINTF) -o $(NAME)$(CLIENT)
				@echo ""
				@echo "$(GREEN)$(NAME)(bonus) compiled !$(DEF_COLOR)"
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c	
				@echo "$(YELLOW)Working on $<...$(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@make clean -C ft_printf
				@rm -rf $(OBJ_DIR)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@echo "$(BLUE)Cleared .o files$(DEF_COLOR)"

fclean:			clean
				@make fclean -C ft_printf
				@rm -rf $(NAME)
				@echo "$(CYAN)Cleared all$(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re
