# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 17:19:00 by yichan            #+#    #+#              #
#    Updated: 2023/09/07 01:52:56 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= a.out
CXX				= c++
CXXFLAGS		= -Wall -Werror -Wextra -g3 -std=c++98 
INCLUDES		= ./includes
SRCS_PATH		= ./srcs
OBJS_PATH		= ./objs
# SRCS			= $(wildcard $(SRCS_PATH)/*.cpp)
SRCS			= $(shell find $(SRCS_PATH) -name "*.cpp")
OBJS			= $(patsubst $(SRCS_PATH)/%.cpp, $(OBJS_PATH)/%.o, $(SRCS))

RESET		=	\033[0m
GREEN		=	\033[38;5;46m
WHITE		=	\033[38;5;15m
GREY		=	\033[38;5;8m
ORANGE		=	\033[38;5;202m
RED			=	\033[38;5;160m

all						: $(NAME)
$(NAME)					: $(OBJS)
#   $(MAKE) -c ./libft
						  $(CXX) $(CXXFLAGS) -I$(INCLUDES) $^ -o $@
						  @echo "The program name is $(RED)./$(NAME) $(RESET)"

$(OBJS_PATH)/%.o		: $(SRCS_PATH)/%.cpp $(INCLUDES) ./Makefile
						  @mkdir -p $(@D)
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




# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2023/08/02 15:38:28 by yichan            #+#    #+#              #
# #    Updated: 2023/08/30 20:33:41 by yichan           ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# NAME			=	a.out
# CXX				=	c++
# CXXFLAGS		=	-Wall -Werror -Wextra -g3 -std=c++98 #-fsanitize=address -pedantic
# INCLUDES		=	./includes
# SRCS_PATH		=	./srcs
# OBJS_PATH		=	./objs
# # SRCS			=	$(wildcard $(SRCS_PATH)/*.cpp)
# SRCS			=	$(shell find ${SRCS_PATH} -name "*.cpp")
# OBJS			=	$(patsubst $(SRCS_PATH)/%.cpp, $(OBJS_PATH)/%.o, $(SRCS))

# RESET		=	\033[0m
# GREEN		=	\033[38;5;46m
# WHITE		=	\033[38;5;15m
# GREY		=	\033[38;5;8m
# ORANGE		=	\033[38;5;202m
# RED			=	\033[38;5;160m

# all			:	$(NAME)

# $(NAME)		:	$(OBJS)
# 				$(CXX) $(CXXFLAGS) -I$(INCLUDES) $^ -o $@
# 				@echo "The program name is $(RED)./$(NAME) $(RESET)"
# $(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.cpp $(INCLUDES) ./Makefile
# 					mkdir -p $(@D)
# 					$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

# clean				:
# 						rm -rf $(OBJS_PATH)
						
# fclean				:	clean
# 						rm -rf $(NAME)
						
# re					:	fclean all

# run					:	all
# 						./$(NAME)

# valgrind		:
# 					valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt $(NAME)

# .PHONY				:	clean fclean re run all valgrind
