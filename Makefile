# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:30:04 by ltrevin-          #+#    #+#              #
#    Updated: 2024/07/15 15:27:08 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##########  VARS CONFIG
NAME			= push_swap
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
AR				= ar rcs

##########  PATHS
SRCS_PATH		= ./src
OBJS_PATH		= ./objs
INCLUDE_PATH	= ./include

##########  VARS FILES
SRC_FILES 		= 	check_args.c main.c num_utils.c stack_utils.c \
					move_swap.c move_push.c move_rotate.c move_reverse_rotate.c \
					sort_utils.c init_nodes.c
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
	@echo "🛠  $(@F:.o=) object created!"
	
ARG_FILE := args.txt
# 5 nums max 12 moves
# 100 max 700
# 500 max 5500
NUM_QTY := 500
MAX_MOVES := 5500
generate_arg: 
	@shuf -i 0-5000000 -n $(NUM_QTY) > $(ARG_FILE)

test: $(NAME) generate_arg
	@ARG=$$(cat $(ARG_FILE)); \
	RESULT=$$(./$(NAME) $$ARG | ./checker_linux $$ARG); \
	if [ "$$RESULT" = "OK" ]; then \
		COLOR="\033[0;32m"; \
	else \
		COLOR="\033[0;31m"; \
	fi; \
	echo "󱝿⚙️ Checker verify: $$COLOR$$RESULT\033[0m"; \
	echo -n "🔢 Num of moves:    "; \
	NUM_MOVES=$$(./$(NAME) $$ARG | wc -l); \
	if [ "$$NUM_MOVES" -lt $(MAX_MOVES) ]; then \
		COLOR="\033[0;32m"; \
	else \
		COLOR="\033[0;31m"; \
	fi; \
	echo "$$COLOR$$NUM_MOVES\033[0m"

#fish: for i in (seq 1 10); make test; end
#bash: for i in {1..10}; do make test; done

clean:
	@rm -rf objs
	@echo "🧼 Removed object files from pushswap!"
	@rm -f $(ARG_FILE)
fclean: clean
	@make fclean -C include/libft --no-print-directory
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"

re: fclean all

.PHONY: all clean fclean re libft
