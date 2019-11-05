#pragma once
#ifndef __Ball__
#define __Ball__

#include <vector>
#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Tile.h"
#include "Scene.h"

class Ball :
	public DisplayObject
{
public:
	Ball();
	~Ball();

	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;

	void Reset();

	float GetMass() const { return m_fMass; }
	void SetMass(float fMass) { m_fMass = fMass; }

private:
	float m_fMass;
};


#endif /* defined (__Ship__) */

