##
## Makefile for gfx_scroller in /home/bache_a/work/Infographie/gfx_scroller
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Mar 18 19:26:18 2016 Antoine Baché
## Last update Sat Mar 19 14:06:01 2016 Antoine Baché
##

DEBUG=			yes

SRC_DEMO_PREFIX=	src/

SRC_DEMO_FILES=		main.c				\
			context.c			\
			context/fire.c			\
			free.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=		my_malloc.c			\
			my_free.c			\
			free2D.c			\
			tekpixel.c			\
			my_blit.c			\
			fill.c

FIRE_PREFIX=		src/fire/

FIRE_FILES=		display_fire.c			\
			fire_calcul.c			\
			key_mod.c			\
			main.c				\
			music_settings.c		\
			palette.c			\
			random_lines.c

PLASMA_PREFIX=		src/plasma/

PLASMA_FILES=		check_args.c			\
			main.c				\
			new_frame.c			\
			set_palette.c			\
			tekpixel.c

ONDUL_PREFIX=		src/ondulation/

ONDUL_FILES=		check_args.c			\
			main.c				\
			new_frame.c			\
			set_palette.c			\
			tekpixel.c

SRC_DEMO=		$(addprefix $(SRC_DEMO_PREFIX),$(SRC_DEMO_FILES))

SRC_TOOLS=		$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

SRC_FIRE=		$(addprefix $(FIRE_PREFIX),$(FIRE_FILES))

SRC_PLASMA=		$(addprefix $(PLASMA_PREFIX),$(PLASMA_FILES))

SRC_ONDULATION=		$(addprefix $(ONDUL_PREFIX),$(ONDUL_FILES))

SRC_DEMO+=		$(SRC_TOOLS)

SRC_DEMO+=		$(SRC_FIRE)

SRC_DEMO+=		$(SRC_PLASMA)

DEMO=			demoEtDesLettres

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

OBJ_DEMO=		$(SRC_DEMO:.c=.o)

$(DEMO): $(OBJ_DEMO)
	@echo -n "Flags: "
	@echo $(CFLAGS)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled demo"
	@$(CC) $(OBJ_DEMO) -o $(DEMO) $(LIB)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(DEMO)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ_DEMO)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(DEMO)

re:	fclean all

.PHONY:	all clean fclean re
