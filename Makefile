# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:14:13 by dohelee           #+#    #+#              #
#    Updated: 2021/05/21 02:27:40 by dohelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
CFLAGS = -O3 -Wall -Wextra -Werror

LIB_FT_NAME = ft
LIB_FT_DIR = ./libft

NAME = push_swap
SRCS_DIR = ./
SRCS_NAME = ft_push.c ft_reverse_rotate.c ft_rotate.c ft_stack.c ft_swap.c push_swap.c ft_errchk.c ft_sort.c ft_sort_quick_atob.c ft_sort_quick_btoa.c ft_sort_utils.c ft_sort_optimize.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME)) 
OBJS = $(SRCS:.c=.o)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(SRCS_DIR) -c $^ -o $@
	
$(NAME) : $(OBJS)
	$(MAKE) all -C $(LIB_FT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_FT_DIR) -l$(LIB_FT_NAME) -o $(NAME)

all	: $(NAME) $(NAME2)

clean :
	$(MAKE) clean -C $(LIB_FT_DIR)
	rm -f $(OBJS) 
	
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
