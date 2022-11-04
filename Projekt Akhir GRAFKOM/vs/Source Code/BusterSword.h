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
	void BuildCube(GLuint shaderProgram3);
	void BuildPrism(GLuint shaderProgram3);
	void DrawAll();
	void DrawColoredCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor);
	void DrawColoredPrism();
	void scaling(float x, float y, float z);

private:
	GLuint shaderProgram1, VBO4, VAO4, EBO4, texture4, VBOPrism, VAOPrism, EBOPrism;

};