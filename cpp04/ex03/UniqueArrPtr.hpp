/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniqueArrPtr.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:36:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 14:02:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template < typename T >
class UniqueArrPtr {
	public:
		UniqueArrPtr() : _ptr(NULL) { }
		~UniqueArrPtr() { delete[] _ptr; }
		UniqueArrPtr(T *ptr) : _ptr(ptr) { ptr->announce(); }
		UniqueArrPtr(const UniqueArrPtr &other)
		:	_ptr(const_cast< UniqueArrPtr& >(other)._ptr) { }

		UniqueArrPtr	&operator =(const UniqueArrPtr &other) {
			_ptr = const_cast< UniqueArrPtr& >(other)._ptr;
			return (*this);
		}
		UniqueArrPtr	&operator =(T *ptr) {
			_ptr = ptr;
			return (*this);
		}

		T			&operator *(void) { return *_ptr; }
		T			*operator ->(void) { return _ptr; }
		T			&operator [](unsigned i) { return _ptr[i]; }

	private:
		T	*_ptr;
};
