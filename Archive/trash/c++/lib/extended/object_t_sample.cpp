#include "object_t.hpp"
#include <iostream>
#include <vector>
#include <memory>

using document_t = std::vector<object_t>;
class my {
public:
	void draw(std::ostream &out, size_t size) const {
		out << "HELLOb\n";	
	}
};
class my2 {
public:
	void draw(std::ostream &out, size_t size) const {
		out << "HELLOb\n";	
	}
};
void draw(const document_t &document, std::ostream &out, size_t cntr) {
	out << "<document>\n";
	for (const auto &x : document) {
		x.draw(out, cntr);
	}

	out << "</document>\n";
}
int main() {
	document_t document;
//	document.push_back(object_t(my()));
	document.emplace_back(my());

	document.emplace_back(my2());
	draw(document, std::cout, 0);
}
