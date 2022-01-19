/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 03:13:39 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 03:51:43 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"
#include <cstring>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cctype>

void expect(const char *tok, std::istream &in) {
	size_t tok_len(strlen(tok));
	static std::string buf;
	static std::string::const_iterator cursor(buf.begin());

	while (true) {
		if (cursor == buf.end()) {
			if (!std::getline(in, buf)) {
				if (in.eof()) throw MO::EExpectedToken(tok);
				else throw std::runtime_error("Read error");
				cursor = buf.begin();
			}
		}
		while (isspace(*cursor)) ++cursor;
		if (!buf.compare(cursor - buf.begin(), buf.end() - cursor, tok))
			break ;
		if (cursor != buf.end())
			throw MO::EExpectedToken(tok);
	}
}

MO::Constructor() {
	std::ifstream config("moconf.json");

	expect("[", config);
	expect("\"MindOpen Configuration File\"", config);
	expect(",", config), expect("{", config);
	expect("\"increment_pointer\"", config), expect(":", config);
}
