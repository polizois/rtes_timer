#!/bin/sh

file1="withoutCompensation"
file2="withCompensation"

gcc $file1.c -o $file1 -O3
gcc $file2.c -o $file2 -O3
