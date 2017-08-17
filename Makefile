CC=g++
CC_CHECKS= \
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
CC_FEATURE_SET=-std=c++0x
CC_ARGS= \
	$(CC_CHECKS) \
	$(CC_FEATURE_SET)
CC_ENTRY_POINT_PATH=./main.cpp

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
	$(CC) $(CC_ARGS) -g -DDEBUG $(CC_ENTRY_POINT_PATH) -o debug.exe

release:
	$(CC) $(CC_ARGS) -DRELEASE $(CC_ENTRY_POINT_PATH) -o release.exe

run:
	./`ls -t *.exe | head -n 1 | awk '{print $1}'`

configure:
	chmod +x configure.sh
	sudo ./configure.sh

analyze:
	$(SC_ANALYZER) $(SC_ARGS) $(SC_ENTRY_POINT_PATH)

clean:
	rm -f *.exe
