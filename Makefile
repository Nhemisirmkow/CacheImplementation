LINK_TARGET = main

OBJS =  \
 cache.o \
 main.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean:
		rm -f $(REBUILDABLES)
		echo Clean done

all : $(LINK_TARGET)
		echo All done

$(LINK_TARGET) : $(OBJS)
		g++ -std=c++14 -g -o $@ $^

%.o : %.cpp
		g++ -std=c++14 -g -o $@ -c $<

main.o : main.cpp cache.h
cache.o : cache.h
