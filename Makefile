##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

_SRC =

_TESTS =		criterion/example/simple.c

SRCDIR = 		sources/
SRC =			$(addprefix $(SRCDIR), $(_SRC))
MAIN =			$(addprefix $(SRCDIR), main.c)
MAIN_OBJ =		$(MAIN:.c=.o)
SRC_OBJ = 		$(SRC:.c=.o)

SRC_COVER =		$(SRC:.c=.gcno)
SRC_PRFL =		$(SRC:.c=.gcda)
TESTS_COVER =	$(TESTS:.c=.gcno)
TESTS_PRFL =	$(TESTS:.c=.gcda)

TESTSDIR = 		tests/
TESTS =			$(addprefix $(TESTSDIR), $(_TESTS))
TESTS_OBJ = 	$(TESTS:.c=.o)
TESTS_CFLAGS =	-lcriterion --coverage

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
TESTS_NAME = 	42sh_tests

TESTS_CUSTOM = tests/custom/launch.py

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

objects:		$(SRC_OBJ)

tests_objects:	$(TESTS_OBJ)

clean:
				@rm -f $(MAIN_OBJ)
				@rm -f $(SRC_OBJ)
				@rm -f $(SRC_COVER)
				@rm -f $(SRC_PRFL)
				@rm -f $(TESTS_OBJ)
				@rm -f $(TESTS_COVER)
				@rm -f $(TESTS_PRFL)

fclean: 		clean
				@rm -f $(NAME)
				@rm -f $(TESTS_NAME)
				@printf "$(STYLE_ORANGE)🧽 $(NAME) was successfully cleaned\
				$(STYLE_END)\n"

re: 			fclean all

style:			fclean
				@printf "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)"
				@coding-style . .
				@cat coding-style-reports.log

criterion:
				@printf "$(STYLE_RED)🧪 Tests compliation...$(STYLE_END)\n"
				@$(MAKE) objects CFLAGS+=--coverage
				@$(MAKE) tests_objects CFLAGS+=--coverage
				@$(CC) -o $(TESTS_NAME) $(SRC_OBJ) $(TESTS_OBJ) \
				$(LDFLAGS) $(CFLAGS) $(INC) $(TESTS_CFLAGS)
				@printf "$(STYLE_GREEN)✅ Tests was successfully built\
				$(STYLE_END)\n"
				@./$(TESTS_NAME)

ftest:			$(NAME)
				@echo "pass"

custom:			$(NAME)
				@./$(TESTS_CUSTOM)
				@echo "pass"

tests_run: 		criterion
