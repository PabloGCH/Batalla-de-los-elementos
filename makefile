IDIR = headers
LIBS = lib
CC = g++
CFLAGS = -I$(IDIR)
LFLAGS = -L$(LIBS) -lSDL2 -lSDL2main -lSDL2_image
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
SOURCE = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCE))


src/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LFLAGS)

Bdle: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

clean:
	rm -f Bdle
	rm -f src/*.o
