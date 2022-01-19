#!/bin/bash

bin=serialize

function invalid_args() {
	echo "Usage: $1 [-clean|-run|-valgrind]" 1>&2
	exit 1
}

case $# in
	1)
		if [ "$1" != "-clean" ] && [ "$1" != "-run" ] && [ "$1" != "-valgrind" ]
		then
			invalid_args $0
		fi
		;;
	0)
		;;
	*)
		invalid_args $0
		;;
esac

if [ "$1" = "-clean" ]
then
	rm -rf build
	exit 0
fi

cmake -Bbuild -H.
cd build
make

if [ "$1" = "-run" ]
then
	echo -e "\e[1m\e[94m--= Running ./$bin =--\e[0m"
	./$bin
elif [ "$1" = "-valgrind" ]
then
	echo -e "\e[1m\e[94m--= Running valgrind ./$bin ==-\e[0m"
	valgrind ./$bin
fi

cd ..
