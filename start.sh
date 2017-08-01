#!/usr/bin/env bash
cmake .
make
./build/bin/Mykiss ./sample.csv
