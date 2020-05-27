#!/bin/bash

find src/ -name '*.cpp'| xargs g++ -lubsan -I"./include" -o run \
	&& ./run \
	&& rm ./run
