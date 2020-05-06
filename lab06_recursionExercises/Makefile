parens: main.o executive.o matchParenthesis.o permuteString.o fibonacci.o matchBraceBracketParen.o
	g++ -std=c++11 -g -Wall main.o executive.o matchParenthesis.o permuteString.o fibonacci.o matchBraceBracketParen.o -o parens
	cp parens perm
	cp perm fib
	cp parens parensV2

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.cpp executive.h
	g++ -std=c++11 -g -Wall -c executive.cpp	

matchParenthesis.o: matchParenthesis.cpp matchParenthesis.h
	g++ -std=c++11 -g -Wall -c matchParenthesis.cpp

permuteString.o: permuteString.cpp permuteString.h
	g++ -std=c++11 -g -Wall -c permuteString.cpp

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -std=c++11 -g -Wall -c fibonacci.cpp

matchBraceBracketParen.o: matchBraceBracketParen.cpp matchBraceBracketParen.h
	g++ -std=c++11 -g -Wall -c matchBraceBracketParen.cpp

clean:
	rm *.o parens perm fib parensV2
