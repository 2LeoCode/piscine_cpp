#!/bin/bash

bin=bureaucrat3

function invalid_args() {
	echo "Usage: $1 [-clean|-run]"
	exit 1
}

case $# in
	1)
		if [ "$1" != "-clean" ] && [ "$1" != "-run" ]
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
	./$bin
fi

cd ..
