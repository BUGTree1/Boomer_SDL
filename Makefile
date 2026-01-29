CXX = g++
CXXFLAGS = -Isrc -I/usr/include/dbus-1.0 -I/usr/lib64/dbus-1.0/include -lSDL3 -Wall -Wextra -O3 -std=c++17 -Wno-unused-parameter

OUT_DIR    = bin
CXX_SRC    = src/boomer.cpp
CXX_OUT    = $(OUT_DIR)/boomer

test: build
	$(CXX_OUT)

build: $(CXX_OUT)

$(CXX_OUT): $(CXX_SRC) $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $(CXX_SRC) -o $(CXX_OUT)

$(OUT_DIR):
	mkdir $(OUT_DIR) || echo directory bin created
