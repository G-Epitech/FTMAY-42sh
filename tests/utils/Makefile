##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

STYLE_GREEN=\033[0;32m
STYLE_ORANGE=\033[0;33m
STYLE_RED=\033[0;31m
STYLE_BLUE=\033[0;34m
STYLE_GREY=\033[0;30m
STYLE_BOLD=\033[1m
STYLE_END=\033[0m

COMPILING_O_LOG = "$(STYLE_BLUE)📑 Compiling tests utils -\
$(STYLE_BOLD)$(STYLE_BOLD)[%s]$(STYLE_END)\n"

all: 	my_sig set_files_permissions

my_sig:
		@printf $(COMPILING_O_LOG) my_sig.c
		@$(CC) -o my_sig.out my_sig.c

clean:
		@rm -rf my_sig.out

fclean: clean

set_files_permissions:
		@chmod 444 forbidden-wx.txt
		@chmod 676 sh/allowed-grp.sh
		@chmod 667 sh/allowed-oth.sh
		@chmod 766 sh/allowed-usr.sh
		@chmod 644 sh/forbidden.sh
		@chmod 777 bin/bin-linux.bin
		@chmod 777 bin/bin-macos.bin