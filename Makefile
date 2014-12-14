CC		= g++

RM		= rm -rf

CPPFLAGS	+= -Wextra -Wall -Werror
CPPFLAGS	+= -I.

LDFLAGS		+= -lpsapi

NAME		= editProcess

SRCS		= main.cpp	\
		  Tools.cpp	\
		  MyProcess.cpp

OBJS		= $(SRCS:.cpp=.o)


$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME).exe

re:		fclean all

.PHONY:		all clean fclean re