#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include "Ball.h"
#include <cmath>

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	/*Label* m_pStartLabel;
	Label* m_pInstructionsLabel;*/

	//Ship* m_pShip;
	Ball* m_pBall;

	glm::vec2 m_mousePosition;

	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;

	// Physics Variables
	const float Deg2Rad = 0.0174532925f;
	const float Rad2Deg = 57.2957795130f;
	bool m_isGravityEnabled = false;
	float m_gravity = 9.8f;
	float m_PPM = 5.0f; // pixels per meter - scale

	float m_time = 0.016667f; // approximately 16 ms
	float m_Atime = 0.f; // accumulated time

	float m_kickForce = 0.f;
	float m_angle = 0.f; // the "kicking" angle
	float m_fBallMass = 0.f;

	bool m_bSimulationStart = false;

	// Physics Functions
	void m_move();
};

#endif /* defined (__START_SCENE__) */