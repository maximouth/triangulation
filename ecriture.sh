#!/bin/bash

tag=31 

while true; do
    read x < $1
    echo $x $tag $1
    if [$x -eq $tag]
    then
	echo $tag > $1
    fi
    echo "fin boucle"
done
