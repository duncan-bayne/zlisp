#!/bin/sh

# thanks to http://stackoverflow.com/questions/5920333/how-to-check-size-of-a-file

file=bin/zlisp.rom
maximumsize=16
actualsize=$(du -B 1 -A "$file" | cut -f 1)
if [ $actualsize -gt $maximumsize ]; then
    echo ERROR: ROM size exceeds $maximumsize bytes
    exit 1
else
    exit 0
fi
