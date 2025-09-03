#include "data.h"

namespace dj {
	//Default constructor
	Data::Data() {
		name = "";
		mfgr = "";
		brand = "";
		type = "";
		container = "";
		comment = "";
	}
	//Constructor if values are known.
	Data::Data(int k, std::string n, std::string m, std::string b, std::string t, int s, std::string c, float p, std::string co) {
		key = k;
		name = n;
		mfgr = m;
		brand = b;
		type = t;
		size = s;
		container = c;
		price = p;
		comment = co;
	}
	bool operator==(const Data& dc, const Data& lc) {
	/*********************************************
		Only checks if key and name are equal because those values should be unique.
		NOTE::Might only need key to be unique
	*********************************************/
		bool equal = false;
		if (dc.key == lc.key || dc.name == lc.name) {
			equal = true;
		}
		return equal;
	}
	bool operator!=(const Data& dc, const Data& lc) {
	/*********************************************
		returns the opposite of overloaded == operator
	*********************************************/
		return !operator==(dc, lc);
	}

}