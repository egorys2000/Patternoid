#! /bin/sh

for f in img/*.jpg
do
    echo "Processing file $f..."
    build/src/Patternoid $f
done
