SRC = lem_in.c \
	  create_rooms.c \
	  create_room.c \
	  create_tunnels.c \
	  create_tunnel.c \
	  algo.c \

SRCPATH = ./srcs/

OBJ = $(SRC:.c=.o)

LIB = libft.a

LIBPATH = ./libft/

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) :
	@make -C $(LIBPATH)
	@gcc -c $(FLAGS) $(addprefix $(SRCPATH),$(SRC))
	@echo "[Create objects]"
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBPATH)$(LIB)
	@echo "[Create lem-in]"

clean :
	@make clean -C $(LIBPATH)
	@rm -f $(OBJ)
	@echo "[Clean objects]"

fclean : clean
	@rm -f $(LIBPATH)$(LIB)
	@rm -f $(NAME)
	@echo "[Clean lem-in]"

re : fclean all

proj :
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@gcc -c $(FLAGS) $(addprefix $(SRCPATH), $(SRC))
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBPATH)$(LIB)
	@echo "Recompile lem-in"
