# Mykiss data preprocessor

Mykiss is a data preprocessor that normalize and transform any dataset similar to Google's Open Image into a dataset that is comsumable by the Osprey machine learning model.

---

## Prerequisite

Mykiss requires:
	+ git
	+ cmake
	+ make

---

## Setup

1. Clone this repository

2. Provide a dataset similar to Openimage's "Image URLs and metadata" dataset.

3. Setup:

```sh
chmod +x ./scripts/*.sh

cp .env.sample .env
```

Edit `.env` to fit your environment.

4. Run Filter module:

```sh
./scripts/filter.sh
```

---

## Hacking

### Add a new module

1. Duplicate one of the module, e.g `filter`
2. Change all its name occurrence. (This can be automated later actually...)
3. Add a script to compile and run the module, look at `filter.sh` for example.

### Add a new 3rd party submodules

1. Find the git repo link, note its, e.g `helloworld`
2. Do `git submodule add git@github.com:user/helloworld.git 3rdparty/helloworld`
3. If the third party is a small library and its include path is in the root, then you are done. Else, add the include path to `.clang_complete`, using the same syntax.

---

## Announcements

+ 2017-08-02T05:11:49.823Z: Refactor into a monorepo project structure
+ 2017-07-31T02:42:21.697Z: Switch over from a pm to use git submodules.
+ 2017-07-31T00:25:10.533Z: Conan's public repository is very limited... Switch over to cpm
+ 2017-07-30T23:07:38.448Z: Setup conan
+ 2017-07-30T10:10:32.269Z: Go does not play well with csv. Switch to C++
+ Tue Jul 25 22:10:12 2017: Project initialized

---

## References:

+ [Open Image dataset](https://github.com/openimages/datasethttps://github.com/openimages/dataset)

+ [CPP Basic Project](https://github.com/marinsky/cpp_basic_project_setup)
