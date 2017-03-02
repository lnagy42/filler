NAME = libft.a
CFLG = -Wextra -Wall -Werror -g
SRCS =  get_next_line.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_del.c \
		ft_deltab.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isinside.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_iswhite.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstadd_end.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_print_bits.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoinfree.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtolower.c \
		ft_strtoupper.c \
		ft_strtrim.c \
		ft_tabsize.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lst_delif.c
DIRP = printf/
FLSP = printf.c flags.c myputnbrs.c all_len.c doflags.c conv.c conv_wchar.c \
	   conv_c.c gets.c
SRCP  = $(addprefix $(DIRP), $(FLSP))
OBJP  = $(SRCP:.c=.o)
OBJS = $(SRCS:.c=.o)
CC   = gcc

all : $(NAME)

verbose:
	@printf "\n   \033[0;32mCompiling sources : \033[0;0m"

%.o: %.c
		@$(CC) $(CFLG) -c -o $@ $<
		@printf $@
		@printf "\033[0;32m ok !\n\033[0;0m"

$(NAME): verbose $(OBJS) $(OBJP)
		@ar rc $(NAME) $(OBJS) $(OBJP)
		@echo " \033[0;35mDone !"
		@echo "   \033[0;32mSorting ...\c\033[0;0m"
		@ranlib $(NAME)
		@echo " \033[0;35mDone !\033[0;0m"

link:
		@ar rc $(NAME) $(OBJS) $(OBJP)

clean:
		@printf "\033[0;31mcleaning libft...\t\t\t\t"
		@rm -f $(OBJS) $(OBJP)
		@printf "\033[0;35mDone !\033[0;31m\n"

quietclean:
		@rm -f $(OBJS) $(OBJP)

fclean: quietclean
		@rm -f $(NAME)

re: fclean $(OBJS) $(OBJP)
	@echo " \033[0;35mDone !\n   \033[0;32mLinking ...\c\033[0;0m"
	@ar rc $(NAME) $(OBJS) $(OBJP)
	@echo " \033[0;35mDone !"
	@echo "   \033[0;32mSorting ...\c\033[0;0m"
	@ranlib $(NAME)
	@echo " \033[0;35mDone !\033[0;0m"
