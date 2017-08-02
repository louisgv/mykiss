# The source structure of the C++ project

Since we can do a mono-repo project hierarchy, it is best to have the runnable binary in the root folder so we can run them like so : `./run.sh`

To achieve this, we can study the structure of our current project. If we put everything escape 3rdparty, dotfiles, config files, we can technically invoke the binary build per each process separately. The reason we do so is to avoid overwhelming the 2nd process. We only need to download the image once.

Following googletest structure, we should have all module/process on a flat root directory structure. The only drawback is that we will need to include them manually into our `.clang_complete` whenever a new module is created, similar to our 3rdparty.

We decided to move all shell script into the scripts directory. This will make the path somewhat ugly and confusing, but it will make the project structure a bit more sane. Also this follows the convention from googletest

The structure works. With this, each module will output its separated binary in build/bin. Whereas when needed they all consume binary library. We don't have to plague each with its own CMakeFiles.

We decided to remove linting target. It is fairly useless when you can already configure your editor to lint the code. Furthermore, clang_complete does a fair job with uncrustify to beautify the code.

# What is the total size of all the image in the data set?

We can calculate this using the first process.

Here are insight into the meta data:

```
790339 images
6.8e+06 MB ~ 7TB of images
4.1e+04 ms ~ 40000ms / 40s
```

# Do we need unit test?

... well if someone pay us, sure! Are we gonna do it?... well when we need it.

# Processes needed for Mykiss

+ Argument needed should include a $WORK directory, else space will run out.

1. A process to filter out data by file size and save them into $WORK/data.csv
2. A process to download all the images into $WORK/high/{name}, concurrently
3. A process to process the image into a compressed version that follow RAISR

In total, we need:

## Filter

+ The Filter would take in 2 argumnent, the first being the sample data, the second the location $WORK

+ The Filter will go through all the metadata, if the size is higher 6.3MB or size > 6,300,000

## Downloader

## Compressor

# How to process rach row of data without running out of memory?

1. Using a stream

2. Read by line

3. Multiple thread with logging of finished id

# What algorithm should be used for compressing the img?

# Naming convention for input and output set

# What info is necessary for reconstructing the original img?
