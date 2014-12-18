# Edit these on update
VERSION=0.0.1
### Shouldn't need to edit below here ###
CPPFLAGS=-Iinclude -std=c++1y -c -g -O0
DEBUGCFLAGS=$(CFLAGS)
RELEASECFLAGS=$(CFLAGS)
LDFLAGS=-arch x86_64 -macosx_version_min 10.10 -lc++ -lc
DEBUGLDFLAGS=$(LDFLAGS)
RELEASELDFLAGS=$(LDFLAGS)
CC=cc
LD=ld

vpath %.o build
vpath %.c src
vpath %.h include
vpath %.dylib build
vpath redpapercliptest build

sources := $(patsubst src/%,%,$(wildcard src/*.c))
objects := $(patsubst %.c,%.o,$(sources))
debugobjects := $(patsubst %.c,%-debug.o,$(sources))
testsources := $(wildcard t/*.c)
%-debug.o: %.c
	$(CC) $(DEBUGCFLAGS) $^ -o build/$@
%.o: $.c
	$(CC) $(RELEASECFLAGS) $^ -o build/$@
modernc-debug.dylib: $(debugobjects)
	$(LD) $(DEBUGLDFLAGS) $^ -o build/$@
modernc.dylib: $(sources)
	$(LD) $(RELEASELDFLAGS) $^ -o build/$@
release: modernc.dylib
debug: modernc-debug.dylib
modernctest: debug 
	$(CC) -
test: redpapercliptest
	build/redpapercliptest
# Housekeeping
clean:
	rm -f build/*/*.o
.PHONY: clean test
all: release

vpath %.o build
vpath %.cpp src
vpath %.h include
vpath %.dylib build

build:
	mkdir -p build/{core,qt}
%.o: %.cpp
	clang++ $(CPPFLAGS) -o build/$@ $^
rpnow: core/main.o core/CommandReader.o core/Interpreter.o qt/backend.o qt/glue.o
	ld $(LDFLAGS) -o $@ $^
rp: rpnow build
all: main.o
# main.o:
# 	gcc
# main: 

