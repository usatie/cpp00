NAME = program

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp
OBJS = $(SRCS: %.o=%.cpp)

run: $(NAME)
	./$(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o
	$(RM) $(NAME)
