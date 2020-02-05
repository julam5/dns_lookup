src = main.cpp \
        dns_lookup.cpp


prog	:=dns_lookup
CXX		:=g++
INCLUDE	:=-I./

CXXFLAGS:=-O2 $(INCLUDE) -Wno-format -Wno-multichar -std=c++11

obj = $(src:.cpp=.o)

$(prog): $(obj)
	$(CXX) $(INCLUDE) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#%.o: %.cpp
#	$(CXX) -c $(CXXFLAGS) $<

.PHONY: clean
clean:
	rm -f $(obj) $(prog)

