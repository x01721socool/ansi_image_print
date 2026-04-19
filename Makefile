install: src/main.c
	gcc src/main.c -o main
	install -D main /usr/local/bin/ansifromimage

clean:
	rm main /usr/local/bin/ansifromimage
