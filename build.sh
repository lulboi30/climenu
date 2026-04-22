#! /bin/bash

mkdir bin

echo "Building Shared Object"

gcc -c -std=c99 -fPIC climenu/climenu.c -o bin/climenu.o
gcc -shared bin/climenu.o -o bin/climenu.so
rm bin/climenu.o

echo "Building Static Object"

gcc -c -std=c99 climenu/climenu.c -o bin/climenu.o
ar rcs bin/climenu.a bin/climenu.o
rm bin/climenu.o

echo "Copy Header To 'bin' Folder? [y/n]"
read x

case $x in
	y)
		cp climenu/climenu.h bin/
		;;
	n)
		;;
	*)
		echo "Choose 'y' Or 'n'!"
		;;
esac

echo "Build Examples? [y/n]"
read x

case $x in
	y)
		gcc -std=c99 -I climenu climenu/climenu.c examples/RiggedRockPaperScissors.c -o bin/RiggedRockPaperScissors
		;;
	n)
		;;
	*)
		echo "Choose 'y' Or 'n'!"
		;;
esac
