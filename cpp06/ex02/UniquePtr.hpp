/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:58:16 by crochu            #+#    #+#             */
/*   Updated: 2021/11/06 17:14:40 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template <typename T>
class UniquePtr {
	public:
		UniquePtr(T *ptr = NULL) : _ptr(ptr) { }
		UniquePtr(UniquePtr &other) : _ptr(other._ptr) { }
		~UniquePtr() { delete _ptr; }

		UniquePtr &operator=(UniquePtr &other) {
			_ptr = other._ptr;
			return *this;
		}
		UniquePtr &operator=(T *ptr) {
			_ptr = ptr;
			return *this;
		}
		T *operator->(void) { return _ptr; }
		T &operator*(void) { return *_ptr; }

		T *ptr() { return _ptr; }

	private:
		T *_ptr;
};