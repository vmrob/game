#include <boost/multi_array.hpp>
#include <cinder/TriMesh.h>

class Terrain {
public:
	Terrain() = default;
	Terrain(int x, int y);

	void draw();
	void generate(int x, int y);

	inline double at(int x, int y) {
		return _grid[x][y];
	}

private:
	boost::multi_array<double, 2> _grid;

	ci::TriMesh _mesh;

	void _generateMesh();
};