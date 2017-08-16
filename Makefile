CC=g++
CHECKS=-Wall \
	-Werror \
	-Wclobbered \
	-Wempty-body \
	-Wignored-qualifiers \
	-Wmissing-field-initializers \
	-Wtype-limits \
	-Wuninitialized \
	-Wunused-parameter \
	-Wunused-but-set-parameter
ARGS=-std=c++11 $(CHECKS)
ENTRY_POINT_PATH=./main.cpp

debug:
	$(CC) $(ARGS) -g -DDEBUG $(ENTRY_POINT_PATH) -o debug.exe

release:
	$(CC) $(ARGS) -DRELEASE $(ENTRY_POINT_PATH) -o release.exe

run:
	./`ls -t *.exe | head -n 1 | awk '{print $1}'`

configure:
	chmod +x configure.sh
	sudo ./configure.sh

analyze:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes -v ./debug.exe

clean:
	rm -f *.exe
