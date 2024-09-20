CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = test_assets.c test_new.c get_next_line.c get_next_line_utils.c ft_split.c  error.c valid_path1.c valid_path.c check.c test2.c ft_putnbr.c ft_strcmp.c ft_strchr.c  check2.c ft_strrchr.c mouvement_ctl.c testfile_initialise.c mouvement_ctl_utils.c test_assets_utls.c print_assets.c main.c

OBJS =  $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all clean fclean re