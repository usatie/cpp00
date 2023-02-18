NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = *.cpp
OBJS = $(SRCS: %.o=%.cpp)

run: $(NAME)
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o
	$(RM) $(NAME)
