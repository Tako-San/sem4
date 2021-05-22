BLD = build

CXX = g++ --std=c++17 -I ./build/

all: start

clean:
	rm -rf $(BLD)
	rm output

bld_dir:
	mkdir -p $(BLD)

start: bld_dir first second third
	echo 'finish'

first: first.cc
	$(CXX) first.cc -o $(BLD)/fst.out
	$(BLD)/fst.out

second: second.cc
	$(CXX) second.cc -o $(BLD)/snd.out
	$(BLD)/snd.out

third: third.cc
	$(CXX) third.cc -o $(BLD)/thrd.out
	$(BLD)/thrd.out
