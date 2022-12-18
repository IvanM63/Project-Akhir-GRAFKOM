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
#include "LightSaber.h"
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
	bool run = true;

	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2;
	GLuint shaderPlane, texturedShader;

	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	float angle = 0;

	//Inisiasi Lingkungan Indoor
	MuseumIndoor mi1;

	//Inisiasi Pedang
	MasterSword ms1;
	BusterSword bs1;
	LightSaber ls1;

	//Inisiasi Person
	Person person1, person2, person3;

	//Light cube
	GLuint lightShader, lightVBO, lightVAO, lightEBO;
	GLuint lightSegitigaVBO, lightSegitigaVAO, lightSegitigaEBO;
	void BuildLight();
	void BuildLightSegitiga();
	void DrawLight(float lightX, float lightY, float lightZ, float colorR, float colorG, float colorB);
	void DrawLightSegitiga(float lightX, float lightY, float lightZ, float colorR, float colorG, float colorB);

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
	const unsigned int SHADOW_WIDTH = 512, SHADOW_HEIGHT = 512;

	unsigned int depthCubeMap[4];
	unsigned int depthMapFBO[4];

	glm::vec3 lightPos[4];

	unsigned int sizeOfLights = sizeof(depthCubeMap) / sizeof(depthCubeMap[0]);

	bool shadows = false;
	bool shadowsKeyPressed = true;

	bool rightArrow = false;
	bool rightArrowKeyPressed = true;

	bool lefttArrow = false;
	bool leftArrowKeyPressed = true;

	//Posisi dari Master Sword Pedestial sama Lampu Kuning
	glm::vec3 masterPos = glm::vec3(0.0, 0.25, -21.0);

	//Posisi dari LightSaber
	glm::vec3 saberPos = glm::vec3(5.0, -1.0, -14.0);

	//Posisi dari Buster Sword
	glm::vec3 busterPos = glm::vec3(-5.0, 0.5, -16.25);

	//Light Config KECERAHAN CAHAYA
	int lk = 2;
	float lightConfig[7][2] = {
		{0.7, 1.8}, {0.35, 0.44}, {0.22, 0.20}, // 0 1 2
		{0.14, 0.07}, {0.09, 0.032}, {0.07, 0.017}, {0.045, 0.0075} // 3 4 5 6
	};

	//LIGHT WARNA CAHAYA
	int lc = 0;
	glm::vec3 lightColor[4]{
		glm::vec3(0.5f, 0.5f, 0.5f), // PUTIH
		glm::vec3(0.5f, 0.0f, 0.0f), // MERAH
		glm::vec3(0.0f, 0.0f, 0.5f), // BIRU
		glm::vec3(0.75f, 0.75f, 0.0f), // KUNING

	};
};

