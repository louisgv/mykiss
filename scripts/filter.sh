#!/usr/bin/env bash

source .env;

PATH_TO_DATA=${PATH_TO_DATA:-'./sample.csv'}

cmake ./filter/
make
./build/bin/filter $PATH_TO_DATA
