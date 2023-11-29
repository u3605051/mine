FLAGS = -pedantic-errors -std=c++11

mechanics.o: mechanics.cpp mechanics.h display.h score.h
	g++ $(FLAGS) -c $<

display.o: display.cpp display.h mechanics.h
	g++ $(FLAGS) -c $<

main.o: main.cpp display.h mechanics.h
	g++ $(FLAGS) -c $<

score.o: score.cpp score.h

game: main.o mechanics.o display.o score.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f game score.o main.o display.o mechanics.o *.txt
	touch scoreboard.txt
tar:
	tar -czvf game.tgz *.cpp *.h
.PHONY: clean tar
