NAME =		libftprintf.a

SRC =		convert_to_base.c \
			convert_va_arg_to_str.c \
			convert_va_arg_to_str2.c \
			ft_printf.c \
			parse_percent.c \
			write_to_buff.c \
			apply_flag_router.c \
			apply_precision.c \
			calcul_real_padding.c \
			diese_sign_correction_padding.c \
			dispatch_type.c \
			dispatch_type2.c \
			ignore_flag.c \
			ignore_flag2.c \

OBJ =		$(SRC:.c=.o)

HEADER =	ft_printf.h

FLAG =		-Wall -Werror -Wextra

LIBFT =		libft/libft.a

COUNT =		0

%.o:%.c $(HEADER)
			@clear
			@echo "$(COUNT)/13   $@"
			@gcc -o $@ -c $< $(FLAG) -O
			$(eval COUNT=$(shell echo $$(($(COUNT)+1))))


$(NAME) :	$(OBJ)
			@make -C libft
			@echo "Creating libftprintf.a . . ."
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "Done"

all :		$(NAME)

lib :
			@make -C libft

clean :
			@clear
			@/bin/rm -f $(OBJ)
			@echo "Object's libftprintf removed"
			@make -C libft clean

fclean :	clean
			@clear
			@/bin/rm -f $(NAME)
			@echo "libftprintf.a removed"
			@make -C libft fclean

re : 		fclean all

ssflag :
			@gcc -c $(SRC)
			@gcc $(LIBFT) $(OBJ) -o $(NAME)
