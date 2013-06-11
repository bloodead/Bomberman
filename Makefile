NAME=	bomberman
SRC=	main.cpp	\
	sdl_init.cpp	\
	terrain_init.cpp\
	readsrc.cpp\
	menu.cpp\
	characters.cpp
G=	g++ -g
OBJS	=	$(SRC:.cpp=.o)
LFLAGS=	-lSDL -lSDL_image -lSDL_ttf


all: $(NAME)

$(NAME):	$(OBJS)
	$(G) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
	rm -rf $(OBJS)

distclean:	clean
	rm -rf $(NAME)

rebuild:	distclean all
