#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class LightSaber {
public:
	LightSaber();
	float moveX = 0;
	float anglep = 0;
	GLuint textureColor[5], stextureColor[5];

	//Build Function
	void BuildAll();
	void BuildCube();
	void BuildCubeHitamPutih();

	//Draw Function
	void DrawAll(GLuint shaderProgram);
	void DrawCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i);
	void DrawLight(GLuint lightShader);

	//Misc Function
	void scaling(float x, float y, float z);
	void loadColor(const char* textureLoc, int i);
	void setPosition(glm::vec3 location);

private:
	GLuint shaderProgram, VBO, VAO, EBO, texture, stexture;
	GLuint VBOh, VAOh, EBOh, textureH, stextureH;

	float mX, mY, mZ;

	float sX = 0;
	float sY = 0;
	float sZ = 0;
	
	float p = 3.5;
	float x = 0.0625;
};