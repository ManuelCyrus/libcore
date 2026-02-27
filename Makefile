#ALL COLORS
GREEN := \033[0;32m
RESET := \033[0m
RED := \033[0;31m



NAME:=libcore.a

#commands
CC:=cc
CFLAGS:= -Wall -Wextra -Werror

SRC_DIR:= src/
SRC_UTILS:= src/utils/
SRC_PRINT:= src/print/


SRC:=$(wildcard $(SRC_DIR)*.c $(SRC_UTILS)*.c $(SRC_PRINT)*.c)
OBJ:=$(SRC:.c=.o)

all:$(NAME) BANNER

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "${GREEN}lib created${RESET}"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


BANNER:
	@echo "$(GREEN)    __    / ____/_  ___________  _____"
	@echo " <(o )  / /   / / / / ___/ / / / ___/"
	@echo "  ( . >/ /___/ /_/ / /  / /_/ (__  ) "
	@echo "   \`--- \____/\__, /_/   \__,_/____/ "
	@echo "            /____/                   $(RESET)"

fclean:
	clear
	rm -f $(OBJ) libcore.a
	clear
re:fclean all

Tester:
	cc $(CFLAGS) main.c  libcore.a -o test
	clear
	@echo "$(GREEN)=============== MOD TEST ACTIVETED ==================\n"
	./test
test:Tester

leaks:
	valgrind ./test

.PHONY: all clean fclean re	BANNER