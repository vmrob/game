#include "App.h"

#include <cinder/Camera.h>

GameApp::GameApp()
	: _terrain(10, 10)
{

}

void GameApp::setup() {
	ci::CameraPersp cam(ci::app::getWindowWidth() * 0.5f, ci::app::getWindowHeight(), 60.0f, 0.0f, 1000.0f);
	cam.setEyePoint(ci::Vec3f(0.0f, 0.0f, 50.0f));
	cam.setWorldUp(ci::Vec3f(0.0f, 1.0f, 0.0f));
	cam.setCenterOfInterestPoint(ci::Vec3f::zero());

	_mayaCam.setCurrentCam(cam);
}

void GameApp::update() {

}

void GameApp::draw() {
	_clear();

	ci::gl::pushModelView();

	ci::gl::setModelView(_mayaCam.getCamera());

	_terrain.draw();

	ci::gl::popModelView();
}

void GameApp::_clear() {
	auto size = ci::app::toPixels(ci::app::getWindowSize());

	ci::gl::clear();
	ci::gl::color(0.0, 0.0, 0.0);
	ci::gl::drawSolidRect(ci::Rectf(0, size.y, size.x, 0));
}

void GameApp::mouseDown(ci::app::MouseEvent event) {
	_mayaCam.mouseDown(event.getPos());
}

void GameApp::mouseDrag(ci::app::MouseEvent event) {
	_mayaCam.mouseDrag(
		event.getPos(),
		event.isLeftDown() && !event.isShiftDown(),
		event.isShiftDown(),
		event.isRightDown()
	);
}