#ALL COLORS
GREEN := \033[0;32m
RESET := \033[0m



NAME:=libcore.a

#commands
CC:=cc
CFLAGS:= -Wall -Wextra -Werror

SRC_DIR:= src/
SRC_PRINT:= src/utils

SRC:=$(wildcard $(SRC_DIR)*.c $(SRC_PRINT)*.C)
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
	rm -f $(OBJ)
re:fclean all

.PHONY: all clean fclean re	BANNER