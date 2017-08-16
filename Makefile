CC=g++
ARGS=-std=c++11 -Wall -Werror
ENTRY_FILE_PATH=./main.cpp

debug:
	$(CC) $(ARGS) -g -DDEBUG $(ENTRY_FILE_PATH) -o debug.exe

release:
	$(CC) $(ARGS) -DRELEASE $(ENTRY_FILE_PATH) -o release.exe

run:
	./`ls -t *.exe | head -n 1 | awk '{print $1}'`

configure:
	chmod +x configure.sh
	sudo ./configure.sh

analyze:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes ./debug.exe

clean:
	rm -f *.exe
