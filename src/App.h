#include <cinder/app/AppBasic.h>
#include <cinder/MayaCamUI.h>

#include "Terrain.h"

class GameApp : public cinder::app::AppBasic {
public:
	GameApp();
	virtual void update() override;
	virtual void draw() override;
	virtual void setup() override;

	virtual void mouseDown(ci::app::MouseEvent event) override;
	virtual void mouseDrag(ci::app::MouseEvent event) override;

private:
	void _clear();

	ci::MayaCamUI _mayaCam;

	Terrain _terrain;
};