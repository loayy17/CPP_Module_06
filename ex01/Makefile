CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Serializer.cpp Data.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = serializer
${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: re fclean clean all