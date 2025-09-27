CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = typeIdentifier
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re