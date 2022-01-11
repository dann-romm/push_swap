CC			= gcc
RM			= rm -rf
# CFLAGS		= -Wall -Wextra -Werror
CFLAGS§		= -fsanitize=address

NAME		= push_swap
BONUSNAME	= checker

SRCDIR		= ./src/
OBJDIR		= ./obj/
INCDIR		= ./includes/

SRC			= push_swap.c list1.c list2.c instructions1.c instructions2.c instructions3.c algorithm.c algorithm_utils.c execute_operation.c utils.c parsing.c ft_split.c
OBJ			= $(addprefix $(OBJDIR), $(SRC:.c=.o))

BONUSSRC	= checker.c list1.c list2.c instructions1.c instructions2.c instructions3.c utils.c parsing.c ft_split.c get_next_line.c get_next_line_utils.c
BONUSOBJ	= $(addprefix $(OBJDIR), $(BONUSSRC:.c=.o))

all: $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUSNAME)

$(BONUSNAME): $(OBJDIR) $(BONUSOBJ)
	$(CC) $(CFLAGS) $(BONUSOBJ) -o $(BONUSNAME)

clear:
	clear

t: clear $(NAME)
	@echo "____________________"
	@echo $(NAME)
	@echo "____________________"
	@./$(NAME)

p: $(NAME) $(BONUSNAME)
	python3 temp.py

.PHONY: all clean fclean re mkdir_OBJDIR bonus
