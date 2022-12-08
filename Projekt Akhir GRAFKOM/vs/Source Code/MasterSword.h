#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class MasterSword {
public:
	MasterSword();
	float moveX = 0;
	float anglep = 0;
	GLuint textureColor[5], stextureColor[5];
	//GLuint textureCyan, stextureCyan;
	//GLuint textureCyan, stextureCyan;
	void BuildAll();
	void BuildCube();
	void DrawAll(GLuint shaderProgram);
	void DrawColoredCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor, int i);
	void scaling(float x, float y, float z);
	void loadColor(const char* textureLoc, int i);

	//Misc Function
	void setPosition(glm::vec3 position);

private:
	GLuint shaderProgram, VBO3, VAO3, EBO3, texture3;
	//glm::vec3 position;

	float mX = 0;
	float mY = 1.77;
	float mZ = -2.875;
	float sX = 0;
	float sY = 0;
	float sZ = 0;
	
};