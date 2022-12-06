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
#include "Person.h"

class Demo :
	public RenderEngine
{
public:
	Demo();
	~Demo();

private:
	//static int sizeOfLights = 2;

	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2;
	GLuint shaderPlane, texturedShader;
	
	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	float angle = 0;

	//Inisiasi Lingkungan Indoor
	MuseumIndoor mi1;

	//Inisiasi Pedang
	MasterSword ms1;
	BusterSword bs1;

	//Inisiasi Person
	Person person1, person2, person3;
	
	//Light cube
	GLuint lightShader, lightVBO, lightVAO, lightEBO;
	GLuint lightSegitigaVBO, lightSegitigaVAO, lightSegitigaEBO;
	void BuildLight();
	void BuildLightSegitiga();
	void DrawLight(float lightX, float lightY, float lightZ, float colorR, float colorG, float colorB);
	void DrawLightSegitiga(float lightX, float lightY, float lightZ, float colorR, float colorG, float colorB);

	//Posisi Light Pos
	//Light 1
	float xLight = 0.0f;
	float yLight = 8.0f;
	float zLight = 15.0f;

	//Light 2
	
	//Light 3

	GLuint shadowmapShader, cubeVBO, cubeVAO, cubeEBO, cube_texture, textureCubeSpecular, planeVBO, planeVAO, planeEBO, plane_texture, stexture, stexture2;

	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
	void MoveCamera(float speed);
	void StrafeCamera(float speed);
	void RotateCamera(float speed);
	void InitCamera();

	//Textured Cube
	GLuint textureCube;
	void BuildTexturedCube();
	void DrawTexturedCube(GLuint shader);

	void BuildPlane();
	void DrawPlane(GLuint shader);

	GLuint shader, simpleDepthShader;
	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;

	unsigned int depthCubeMap[2];
	unsigned int depthMapFBO[2];

	glm::vec3 lightPos[2] = {
		glm::vec3(0.0, 5.0, 0.0),
		glm::vec3(0.0, 5.0, 5.0),
		//glm::vec3(0.0, 0.1, -20.5)
	};

	unsigned int sizeOfLights = sizeof(depthCubeMap) / sizeof(depthCubeMap[0]);

	bool shadows = true;
	bool shadowsKeyPressed = false;
};

