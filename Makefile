# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmei <rmei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 12:07:28 by rmei              #+#    #+#              #
#    Updated: 2024/08/30 17:20:20 by rmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### -- VARIABLES -- ####
# Push Swap
PSWAP_SRC = main.c \
	push_swap_rotate.c sort.c stack.c
PSWAP_SRC := $(addprefix src/push_swap/, ${PSWAP_SRC})
PSWAP_OBJS = $(PSWAP_SRC:%.c=%.o)
NAME = push_swap

# Checker
CHECKER_SRC = checker.c
CHECKER_SRC := $(addprefix src/checker/, ${CHECKER_SRC})
CHECKER_OBJS = $(CHECKER_SRC:%.c=%.o)
CHECKER = checker

# External libraries
LIBFT = lib/libft

# Compiler and linker flags
CPPFLAGS = -I./include
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./$(LIBFT) -lft

#### -- RULES -- ####	
all: __lib $(NAME)

bonus: __lib $(CHECKER) 

# Create external libraries #
__lib:
	@make -sC $(LIBFT)

# Create executables
$(NAME): $(PSWAP_OBJS)
	cc $^ $(LDFLAGS) -o $@

$(CHECKER): $(CHECKER_OBJS)
	cc $^ $(LDFLAGS) -o $@
	
%.o: %.c
	cc $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	
# Manage object files and executables #
clean:
	make clean -sC $(LIBFT)
	rm -f $(PSWAP_OBJS) $(CHECKER_OBJS)

fclean: 
	make fclean -sC $(LIBFT)
	rm -f $(PSWAP_OBJS) $(NAME) $(CHECKER_OBJS) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
