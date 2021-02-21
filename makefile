IDIR = headers
LIBS = $(CURDIR)/lib
CC = g++
CFLAGS = -I$(IDIR) -lm -lSDL2main -lSDL2 -lSDL2_image
LFLAGS = -L$(LIBS)
_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
SOURCE = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCE))
EXECUTABLE = Bdle

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS) $(LFLAGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

clean:
	rm -f $(EXECUTABLE)
	rm -f src/*.o
