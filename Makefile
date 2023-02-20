

SRC	=	src/main.c \
		src/window/rendering.c \
		src/window/action.c \
		src/player/actions.c \
		src/player/move.c \
		# src/bullet/actions.c \
		# src/player/shoot.c \

OBJ	=	$(SRC:.c=.o)

LIB	=	-lSDL2 -lSDL2_image

NAME	=	game

CFLAGS += -Wall -Wextra

CFLAGS += -I./includes/

all:	$(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) $(LIB) -o $(NAME) -g


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re