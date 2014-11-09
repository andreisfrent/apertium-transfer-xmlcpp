#!/bin/bash

find ..  -path ../include -prune -o -type f -name '*.h' -print | \
    sed -e 's/^/#include "/g' -e 's/$/"/g' > apertium_xml2cpp.h
