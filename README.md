# raylib-cpp-rpg
[![Static analysis](https://github.com/s-ionut/raylib-cpp-rpg/actions/workflows/clang-tidy.yml/badge.svg)](https://github.com/s-ionut/raylib-cpp-rpg/actions/workflows/clang-tidy.yml)   
This repository is a C++ remake of old `raylib-rpg` (that was originally built using ANSI C)

## Build

To build this project, make sure to have CMake installed locally.

### VSCode

If you have VSCode installed you can Build/Install/Run the project using 3 available tasks
```
CTRL+SHIFT+P
Select Run Task
Choose between 3 available tasks:
 - Build
 - Build & Install
 - Run
```

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
