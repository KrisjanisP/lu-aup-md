# run in root directory!
rm -fr ./build && cmake -S src -B build && cmake --build build --verbose && cd build && ctest -V && cd ..