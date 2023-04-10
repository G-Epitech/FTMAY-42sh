##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##


_SRC =

_TESTS =

SRCDIR = 		sources/
SRC =			$(addprefix $(SRCDIR), $(_SRC))
MAIN =			$(addprefix $(SRCDIR), main.c)
MAIN_OBJ =		$(MAIN:.c=.o)
SRC_OBJ = 		$(SRC:.c=.o)

TESTSDIR = 		tests/
TESTS =			$(addprefix $(TESTSDIR), $(_TESTS))
TESTS_OBJ = 	$(TESTS:.c=.o)

INC = 			-I.. -I./includes
CFLAGS +=		-Wall -Wextra -Werror -Wno-unused-command-line-argument

CC = 			gcc

FTEST_REPO = 	https://github.com/Atomot/ftest/
FTEST_V = 		ftest-0.1.0-1.x86_64.rpm

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

COMPILING_O_LOG = "$(STYLE_BLUE)📑 Compiling sources -\
$(STYLE_BOLD)$(STYLE_BOLD)[%s]$(STYLE_END)\n"

NAME =			42sh

.PHONY = all clean fclean re

all: 			$(NAME)

$(NAME):		$(SRC_OBJ) $(MAIN_OBJ)
				@printf "$(STYLE_RED)🚚 Main compliation...$(STYLE_END)\n"
				@$(CC) -o $(NAME) $(SRC_OBJ) $(MAIN_OBJ) \
				$(LDFLAGS) $(CFLAGS) $(INC)
				@printf "$(STYLE_GREEN)✅ $(NAME) was successfully built\
				$(STYLE_END)\n"

%.o: %.c
				@printf $(COMPILING_O_LOG) $<
				@$(CC) $(CFLAGS) $(INC) $(LDFLAGS) -c $< -o $@

docker:
				@docker run -it --rm -v $(shell pwd):/project -w /project \
				epitechcontent/epitest-docker tcsh

exec:			$(NAME)
				@./$(NAME)

clean:
				@rm -f $(OBJ)
				@rm -f $(MAIN_OBJ)

fclean: 		clean
				@rm -f $(NAME)
				@printf "$(STYLE_ORANGE)🧽 $(NAME) was successfully cleaned\
				$(STYLE_END)\n"

re: 			fclean all

style:			fclean
				@echo "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)"
				@coding-style . .
				@cat coding-style-reports.log

tests_run:
			echo "pass"

criterion:
			echo "pass"

ftest:
			echo "pass"

custom:
			echo "pass"
