#!/bin/bash

bin=bureaucrat4

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

error=$(cmake -Bbuild -H. 2>&1 >/dev/null)

if [ ! -z "$error" ]
then
	echo "cmake is not installed, run sudo apt install cmake" 1>&2
	exit 1
fi

cd build
make

if [ "$1" = "-run" ]
then
	echo -e "\e[1m\e[94m--= Running ./$bin =--\e[0m"
	./$bin
elif [ "$1" = "-valgrind" ]
	echo -e "\e[1m\e[94m--= Running valgrind ./$bin ==-\e[0m"
	valgrind ./$bin
fi

cd ..
