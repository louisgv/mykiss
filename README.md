# Mykiss data preprocessor

Mykiss is a data preprocessor that normalize and transform any dataset similar to Google's Open Image into a dataset that is comsumable by the Osprey machine learning model.

## Prerequisite

Mykiss requires:
	+ cmake
	+ conan

## Setup

1. Clone this repository

2. Provide a dataset similar to Openimage's "Image URLs and metadata" dataset.

3. Run:
```
mkdir build && cd build
conan install ..
```

## Announcements

+ 2017-07-30T10:10:32.269Z: Go does not play well with csv. Switch to C++
+ Tue Jul 25 22:10:12 2017: Project initialized

## References:

+ (Open Image dataset)[https://github.com/openimages/datasethttps://github.com/openimages/dataset]
