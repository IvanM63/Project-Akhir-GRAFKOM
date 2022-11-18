#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include "Camera.h"
#include "MasterSword.h"
#include "BusterSword.h"
#include "MuseumIndoor.h"

class Demo :
	public RenderEngine
{
public:
	Demo();
	~Demo();

private:


	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2, lightShader;
	GLuint shaderPlane, texturedShader;
	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	float angle = 0;

	//Inisiasi Lingkungan Indoor
	MuseumIndoor mi1;

	//Inisiasi Objeks
	MasterSword ms1;
	BusterSword bs1;

	GLuint shadowmapShader, cubeVBO, cubeVAO, cubeEBO, cube_texture, planeVBO, planeVAO, planeEBO, plane_texture, stexture, stexture2;

	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
	void MoveCamera(float speed);
	void StrafeCamera(float speed);
	void RotateCamera(float speed);
	void InitCamera();
	void BuildTexturedCube();
	void DrawTexturedCube();
};

