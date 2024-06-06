#pragma once
#include "GraphicsEngine.h"
#include "EventEngine.h"

class XCube2Engine {
private:
	static std : : shared_ptr<XCube2Engine> instance;



	std::shared_ptr<GraphicsEngine> gfxInstance;
	std::shared_ptr<EventEngine> eventInstance;



	XCube2Engine();
public:

	std::shared_ptr<GraphicsEngine> getGraphicsEngine() { return gfxInstance; }
	std::shared_ptr<EventEngine> getEventEngine() { return eventInstance; }


	static void quit();

};