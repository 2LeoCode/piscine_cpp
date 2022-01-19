/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniquePtr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:36:20 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 02:48:20 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define UP UniquePtr
#define Constructor UP
#define Destructor ~UP

template < typename T >
class UniquePtr {
	public:
		Constructor(T *ptr = 0) : _ptr(ptr) { }
		Destructor() { delete _ptr; }

		UniquePtr &operator=(UniquePtr &other) {
			_ptr = other._ptr;
			return *this;
		}
		UniquePtr &operator=(T *ptr) {
			_ptr = ptr;
			return *this;
		}
		T &operator*(void) { return *_ptr; }
		T *operator->(void) { return _ptr; }
		bool operator bool(void) const { return _ptr; }

		T *ptr(void) { return _ptr; }

	private:
		T	*_ptr;
};
