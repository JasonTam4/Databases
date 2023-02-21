main: main.cpp
	g++ --std=c++11 main.cpp request.cpp game.cpp -lcurl

clean:
	rm a.out