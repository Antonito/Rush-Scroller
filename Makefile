##
## Makefile for gfx_scroller in /home/bache_a/work/Infographie/gfx_scroller
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Mar 18 19:26:18 2016 Antoine Baché
## Last update Fri Mar 18 21:20:41 2016 Antoine Baché
##

DEBUG=			yes

SRC_DEMO1_PREFIX=	src/demo1/

SRC_DEMO1_FILES=	main.c

SRC_DEMO1=		$(addprefix $(SRC_DEMO1_PREFIX),$(SRC_DEMO1_FILES))

DEMO1=			demo1

HEAD=			-Iinclude			\
			-I/home/${USER}/.froot/include

LIB=			-L/usr/local/lib		\
			-L/home/${USER}/.froot/lib	\
			-llapin 			\
			-lsfml-audio 			\
			-lsfml-graphics 		\
			-lsfml-window 			\
			-lsfml-system 			\
			-lstdc++ 			\
			-ldl 				\
			-lm

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror
endif

CC=			gcc

RM=			rm -f

OBJ_DEMO1=		$(SRC_DEMO1:.c=.o)

$(DEMO1): $(OBJ_DEMO1)
	@echo -n "Flags: "
	@echo $(CFLAGS)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled demo1"
	@$(CC) $(OBJ_DEMO1) -o $(DEMO1)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(DEMO1)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ_DEMO1)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(DEMO1)

re:	fclean all

.PHONY:	all clean fclean re
