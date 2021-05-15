BLD = build

CXX = g++ --std=c++17 -I ./build/

all: start

clean:
	rm -rf $(BLD)
	rm sum.cc

bld_dir:
	mkdir -p $(BLD)

start: bld_dir sum_creator.o sum.o main.o
	$(CXX) -o $(BLD)/sum.out $(BLD)/sum.o $(BLD)/main.o

main.o: main.cc
	$(CXX) -c -o $(BLD)/main.o main.cc

sum.o: sum.cc
	$(CXX) -c -o $(BLD)/sum.o sum.cc

sum_creator.o: sum_creator.cc
	$(CXX) sum_creator.cc -o $(BLD)/sum_creator.out
	./$(BLD)/sum_creator.out
