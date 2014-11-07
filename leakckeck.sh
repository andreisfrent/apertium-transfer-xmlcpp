#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all \
    ./src/apertium-xml2cpp < samples/intro.t1x
