# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:30:04 by ltrevin-          #+#    #+#              #
#    Updated: 2024/05/20 19:16:06 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##########  VARS CONFIG
NAME			= push_swap
CC				= gcc
FLAGS			= -Wall -Wextra -Werror 
AR				= ar rcs

##########  PATHS
SRCS_PATH		= ./src
OBJS_PATH		= ./objs
INCLUDE_PATH	= ./include

##########  VARS FILES
SRC_FILES 		= check_args.c main.c
SRCS 			= $(patsubst %, $(SRCS_PATH)/%, $(SRC_FILES))
OBJECTS 		= $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRCS))
HEADER_FILE		= $(INCLUDE_PATH)/push_swap.h
##########  RULES
all: $(NAME)

$(NAME): $(HEADER_FILE) $(OBJECTS) Makefile
	@$(CC) $(FLAGS) $(OBJECTS) -o $@
	@echo "🔅 Pushswap is ready to work!"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER_FILE)
	@mkdir -p objs
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
	@echo "🛠  $(@F) object created!"

run: $(NAME) 
	@echo "🔢 Starting execution..."
	@./$(NAME) $(ARGS)
	
test: $(NAME) checker_Mac
	@echo "🔢  Starting execution with checker_Mac..."
	@./$(NAME) $(ARGS) | ./checker_Mac $(ARGS)
	@echo "🔢  Starting execution counting words..."
	@./$(NAME) $(ARGS) | wc -l

.PHONY: all clean fclean re

clean:
	@rm -rf objs
	@echo "🧼 Removed object files from pushswap!"

fclean: clean
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"

re: fclean all