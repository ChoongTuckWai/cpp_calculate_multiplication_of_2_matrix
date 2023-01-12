all: builds run

init:
	mkdir -p build; \
	cd build; \
	cmake .. -DCMAKE_TOOLCHAIN_FILE="~/vcpkg/scripts/buildsystems/vcpkg.cmake"

builds:
	cmake --build build

run:
	./build/main

clean:
	rm -rf build