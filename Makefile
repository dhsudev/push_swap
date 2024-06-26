# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:30:04 by ltrevin-          #+#    #+#              #
#    Updated: 2024/07/01 16:10:12 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##########  VARS CONFIG
NAME			= push_swap
CC				= gcc
FLAGS			= -Wall -Wextra -Werror #-g -fsanitize=address
AR				= ar rcs

##########  PATHS
SRCS_PATH		= ./src
OBJS_PATH		= ./objs
INCLUDE_PATH	= ./include

##########  VARS FILES
SRC_FILES 		= check_args.c main.c num_utils.c stack_utils.c swap_move.c push_move.c rotate_move.c reverse_rotate_move.c
SRCS 			= $(patsubst %, $(SRCS_PATH)/%, $(SRC_FILES))
OBJECTS 		= $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRCS))
HEADER_FILE		= $(INCLUDE_PATH)/push_swap.h
##########  RULES
all: libft $(NAME)

$(NAME): $(HEADER_FILE) $(OBJECTS) Makefile
	@$(CC) $(FLAGS) $(OBJECTS) -o $@ include/libft/libft.a
	@echo "🔅 Pushswap is ready to work!"

libft:
	@make bonus -C include/libft --no-print-directory

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER_FILE) include/libft/libft.a
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

.PHONY: all clean fclean re libft

clean:
	@rm -rf objs
	@echo "🧼 Removed object files from pushswap!"

fclean: clean
	@make fclean -C include/libft --no-print-directory
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"

re: fclean all
