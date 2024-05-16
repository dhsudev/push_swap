# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:30:04 by ltrevin-          #+#    #+#              #
#    Updated: 2024/05/16 17:45:03 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##########  VARS CONFIG
NAME			= push_swap
HEADER_FILE		= push_swap.h
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
AR				= ar rcs

##########  PATHS
SRCS_PATH		= ./src
OBJS_PATH		= ./objs
INCLUDE_PATH	= ./include

##########  VARS FILES
SRC_FILES = main.c
OBJECTS = $(SRC_FILES:.c=.o)

##########  RULES
all: $(NAME)

$(NAME): $(INCLUDE_PATH)/$(HEADER_FILE) $(OBJS_PATH)/$(OBJECTS) Makefile
	@$(CC) $(FLAGS) $(OBJS_PATH)/$(OBJECTS) -o $@
	@echo "🔅 Pushswap is ready to work!"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
	@echo "🛠  $(@F) object created!"

.PHONY: all clean fclean re

clean:
	@rm -rf objs
	@echo "🧼 Removed object files from pushswap!"

fclean: clean
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"

re: fclean all