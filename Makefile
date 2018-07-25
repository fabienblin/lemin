# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/07/25 16:44:31 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/07/25 17:52:52 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

SRC_DIR =	./src/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

NAME =		lemin

CFILES =	main.c

SOURCES =	$(addprefix $(SRC_DIR), $(CFILES))

OFILES =	$(CFILES:.c=.o)

OBJECTS =	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME)	:	$(OBJECTS)
			@make libft
			gcc $(FLAGS) $(OBJECTS) -L ./libft/ -lft -o $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@make obj
					gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./libft/inc/

clean	:	obj
			@make clean -C ./libft/
			@rm -rf $(OBJ_DIR)

fclean	:	obj
			@make fclean -C ./libft/
			@rm -f $(NAME)
			@rm -rf $(OBJ_DIR)

re		:	fclean all

obj	:
			@mkdir -p $(OBJ_DIR)

libft	:
			@make -C ./libft/

test	:	libft
			gcc ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o lemin_test
			./lemin_test < map

debug	:	libft
			gcc -ggdb ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o lemin_debug
			lldb ./lemin_debug

.PHONY	:	all clean fclean re libft obj