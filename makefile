# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 16:40:09 by lstorey           #+#    #+#              #
#    Updated: 2024/04/10 12:52:12 by lstorey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk

SERVER		=	server

CLIENT 		=	client

CC			= 	cc

FLAGS		= 	-Wall -Werror -Wextra -g

C_SRC 		=	client.c 

S_SRC 		=	server.c 

LIBFT 		= 	libft/libft.a 		

S_OBJ  		= 	$(S_SRC:.c=.o)
C_OBJ  		= 	$(C_SRC:.c=.o) 

all			: $(NAME)

$(NAME)		: $(SERVER) $(CLIENT)

$(SERVER) 	:	$(S_OBJ) 
				cd libft && make all
				cc $(FLAGS) $(S_OBJ) $(LIBFT) -o $(SERVER)
				
$(CLIENT)	:	$(C_OBJ) 
				cd libft && make all
				cc $(FLAGS) $(C_OBJ) $(LIBFT) -o $(CLIENT)
				
%.o			:	%.c
				@CC $(FLAGS) -c $< -o $@

libft		: 	
				make -C libft
clean		:	
				rm -f $(C_OBJ) $(S_OBJ)
				cd libft && make clean
				 

fclean		:	clean
				rm -f $(SERVER) $(CLIENT)
				cd libft && make fclean

re			:	fclean all

.PHONY 		: all clean fclean re san leaks