#include "Terrain.h"

#include <cinder/gl/gl.h>
#include "utility.h"

Terrain::Terrain(int x, int y)
	: _grid(boost::extents[x][y])
{
	generate(x, y);
}

void Terrain::draw() {
	ci::gl::enableWireframe();
	ci::gl::pushModelView();

	const double scalar = 50.0;
	const double halfScalar = 0.5 * scalar;

	ci::gl::scale(scalar * ci::Vec2f::one());

	// ci::gl::translate(-halfScalar * ci::Vec2f::one());

	ci::gl::draw(_mesh);

	ci::gl::popModelView();
	ci::gl::disableWireframe();
}

void Terrain::generate(int x, int y) {
	_grid = boost::multi_array<double, 2>(boost::extents[x][y]);
	int xSize = _grid.shape()[0];
	int ySize = _grid.shape()[1];
	for (int x = 0; x < xSize; ++x) {
		for (int y = 0; y < ySize; ++y) {
			_grid[x][y] = Random<double>(0, 1);
		}
	}

	_generateMesh();
}

void Terrain::_generateMesh() {
	_mesh.clear();

	int xSize = _grid.shape()[0];
	int ySize = _grid.shape()[1];

	if (xSize < 2 || ySize < 2) {
		return;
	}

	// add verticies and colors
	// colors correspond to their height
	for (int x = 0; x < xSize; ++x) {
		for (int y = 0; y < xSize; ++y) {
			double val = _grid[x][y];
			_mesh.appendVertex(ci::Vec3f(x, y, val));
			_mesh.appendColorRgb(ci::Color::gray(val));
		}
	}

	// add triangles
	//
	//         X
	//    *-----*-----*-----*
	//    |   / |   / |   / |
	//    | /   | /   | /   |
	//    *-----O-----*-----* <-- start at (1,1)
	//  Y |   / |   / |   / |
	//    | /   | /   | /   |
	//    *-----*-----*-----*
	//    |   / |   / |   / |
	//    | /   | /   | /   |
	//    *-----*-----*-----O <-- end at (sizeX, sizeY)
	//
	for (int x = 1; x < xSize; ++x) {
		for (int y = 1; y < xSize; ++y) {
			// *-----*
			// |XXX/ |
			// |X/   |
			// *-----O
			{
				int v1 = (x - 1) * xSize + y - 1;
				int v2 = (x - 1) * xSize + y;
				int v3 = (x)     * xSize + y - 1;
				_mesh.appendTriangle(v1, v2, v3);
			}
			// *-----*
			// |   /X|
			// | /XXX|
			// *-----O
			{
				int v1 = (x)     * xSize + y;
				int v2 = (x)     * xSize + y - 1;
				int v3 = (x - 1) * xSize + y;
				_mesh.appendTriangle(v1, v2, v3);
			}
		}
	}
}
