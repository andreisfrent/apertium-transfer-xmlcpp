#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all \
    ./src/apertium-xml2cpp < samples/only_transfer.t1x
