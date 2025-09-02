#include "data.h"

namespace dj {
	Data::Data() {
		name = "";
		mfgr = "";
		brand = "";
		type = "";
		container = "";
		comment = "";
	}
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
		bool equal = false;
		if (dc.key == lc.key || dc.name == lc.name) {
			equal = true;
		}
		return equal;
	}
	bool operator!=(const Data& dc, const Data& lc) {
		return !operator==(dc, lc);
	}

}