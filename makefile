EXE=test.exe

all: dirtree
	$(CXX) -std=c++11 -I.. -o bin/$(EXE) src/example.cpp 

dirtree:
	@mkdir -p bin

clean:
	rm -f bin/$(EXE)

cleanall:
	rm -rf bin obj