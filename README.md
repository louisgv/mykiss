# Mykiss data preprocessor

Mykiss is a data preprocessor that normalize and transform any dataset similar to Google's Open Image into a dataset that is comsumable by the Osprey machine learning model.

## Prerequisite

Mykiss requires:
	+ cmake
	+ conan

## Setup

1. Clone this repository

2. Provide a dataset similar to Openimage's "Image URLs and metadata" dataset.

3. Setup:

```sh
mkdir build && cd build
conan install ..
```

4. Build:

```sh
# (win)
cmake .. -G "Visual Studio 14 Win64"
cmake --build . --config Release
```

```sh
# (linux, mac)
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

4. Run:

```sh
# Inside ./build
./bin/timer
```

## Announcements

+ 2017-07-31T00:25:10.533Z: Conan's public repository is very limited... Switch over to cpm
+ 2017-07-30T23:07:38.448Z: Setup conan
+ 2017-07-30T10:10:32.269Z: Go does not play well with csv. Switch to C++
+ Tue Jul 25 22:10:12 2017: Project initialized

## References:

+ (Open Image dataset)[https://github.com/openimages/datasethttps://github.com/openimages/dataset]
