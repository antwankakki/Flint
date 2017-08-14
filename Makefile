CC=g++
ARGS=-std=c++11 -Wall -Werror
ENTRY_FILE_PATH=./main.c

debug:
	$(CC) $(ARGS) -DDEBUG $(ENTRY_FILE_PATH) -o debug.exe

release:
	$(CC) $(ARGS) -DRELEASE $(ENTRY_FILE_PATH) -o release.exe

run:
	./`ls -t *.exe | head -n 1 | awk '{print $1}'`

clean:
	rm -f *.exe