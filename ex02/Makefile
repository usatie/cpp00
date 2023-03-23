NAME = program

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

# diff <(awk '{print $2}' 19920104_091532.log) <(./program | awk '{print $2}')

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	$(RM) *.o
	$(RM) $(NAME)
