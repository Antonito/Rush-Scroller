##
## Makefile for gfx_scroller in /home/bache_a/work/Infographie/gfx_scroller
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Mar 18 19:26:18 2016 Antoine Baché
## Last update Sun Mar 20 02:30:59 2016 Antoine Baché
##

DEBUG=			yes

SRC_DEMO_PREFIX=	src/

SRC_DEMO_FILES=		main.c				\
			context.c			\
			context/fire.c			\
			context/plasma.c		\
			context/sprite.c		\
			context/starfield.c		\
			context/ondulation.c		\
			context/damier.c		\
			context/scroller.c		\
			transition/fade.c		\
			transition/transition.c		\
			select.c			\
			free.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=		add_vec.c			\
			cast.c				\
			div_vec.c			\
			draw_transformed.c		\
			fill.c				\
			free2D.c			\
			interpolate.c			\
			load_font_ini.c			\
			mat_construct.c			\
			mult_mat.c			\
			mult_vec.c			\
			mult_vec_mat.c			\
			my_blit.c			\
			my_free.c			\
			my_malloc.c			\
			perspective.c			\
			rotate.c			\
			rotate2.c			\
			scale.c				\
			strlenSpace.c			\
			sub_vec.c			\
			surface.c			\
			tekpixel.c			\
			translate.c			\
			vec_construct.c			\
			vec_dot.c			\
			vec_length.c			\
			vec_normalize.c

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
			trigo.c				\
			tekpixel.c

ONDUL_PREFIX=		src/ondulation/

ONDUL_FILES=		cpy_pix.c			\
			main.c				\
			move_flag.c

SPRITE_PREFIX=		src/sprite/

SPRITE_FILES=		main.c				\
			sprite.c

STARFIELD_PREFIX=	src/starfield/

STARFIELD_FILES=	gen_star.c			\
			main.c				\
			starfield.c			\
			tekline.c

DAMIER_PREFIX=		src/damier/

DAMIER_FILES=		damier.c

SCROLLER_PREFIX=	src/scroller/

SCROLLER_FILES=		main.c


SRC_DEMO=		$(addprefix $(SRC_DEMO_PREFIX),$(SRC_DEMO_FILES))

SRC_TOOLS=		$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

SRC_FIRE=		$(addprefix $(FIRE_PREFIX),$(FIRE_FILES))

SRC_PLASMA=		$(addprefix $(PLASMA_PREFIX),$(PLASMA_FILES))

SRC_ONDULATION=		$(addprefix $(ONDUL_PREFIX),$(ONDUL_FILES))

SRC_SPRITE=		$(addprefix $(SPRITE_PREFIX),$(SPRITE_FILES))

SRC_STARFIELD=		$(addprefix $(STARFIELD_PREFIX),$(STARFIELD_FILES))

SRC_DAMIER=		$(addprefix $(DAMIER_PREFIX),$(DAMIER_FILES))

SRC_SCROLLER=		$(addprefix $(SCROLLER_PREFIX),$(SCROLLER_FILES))

SRC_DEMO+=		$(SRC_TOOLS)

SRC_DEMO+=		$(SRC_FIRE)

SRC_DEMO+=		$(SRC_PLASMA)

SRC_DEMO+=		$(SRC_SPRITE)

SRC_DEMO+=		$(SRC_STARFIELD)

SRC_DEMO+=		$(SRC_ONDULATION)

SRC_DEMO+=		$(SRC_DAMIER)

SRC_DEMO+=		$(SRC_SCROLLER)

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
