##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##


_SRC =			mysh/mysh.c \
				mysh/execute.c \
				mysh/input.c \
				mysh/parse.c \
				\
				builtins/cd.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/unsetenv.c \
				builtins/setenv.c \
				builtins/set.c \
				builtins/unset.c \
				builtins/var.c \
				\
				errors/get.c \
				errors/strerror.c \
				errors/strsignal.c \
				\
				types/node/new.c \
				types/node/free.c \
				types/node/unlink.c \
				\
				types/list/new.c \
				types/list/free.c \
				types/list/append.c \
				types/list/remove.c \
				\
				types/cmd/free.c \
				types/cmd/display.c \
				types/cmd/target/target.c \
				types/cmd/target/builtin.c \
				types/cmd/target/system.c \
				types/cmd/target/absolute.c \
				types/cmd/target/empty.c \
				types/cmd/args/get_len.c \
				types/cmd/args/set_args.c \
				types/cmd/new.c \
				\
				types/io/free.c \
				types/ios/free.c \
				\
				types/var/free.c \
				types/var/new.c \
				types/var/set.c \
				types/var/list/get.c \
				types/var/list/set.c \
				\
				types/inst/new.c \
				types/inst/free.c \
				types/inst/append.c \
				types/inst/block/free.c \
				types/inst/block/new.c \
				\
				types/parsing_utils/free.c \
				types/parsing_utils/new.c \
				\
				types/input_line/refresh.c \
				types/input_line/delete_char.c \
				types/input_line/handlers/cursor.c \
				types/input_line/handlers/keypressed.c \
				types/input_line/handlers/history.c \
				types/input_line/new.c \
				types/input_line/append_char.c \
				types/input_line/input_line.c \
				types/input_line/iscntrl.c \
				types/input_line/mode.c \
				\
				types/shell/new.c \
				types/shell/free.c \
				types/shell/input.c \
				types/shell/format/format.c \
				types/shell/format/get_no_var.c \
				types/shell/format/get_var.c \
				types/shell/io.c \
				types/shell/exit.c \
				types/shell/prompt.c \
        		types/shell/vars/vars.c \
				types/shell/vars/special/std.c \
				types/shell/vars/special/init.c \
				types/shell/vars/special/home.c \
				types/shell/vars/special/dispatch_env_update.c \
				\
				types/history/new.c \
				types/history/free.c \
				types/history/entry/new.c \
				types/history/entry/free.c \
				types/history/append.c \
				types/history/current.c \
				types/history/clear.c \
				types/history/move.c \
				\
				utils/is_number.c \
				utils/malloc2.c \
				utils/asprintf2.c \
				\
				parsing/redirection/get_redirection.c \
				parsing/redirection/set_path.c \
				parsing/redirection/set_type.c \
				parsing/get_cmd.c \
				parsing/get_word.c \
				parsing/parsing.c \
				parsing/recursivity.c \
				parsing/analyse_data.c \
				parsing/utils/utils.c \
				parsing/utils/display.c \
				parsing/pipes.c \
				parsing/separator/utils.c \
				parsing/separator/separator.c \
				parsing/append.c \
				\
				execution/block/block.c \
				execution/cmd/absolute.c \
				execution/cmd/builtin.c \
				execution/cmd/can_be_done.c \
				execution/cmd/error.c \
				execution/cmd/prepare.c \
				execution/cmd/launch.c \
				execution/inst/fd/fd.c \
				execution/inst/fd/parent.c \
				execution/inst/fork.c \
				execution/inst/inst.c \
				execution/inst/launch.c \
				execution/inst/previous.c \
				execution/redirections/error.c \
				execution/redirections/input_double.c \
				execution/redirections/input.c \
				execution/redirections/output.c \
				execution/redirections/redirections.c \
				execution/execution.c \
				execution/utils.c \

