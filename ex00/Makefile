# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 17:19:00 by yichan            #+#    #+#              #
#    Updated: 2023/08/23 19:01:28 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= a.out
CXX				= c++
CXXFLAGS		= -Wall -Werror -Wextra -g3 -std=c++98
INCLUDES		= ./includes
SRCS_PATH		= ./srcs
OBJS_PATH		= ./objs
SRCS			= $(wildcard $(SRCS))
OBJS			= $(patsubst $(SRCS_PATH)/%.c, $(ONJS_PATH)/%.o, $(SRCS))

all						: $(NAME)
NAME					: $(OBJS)
#   $(MAKE) -c ./libft
						  $(CXX) $(CXXFLAGS) -I$(INCLUDES) $^ -o $@

$(ONJS_PATH)/%.o		: $(SRCS_PATH)/%.c $(INCLUDES) ./Makefile
						  mkdir -p $(@D)
						  $(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

clean					:
							rm -rf $(OBJS_PATH)
						
fclean					:	clean
							rm -rf $(NAME)
						
re						:	fclean all

run						:	all
							./$(NAME)

valgrind				:
							valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt $(NAME)

.PHONY					:	clean fclean re run all valgrind