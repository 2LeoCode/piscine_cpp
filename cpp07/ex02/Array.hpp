/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:41:18 by crochu            #+#    #+#             */
/*   Updated: 2021/11/08 01:37:02 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define Constructor Array
#define Destructor ~Array

#include <cstring>
#include <iostream>

template <typename T>
class Array {
	public:
		Constructor(unsigned size = 0) : _size(size), _arr(new T[size]) { }
		Destructor() { delete[] _arr; }

		Constructor(const Array< T > &other) :
		_size(other._size), _arr(new T[_size]) {
			memcpy(_arr, other._arr, _size * sizeof(T));
		}

		Array< T > &operator=(const Array< T > &other) {
			_size = other._size;
			delete[] _arr;
			_arr = new T[_size];
			memcpy(_arr, other._arr, _size * sizeof(T));
			return *this;
		}
		T &operator[](unsigned i) {
			if (i >= _size) throw EOutOfBounds();
			return _arr[i];
		}

		unsigned size(void) const { return _size; }
		void print(void) const {
			for (unsigned i = 0; i < _size; ++i)
				std::cout << '[' << _arr[i] << ']';
			std::cout << std::endl;
		}

		struct EOutOfBounds : public std::exception {
			const char *what() const throw() { return "Out of bounds"; }
		};

	private:
		unsigned	_size;
		T*			_arr;
};