_TESTS =		criterion/types/list.c \
				criterion/types/node.c \
				criterion/types/io.c \
				criterion/types/ios.c \
				criterion/types/var.c \
				criterion/types/shell/shell.c \
				criterion/types/shell/input.c \
				criterion/types/shell/format.c \
				criterion/types/shell/io.c \
				criterion/types/shell/vars.c \
				criterion/types/inst/inst.c \
				criterion/types/inst/block.c \
				criterion/types/cmd/cmd.c \
				criterion/types/cmd/target.c \
				criterion/types/history/history.c \
				criterion/types/history/entry.c \
				criterion/types/history/append.c \
				criterion/types/cmd/set_args.c \
				\
				criterion/utils/is_number.c \
				criterion/utils/malloc2.c \
				criterion/utils/asprintf2.c \
				\
				criterion/builtins/exit.c \
				criterion/builtins/env.c \
				criterion/builtins/cd.c \
				criterion/builtins/unsetenv.c \
				criterion/builtins/setenv.c \
				criterion/builtins/set.c \
				criterion/builtins/unset.c \
				criterion/builtins/var.c \
				\
				criterion/errors/get.c \
				criterion/errors/strerror.c \
				criterion/errors/strsignal.c \
				\
				criterion/parsing/redirection.c \
				criterion/parsing/separator.c \
				criterion/parsing/pipe.c \
				criterion/parsing/get_word.c \
				criterion/parsing/utils.c \
				criterion/parsing/get_cmd.c \
				criterion/parsing/parsing.c \
				\
				criterion/execution/redirections/input_double.c \
				criterion/execution/redirections/input.c \
				criterion/execution/redirections/output.c \
				criterion/execution/redirections/error.c \
				criterion/execution/redirections.c \
				criterion/execution/block.c \
				criterion/execution/cmd/absolute.c \
				criterion/execution/cmd/builtin.c \
				criterion/execution/cmd/prepare.c \
				criterion/execution/cmd/launch.c \
				criterion/execution/cmd/can_be_done.c \
				criterion/execution/inst/fd.c \
				criterion/execution/inst/fork.c \
				criterion/execution/inst/inst.c \
				criterion/execution/inst/launch.c \
				criterion/execution/execution.c \

SRCDIR = 		sources/
SRC =			$(addprefix $(SRCDIR), $(_SRC))
MAIN =			$(addprefix $(SRCDIR), main.c)
MAIN_OBJ =		$(MAIN:.c=.o)
SRC_OBJ = 		$(SRC:.c=.o)

SRC_COVER =		$(SRC:.c=.gcno)
SRC_PRFL =		$(SRC:.c=.gcda)

TESTSDIR = 		tests/
TESTS_UTILS = 	$(TESTSDIR)/utils/
TESTS =			$(addprefix $(TESTSDIR), $(_TESTS))
TESTS_OBJ = 	$(TESTS:.c=.o)
TESTS_CFLAGS =	-lcriterion --coverage

INC = 			-I.. -I./includes
CFLAGS +=		-Wall -Wextra -Werror -Wno-unused-command-line-argument -g

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

.PHONY: all clean fclean re

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
				@make -C $(TESTS_UTILS) clean -s

fclean: 		clean
				@rm -f $(NAME)
				@rm -f $(TESTS_NAME)
				@printf "$(STYLE_ORANGE)🧽 $(NAME) was successfully cleaned\
				$(STYLE_END)\n"
				@make -C $(TESTS_UTILS) fclean -s

re: 			fclean all

style:			fclean
				@printf "$(STYLE_RED)🔍 Checking coding style...$(STYLE_END)\n"
				@coding-style . .
				@cat coding-style-reports.log

tests_criterion: fclean
				@printf "$(STYLE_RED)🧪 Tests utils compliation...\
				$(STYLE_END)\n"
				@make -C $(TESTS_UTILS) criterion_utils -s
				@printf "$(STYLE_RED)🧪 Tests compliation...$(STYLE_END)\n"
				@$(MAKE) objects CFLAGS+=--coverage -s
				@$(MAKE) tests_objects -s
				@$(CC) -o $(TESTS_NAME) $(SRC_OBJ) $(TESTS_OBJ) \
				$(LDFLAGS) $(CFLAGS) $(INC) $(TESTS_CFLAGS)
				@printf "$(STYLE_GREEN)✅ Tests were successfully built\
				$(STYLE_END)\n"
				@./$(TESTS_NAME)

ftest:			$(NAME)
				@echo "pass"

tests_custom:	$(NAME)
				@./$(TESTS_CUSTOM)
				@echo "pass"

tests_run:
				@$(MAKE) tests_criterion -s

coverage:
				@gcovr

coverage_branch:
				@gcovr --branch
