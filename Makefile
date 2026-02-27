#ALL COLORS
GREEN := \033[0;32m
RESET := \033[0m
RED := \033[0;31m
YELLOW := \33[0;43m




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
	@printf "${GREEN}All is ok${RESET}"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

BANNER:
	@echo "$(GREEN)    __    / ____/_  ___________  _____"
	@echo " <(o )  / /   / / / / ___/ / / / ___/"
	@echo "  ( . >/ /___/ /_/ / /  / /_/ (__  ) "
	@echo "   \`--- \____/\__, /_/   \__,_/____/ "
	@echo "            /____/                   $(RESET)"

fclean:
	@printf "$(RED) Removing files.....\n"
	rm -f $(OBJ) libcore.a
	@printf "$(RED) All files have been removed\n$(RESET)"

clean:
	rm -f $(OBJ) libcore.a
	clear
	@printf "$(RED)All files  deleted now\n"

re: fclean
	@printf "\n$(YELLOW)Starting rebuild...\n$(RESET)"
	@$(MAKE) --no-print-directory all
	@printf "$(GREEN)Rebuild successfully completed!\n$(RESET)"


Tester:
	cc $(CFLAGS) main.c  libcore.a -o test
	clear
	@printf "$(GREEN)=============== MOD TEST ACTIVETED ==================\n"
	./test
	@printf "\n=============== FINAL TEST FILE =====================\n"
test:Tester

leaks:
	valgrind ./test

.PHONY: all clean fclean re	BANNER