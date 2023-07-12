# raylib-rpg
This repository is a C++ remake of old `raylib-rpg` (that was originally built using ANSI C)

## Build

To build this project, make sure to have CMake installed locally.

### Desktop

```
mkdir build
cd build
cmake ..
make  # or cmake --build .
```

### Web

```
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release
emmake make
```

## Run

```
./raylib-rpg
```