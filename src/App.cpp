#include "App.h"

#include <cinder/Camera.h>

GameApp::GameApp()
	: _terrain(10, 10)
{

}

void GameApp::setup() {
	ci::CameraPersp cam(ci::app::getWindowWidth() * 0.5f, ci::app::getWindowHeight(), 40.0f, 0.1f, 1000.0f);
	cam.setEyePoint(ci::Vec3f(-50.0f, 0.0f, 0.0f));
	cam.setCenterOfInterestPoint(ci::Vec3f::zero());

	_mayaCam.setCurrentCam(cam);
}

void GameApp::update() {

}

void GameApp::draw() {
	_clear();

	ci::gl::pushModelView();

	auto center = ci::app::toPixels(ci::app::getWindowSize()) * 0.5;

	ci::gl::translate(ci::Vec2f(center.x, center.y));

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

}

void GameApp::mouseDrag(ci::app::MouseEvent event) {

}