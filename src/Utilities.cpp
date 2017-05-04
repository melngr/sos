#include "Utilities.h"
#include <string>

//compare strings a and b, ignoring case sensitivity
bool equalsIgnoreCase(const std::string& a, const std::string& b) {
	unsigned int aSize = a.size();
	if (b.size() != aSize) {
		return false;
	}
	for (unsigned int i = 0; i < aSize; ++i) {
		if (tolower(a[i]) != tolower(b[i])) {
			return false;
		}
	}
	return true;
}