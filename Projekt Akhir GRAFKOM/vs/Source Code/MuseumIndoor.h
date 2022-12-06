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

	//Render objekt
	//|-------------------------------------|
	void DrawAll(GLuint shaderProgram);
	void DrawLantai();
	void DrawDinding();
	void DrawKarpet();
	void DrawPillar(float xPos, float zPos);
	void DrawDoor();
	void DrawPedestal1(float xPos, float yPos, float zPos);

private:
	GLuint shaderProgram;
	GLuint VBOLantai, VAOLantai, EBOLantai, textureLantai;
	GLuint VBODinding, VAODinding, EBODinding, textureDinding, stextureDinding;
	GLuint VBOPillar, VAOPillar, EBOPillar, texturePillar, stexturePillar;
	GLuint VBOKarpet, VAOKarpet, EBOKarpet, textureKarpet, stextureKarpet;
	GLuint VBODoor, VAODoor, EBODoor, textureDoor, stextureDoor;
	GLuint stexture2, plane_texture, dindingTexture;
	GLuint VBOPedestal1, VAOPedestal1, EBOPedestal1, texturePedestal1, stexturePedestal1;
	unsigned int * depthCubeMap;
	unsigned int sizeOfLights;
};