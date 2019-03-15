all: clean reload compile start

web: clean-web reload-web compile-web start-web

clean:
	rm -rf cmake-build-debug

dir:
	mkdir -p cmake-build-debug

reload: dir
	cd cmake-build-debug && cmake ..

compile:
	cd cmake-build-debug && make -j4

start:
	cd cmake-build-debug && ./game

clean-web:
	rm -rf cmake-build-debug-web

dir-web:
	mkdir -p cmake-build-debug-web

reload-web: dir-web
	cd cmake-build-debug-web && emcmake cmake ..

compile-web:
	cd cmake-build-debug-web && make -j4

start-web:
	cd cmake-build-debug-web && python -m http.server
