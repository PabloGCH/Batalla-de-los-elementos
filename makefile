CURRENT_DIR = $(shell pwd)
IDIR = headers
LIBS = $(CURRENT_DIR)/lib
CC = g++
CFLAGS = -I$(IDIR) -lm
LFLAGS = -L$(LIBS) -lSDL2main -lSDL2 -lSDL2_image
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
SOURCE = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCE))
EXECUTABLE = Bdle

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LFLAGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(EXECUTABLE)
	rm -f src/*.o
