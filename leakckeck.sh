#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all \
    ./src/apertium-xml2cpp < samples/en-es.t1x
