#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Person {
public:
	Person();

	//Function of Person
	void position(float xPos, float yPos, float zPos);
	void changeRotationX(float radian);

	//Build Objekt
	void BuildAll(GLuint shaderProgram, const char *textureLoc);
	void BuildHead();
	void BuildBody();
	void BuildArms();
	void BuildLegs();

	//Draw Objekt
	void DrawAll();
	void DrawHead(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize);
	void DrawBody(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize);
	void DrawArms(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize);
	void DrawLegs(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize);
	
private:
	GLuint shaderProgram;
	GLuint headVBO, headVAO, headEBO, headTexture, headTextures;
	GLuint BodyVBO, BodyVAO, BodyEBO, bodyTexture, bodyTextures;
	GLuint ArmsVBO, ArmsVAO, ArmsEBO, armsTexture, armsTextures;
	GLuint LegsVBO, LegsVAO, LegsEBO, legsTexture, legsTextures;
	const char *textureLoc = "knight_skin.png";
	float angle = 3.14159f;

	//Posisi Person
	float mX = 0;
	float mY = -0.1875;
	float mZ = 0 ;
};
