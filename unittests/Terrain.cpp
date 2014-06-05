#include <tinytest.h>

#include <vector>
#include "../src/Terrain.h"

TEST_SUITE("Terrain") {

	TEST("Generate") {

		Terrain t1(10, 10);
		Terrain t2(10, 10);
	
		std::vector<double> e1;
		std::vector<double> e2;

		for(int x = 0; x < 10; ++x) {
			for(int y = 0; y < 10; ++y) {
				e1.push_back(t1.at(x, y));
				e2.push_back(t2.at(x, y));
			}
		}

		CHECK(e1 != e2);

		t1.generate(10, 10);
		e2.clear();

		// regenerate, ensure new terrain is formed
		for(int x = 0; x < 10; ++x) {
			for(int y = 0; y < 10; ++y) {
				e2.push_back(t1.at(x, y));
			}
		}

		CHECK(e1 != e2);

	};

};