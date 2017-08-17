CXX=g++
CXX_CHECKS= \
	-Wall \
	-Werror \
	-Wclobbered \
	-Wempty-body \
	-Wignored-qualifiers \
	-Wmissing-field-initializers \
	-Wtype-limits \
	-Wuninitialized \
	-Wunused-parameter \
	-Wunused-but-set-parameter
CXX_FEATURE_SET=-std=c++0x
CXX_ARGS= \
	$(CXX_CHECKS) \
	$(CXX_FEATURE_SET)
CXX_ENTRY_POINT_PATH=./main.cpp

SC_ANALYZER=valgrind
SC_CHECKS= \
	--tool=memcheck \
	--leak-check=yes \
	--show-reachable=yes \
	--num-callers=20 \
	--track-fds=yes \
	--track-origins=yes \
	-v
SC_ARGS=$(SC_CHECKS)
SC_ENTRY_POINT_PATH=./debug.exe

debug:
	$(CC) $(CXX_ARGS) -g -DDEBUG $(CXX_ENTRY_POINT_PATH) -o debug.exe

release:
	$(CC) $(CXX_ARGS) -DRELEASE $(CXX_ENTRY_POINT_PATH) -o release.exe

production:
	$(CC) $(CXX_ARGS) $(CXX_ENTRY_POINT_PATH) -o production.exe

run:
	./`ls -t *.exe | head -n 1 | awk '{print $1}'`

configure:
	chmod +x configure.sh
	sudo ./configure.sh

analyze:
	$(SC_ANALYZER) $(SC_ARGS) $(SC_ENTRY_POINT_PATH)

clean:
	rm -f *.exe
