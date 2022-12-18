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
	void BuildCube();
	void BuildPrism();
	void BuildPrismBilahTumpul();
	void BuildPrismBilahTajam();
	void BuildTexturedBilahKiri();
	void BuildAll();

	//Render Objekt
	void DrawAll(GLuint shaderProgram);
	void DrawColoredCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	void DrawColoredPrism(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	void DrawColoredPrismBilahLancip(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	void DrawColoredPrismBilahTumpul(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	void DrawTexturedBilahKiri(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	void scaling(float x, float y, float z);

	//Misc Function
	void setPosition(glm::vec3 position);
	void loadTexture(const char* textureLoc, int i);

private:
	GLuint shaderProgram1, VBO4, VAO4, EBO4, texture4, VBOPrism, VAOPrism, EBOPrism;
	GLuint VBOPrismBilahTumpul, VAOPrismBilahTumpul, EBOPrismBilahTumpul;
	GLuint VBOPrismBilahLancip, VAOPrismBilahLancip, EBOPrismBilahLancip;
	GLuint stextureBilahKiri, textureBilahKiri, VBOb,VAOb,EBOb;
	GLuint textures[5], stextures[5];

	float mX = 0.0;
	float mY = 0.0;
	float mZ = 0.0;

	float sX = 0;
	float sY = 0;
	float sZ = 0;
};