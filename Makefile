# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 12:31:27 by lnagy             #+#    #+#              #
#*   Updated: 2016/12/12 12:51:27 by lnagy            ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME   = lnagy.filler
CFLG   = -Wextra -Wall -Werror
FILES  = filler.c parse.c play.c
SRCD   = srcs/
OBJD   = objs/
LIBS   = -Llibft -lft
SRCS   = $(addprefix $(SRCD),$(FILES))
OBJS   = $(addprefix $(OBJD),$(FILES:.c=.o))
HEAD   = includes/filler.h
INC    = -Iincludes -Ilibft

.PHONY: lib all clean re fclean

all : $(NAME)

$(OBJD)%.o: $(SRCD)%.c ${HEAD}
	@mkdir -p objs
	gcc $(CFLG) $(INC) -c -o $@ $<

$(NAME): $(OBJS)
		gcc $(CFLG) -o $@ $(OBJS) $(LIBS)

clean:
		@rm -f $(OBJS)
		@echo "Objects cleaned."

fclean: clean
		@rm -f $(NAME)
		@echo "Binaries cleaned."

re: fclean all
