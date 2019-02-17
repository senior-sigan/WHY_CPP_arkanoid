all: clean prepare compile run

clean:
	rm -rf cmake-build-debug

dir:
	mkdir -p cmake-build-debug

reload: dir
	cd cmake-build-debug && cmake ..

compile:
	cd cmake-build-debug && make

start:
	cd cmake-build-debug && ./game