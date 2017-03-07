#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "VectorMath.h"

#include <string>

#define _ROTV 18.0f
#define _VERTEX0 0
#define _VERTEX1 3
#define _VERTEX2 6
#define _VERTEX3 9
#define _VERTEX4 12
#define _VERTEX5 15
#define _MAX_RES 7

class TexturedSphere :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	TexturedSphere(const std::string& filename);
	~TexturedSphere();

	void Display();
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int mx, int my);

	inline void SetResolution(int r) { _resolution = r; }

	inline void ToggleWireFrame() { _flagWireFrame = !_flagWireFrame; }
	inline void ToggleAnimation() { _flagAnimation = !_flagAnimation; }
private:
	void DrawSphere();
	void SubDivide(int p_recurse, float *a, float *b, float *c);
	void DrawFace(float *a, float *b, float *c);
	
	void FixSeam(float &a, float &b, float &c);

	int _texID;
	// recursive resolution (increase for finer mesh)
	int _resolution;

	GLboolean _flagWireFrame;
	GLboolean _flagAnimation;

	float* _INIT_V;
};

