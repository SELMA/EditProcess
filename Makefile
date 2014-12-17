CC		= g++

RM		= rm -rf

PATH_SOURCES	= ./sources

CPPFLAGS	+= -Wextra -Wall -Werror
CPPFLAGS	+= -I./includes/

LDFLAGS		+= -lpsapi

NAME		= editProcess

SRCS		= $(PATH_SOURCES)/main.cpp	    \
		  $(PATH_SOURCES)/Tools.cpp	    \
		  $(PATH_SOURCES)/MyProcess.cpp

OBJS		= $(SRCS:.cpp=.o)


$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:		
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME).exe

re:		fclean all

.PHONY:		all clean fclean re