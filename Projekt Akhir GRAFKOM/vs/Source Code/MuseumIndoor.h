#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "RenderEngine.h"

class MuseumIndoor {
public:
	MuseumIndoor();
	//Build obJekt
	//|-------------------------------------|
	void BuildAll(unsigned int* depthCubeMap, unsigned int sizeOfLights);
	void BuildLantai();
	void BuildDinding();
	void BuildKarpet();
	void BuildPillar();
	void BuildDoor();
	void BuildPedestal1();
	void BuildTexturedCube();

	void BuildPainting();

	//Render objekt
	//|-------------------------------------|
	void DrawAll(GLuint shaderProgram);
	void DrawLantai();
	void DrawDinding();
	void DrawKarpet();
	void DrawPillar(float xPos, float zPos);
	void DrawDoor();
	void DrawPedestal1(float xPos, float yPos, float zPos);
	void DrawTexturedCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	//Blend Object Tes
	void BuildCube();
	void DrawCube();

	void DrawPainting(float xPos, float yPos, float zPos, int i, float pos);

	//Misc Function
	void positionPedestal1(glm::vec3 vecPedestal1);
	void loadTexture(const char* textureLoc, int i);


private:
	GLuint shaderProgram;
	GLuint VBOLantai, VAOLantai, EBOLantai, textureLantai;
	GLuint VBODinding, VAODinding, EBODinding, textureDinding, stextureDinding;
	GLuint VBOPillar, VAOPillar, EBOPillar, texturePillar, stexturePillar;
	GLuint VBOKarpet, VAOKarpet, EBOKarpet, textureKarpet, stextureKarpet;
	GLuint VBODoor, VAODoor, EBODoor, textureDoor, stextureDoor;
	GLuint VBOCubeB, VAOCubeB, EBOCubeB, textureCubeB;
	GLuint stexture2, plane_texture, dindingTexture;
	GLuint VBOPedestal1, VAOPedestal1, EBOPedestal1, texturePedestal1, stexturePedestal1;
	GLuint VBOCube, VAOCube, EBOCube, textureCube, stextureCube;
	GLuint VBOPainting, VAOPainting, EBOPainting, texturePainting, stexturePainting;
	GLuint texturePaintings[6], stexturePaintings[6];
	unsigned int * depthCubeMap;
	unsigned int sizeOfLights;
	//Posisi pedestal1
	glm::vec3 vecPedestal1;
};