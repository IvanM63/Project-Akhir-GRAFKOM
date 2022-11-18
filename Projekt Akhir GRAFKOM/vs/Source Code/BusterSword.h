#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class BusterSword {
public:
	BusterSword();
	float anglep = 0;
	//Build Objekt
	void BuildCube(GLuint shaderProgram3);
	void BuildPrism(GLuint shaderProgram3);
	void BuildPrismBilahTumpul(GLuint shaderProgram3);
	void BuildPrismBilahTajam(GLuint shaderProgram3);
	void BuildTexturedBilahKiri(GLuint shaderProgram3);
	void BuildAll(GLuint shaderProgram3);
	//Render Objekt
	void DrawAll();
	void DrawColoredCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor);
	void DrawColoredPrism(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor);
	void DrawColoredPrismBilahLancip(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor);
	void DrawColoredPrismBilahTumpul(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor);
	void DrawTexturedBilahKiri(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize);
	void scaling(float x, float y, float z);

private:
	GLuint shaderProgram1, VBO4, VAO4, EBO4, texture4, VBOPrism, VAOPrism, EBOPrism;
	GLuint VBOPrismBilahTumpul, VAOPrismBilahTumpul, EBOPrismBilahTumpul;
	GLuint VBOPrismBilahLancip, VAOPrismBilahLancip, EBOPrismBilahLancip;
	GLuint stextureBilahKiri, textureBilahKiri, VBOb,VAOb,EBOb;
	float mX = -1.5;
	float mY = 0.25;
	float mZ = -8.0;
	float sX = 0;
	float sY = 0;
	float sZ = 0;
};