#!/bin/bash

if [ $# -lt 2 ]; then
  echo "Usage $0 src_class dst_class."
  exit -1
fi

if [ -f "ASTNode_$1.h" ] && [ -f "ASTNode_$1.cc" ]; then
  SRC_H="ASTNode_$1.h"
  SRC_CC="ASTNode_$1.cc"
  DST_H="ASTNode_$2.h"
  DST_CC="ASTNode_$2.cc"
  cp ${SRC_H} ${DST_H}
  cp ${SRC_CC} ${DST_CC}
  UPPER_SRC=`echo $1 | tr '[a-z]' '[A-Z]'`
  UPPER_DST=`echo $2 | tr '[a-z]' '[A-Z]'`
  sed -i ${DST_H} -e "s/$UPPER_SRC/$UPPER_DST/g" -e "s/$1/$2/g"
  sed -i ${DST_CC} -e "s/$1/$2/g"
else
  echo "$1 does not exist."
  exit -1
fi
