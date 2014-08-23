CXX = g++
CXXFLAGS = -g -Wall 

vpath %.cpp src

#sourcefile = main.cpp ArcInfoASCIIGenerator.cpp ArcInfoASCIIParser.cpp

sourcefile = $(wildcard src/*.cpp)

#objectfile = $(patsubst %.cpp, obj/%.o, $(sourcefile))

objectfile = $(patsubst %.cpp, %.o, $(patsubst src%, obj%, $(sourcefile)))


bin/spal3d: $(objectfile)
	$(CXX) -o $@ $(objectfile) 

#$(objectfile): | obj
#obj:
#	@mkdir -p $@

obj/%.o: %.cpp
#	@echo $<
	$(CXX) -c $^ -o $@ -Iinclude


.PHONY: clean cleanall 
clean:
	-rm -rf $(objectfile)
cleanall: 
	-rm -rf $(objectfile) bin/spal3d
