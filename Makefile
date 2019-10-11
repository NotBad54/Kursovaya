CC = g++
EXECUTABLE = bin/main.out
CFLAGS = -Wall -c -std=c++11
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))
TEST_SOURCES = $(wildcard $(addprefix test/, *.cpp))
TEST_OBJECTS = $(patsubst $(addprefix test/, %.h),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.h))) $(patsubst $(addprefix test/, %.cpp),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.cpp)))
TEST_EXECUTABLE = bin/test.out

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@ -std=c++11

build/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ 

.PHONY : clean
clean:
	rm -f build/*.o build/*.d bin/*.out

.PHONY : test
test : $(TEST_SOURCES) $(TEST_EXECUTABLE)
	cd bin && ./test.out

$(TEST_EXECUTABLE) : $(TEST_OBJECTS)
	$(CC) $^ -o $@ -std=c++11

build/%_test.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

build/%.o : test/%.cpp
	$(CC) $(CFLAGS) $< -o $@