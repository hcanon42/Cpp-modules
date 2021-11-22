##---------------------------------MAKEFILE-------------------------------------

#====================================OBJS=======================================
OBJS		=	${SRCS:.cpp=.o}


#====================================SRCS=======================================
SRCS			=	main.cpp


#=============================FLAGS AND COMPILERS===============================
CCPP			=	clang++
CPPFLAGS		=	-Wall -Wextra -Werror -I ./
NAME			=	true_type


#================================AVAILABLE RULES================================
#-----
$(NAME):	${OBJS}
		${CCPP} ${CPPFLAGS} -o ${NAME} ${OBJS}

#-----
all:		$(NAME)

#-----
clean:
		rm -f ${OBJS}

#-----
fclean:		clean
		rm -f ${NAME}

#-----
re:		fclean ${NAME}

#-----
.PHONY:		all clean fclean re
