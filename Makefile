# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <gdelabro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 15:37:25 by gdelabro          #+#    #+#              #
#    Updated: 2017/10/05 20:17:44 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = asm
NAME_2 = corewar

SRC_PATH_1 = asm_dir/src
SRC_NAME_1 = ../../op/op.c main.c error.c pars_info.c

SRC_PATH_2 = corewar_dir/src
SRC_NAME_2 = ../../op/op.c\
			 main.c\
			 init.c\
			 loop.c\
			 process.c\
			 execute_instruction.c\
			 swap.c\
			 parser/parser.c\
			 parser/load_player.c\
			 instructions/live.c\
			 instructions/direct_load.c\
			 instructions/direct_store.c\
			 instructions/ft_add.c\
			 instructions/ft_sub.c\
			 instructions/and.c\
			 instructions/or.c\
			 instructions/xor.c\
			 instruction/zjump.c\
			 instructions/two_octet_to_short.c\
			 instructions/four_octets_to_int.c\

OBJ_PATH_1 = asm_dir/obj
OBJ_NAME_1 = $(SRC_NAME_1:.c=.o)

OBJ_PATH_2 = corewar_dir/obj
OBJ_NAME_2 = $(SRC_NAME_2:.c=.o)

CC = clang
CFLAGS = -g -Wall -Werror -Wextra

CPPFLAGS = -I corewar_dir/src -I includes -I ft_printf/includes

LDFLAGS = -L ft_printf
LDLIBS = -lftprintf
LIB = ft_printf/libftprintf.a

SRC_1 = $(addprefix $(SRC_PATH_1)/,$(SRC_NAME_1))
OBJ_1 = $(addprefix $(OBJ_PATH_1)/,$(OBJ_NAME_1))

SRC_2 = $(addprefix $(SRC_PATH_2)/,$(SRC_NAME_2))
OBJ_2 = $(addprefix $(OBJ_PATH_2)/,$(OBJ_NAME_2))

all: $(LIB) $(NAME_1) $(NAME_2)

$(LIB):
	@make -C ft_printf

$(NAME_1): $(OBJ_1)
	@printf "\n"
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of \033[34;1m$@\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(NAME_2): $(OBJ_2)
	@printf "\n"
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of \033[31;1m$@\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(OBJ_PATH_1)/%.o: $(SRC_PATH_1)/%.c
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH_1) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

$(OBJ_PATH_2)/%.o: $(SRC_PATH_2)/%.c
	@printf "\033[31;1m| \033[0;1m"
	@mkdir $(OBJ_PATH_2) 2> /dev/null || true
	@mkdir $(OBJ_PATH_2)/parser 2> /dev/null || true
	@mkdir $(OBJ_PATH_2)/instructions 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C ft_printf clean
	@rm -f $(OBJ_1)
	@rm -rf $(OBJ_2)
	@rm -rf $(OBJ_PATH_1)
	@rm -rf $(OBJ_PATH_2)
	@echo "\033[34;1m$(NAME_1)\033[0;1m: objects deleted"
	@echo "\033[31;1m$(NAME_2)\033[0;1m: objects deleted"

fclean: clean
	@make -C ft_printf fclean
	@rm -rf $(NAME_1)
	@rm -rf $(NAME_2)
	@echo "\033[34;1m$(NAME_1)\033[0;1m: $(NAME_1) deleted"
	@echo "\033[31;1m$(NAME_2)\033[0;1m: $(NAME_2) deleted"


re: fclean all

.PHONY: all clean fclean re
