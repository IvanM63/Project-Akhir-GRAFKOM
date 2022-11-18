#include "MasterSword.h"

MasterSword::MasterSword() {

}

void MasterSword::BuildCube(GLuint shaderProgram3) {
	//Taro shaderProgram ke this
	shaderProgram1 = shaderProgram3;
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5,  0.0f,  0.0f,  1.0f, // 0
		0.5, -0.5, 0.5,   0.0f,  0.0f,  1.0f, // 1
		0.5,  0.5, 0.5,   0.0f,  0.0f,  1.0f, // 2
		-0.5,  0.5, 0.5,  0.0f,  0.0f,  1.0f, // 3

		// right
		0.5,  0.5,  0.5, 1.0f,  0.0f,  0.0f, // 4
		0.5,  0.5, -0.5, 1.0f,  0.0f,  0.0f, // 5
		0.5, -0.5, -0.5, 1.0f,  0.0f,  0.0f, // 6
		0.5, -0.5,  0.5, 1.0f,  0.0f,  0.0f, // 7

		// back
		-0.5, -0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 8 
		0.5,  -0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 9
		0.5,   0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5, -1.0f,  0.0f,  0.0f, // 12
		-0.5, -0.5,  0.5, -1.0f,  0.0f,  0.0f, // 13
		-0.5,  0.5,  0.5, -1.0f,  0.0f,  0.0f, // 14
		-0.5,  0.5, -0.5, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.5, 0.5,  0.5, 0.0f,  1.0f,  0.0f, // 16
		-0.5, 0.5, 0.5, 0.0f,  1.0f,  0.0f, // 17
		-0.5, 0.5, -0.5,0.0f,  1.0f,  0.0f, // 18
		0.5, 0.5, -0.5, 0.0f,  1.0f,  0.0f, // 19

		// bottom
		-0.5, -0.5, -0.5, 0.0f,  -1.0f,  0.0f, // 20
		0.5, -0.5, -0.5,  0.0f,  -1.0f,  0.0f, // 21
		0.5, -0.5,  0.5,  0.0f,  -1.0f,  0.0f, // 22
		-0.5, -0.5,  0.5, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &VAO3);
	glGenBuffers(1, &VBO3);
	glGenBuffers(1, &EBO3);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO3);

	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO3);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define normal pointer layout 2
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MasterSword::DrawAll() {
	//1 kotak -> 0.0625
	//2 kotak -> 0.125
	//3 kotak -> 0.1875
	//4 kotak -> 0.25
	//6 kotak -> 0.375
	//7 kotak -> 0.4375

	float p = 2.5;
	
	//Pegangan
	DrawColoredCube(0, 0.375/p, 5/p, 0.125/p, 0.4375/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	//gagang
	DrawColoredCube(0, 0.625/p, 5/p, 0.25/p, 0.0625/p, 0.1875/p, 0.38431f, 0.61569f, 0.76471f);
	//di atas gagang
	DrawColoredCube(0, 0.6875/p, 5/p, 0.125/p, 0.0625/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	//kotak kuning
	DrawColoredCube(0, 0.78125/p, 5/p, 0.125/p, 0.125/p, 0.0625/p, 1.00000f, 0.95686f, 0.00000f);
	//di atas kuning
	DrawColoredCube(0, 0.9375/p, 5/p, 0.125/p, 0.1875/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	//kuning lagi
	DrawColoredCube(0, 1.0625/p, 5/p, 0.125/p, 0.0625/p, 0.0625/p, 1.00000f, 0.95686f, 0.00000f);
	//bilah Putih
	DrawColoredCube(0, 1.9375/p, 5/p, 0.125/p, 1.6875/p, 0.0625/p, 0.98039f, 1.00000f, 0.98824f);
	//bilah di atas Putih
	DrawColoredCube(0, 2.8125/p, 5/p, 0.125/p, 0.125/p, 0.0625/p, 0.79608f, 1.00000f, 0.93333f);

	//Pinggiran kiri
	DrawColoredCube(-0.09375/p, 1.96875/p, 5/p, 0.0625/p, 1.625/p, 0.0625/p, 0.79608f, 1.00000f, 0.93333f);
	DrawColoredCube(-0.15625/p, 1.3125/p, 5/p, 0.0625/p, 0.125/p, 0.0625/p, 0.79608f, 1.00000f, 0.93333f);

	//Pinggiran kanan
	DrawColoredCube(0.09375/p, 1.96875/p, 5/p, 0.0625/p, 1.625/p, 0.0625/p, 0.79608f, 1.00000f, 0.93333f);
	DrawColoredCube(0.15625/p, 1.3125/p, 5/p, 0.0625/p, 0.125/p, 0.0625/p, 0.79608f, 1.00000f, 0.93333f);

	//SampingkiriEmas
	DrawColoredCube(-0.125/p, 0.78125/p, 5/p, 0.125/p, 0.125/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(-0.21875/p, 0.75/p, 5/p, 0.0625/p, 0.1875/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(-0.28125/p, 0.71875/p, 5/p, 0.0625/p, 0.125/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(-0.34375/p, 0.78125/p, 5/p, 0.0625/p, 0.125/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(-0.40625/p, 0.75/p, 5/p, 0.0625/p, 0.0625/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);

	//SampingkiriEmas
	DrawColoredCube(0.125/p, 0.78125/p, 5/p, 0.125/p, 0.125/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(0.21875/p, 0.75/p, 5/p, 0.0625/p, 0.1875/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(0.28125/p, 0.71875/p, 5/p, 0.0625/p, 0.125/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(0.34375/p, 0.78125/p, 5/p, 0.0625/p, 0.125/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);
	DrawColoredCube(0.40625/p, 0.75/p, 5/p, 0.0625/p, 0.0625/p, 0.0625/p, 0.49412f, 0.12549f, 1.00000f);

	


}

void MasterSword::DrawColoredCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, float rColor, float gColor, float bColor) {
	glUseProgram(shaderProgram1);

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texture3);
	//glUniform1i(glGetUniformLocation(shaderProgram1, "ourTexture"), 0);

	glBindVertexArray(VAO3); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	GLint objectColorLoc = glGetUniformLocation(shaderProgram1, "objectColor");
	glUniform3f(objectColorLoc, rColor, gColor, bColor);

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, anglep, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram1, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	
	glBindVertexArray(0);
}

void MasterSword::scaling(float x, float y, float z) {
	//float p = 0.0625 * (scale);
	mX = x;
	mY = y;
	mZ = z;
	//sX = p;
	//sY = p;
	//sZ = p;
}
