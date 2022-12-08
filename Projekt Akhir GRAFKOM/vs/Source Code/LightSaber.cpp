#include "LightSaber.h"

LightSaber::LightSaber() {

}

void LightSaber::BuildCube() {

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		 0.5, -0.5, 0.5, 1, 0, 0.0f,  0.0f,  1.0f, // 1
		 0.5,  0.5, 0.5, 1, 1, 0.0f,  0.0f,  1.0f, // 2
		-0.5,  0.5, 0.5, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		// right
		 0.5,  0.5,  0.5, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 0.5,  0.5, -0.5, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 0.5, -0.5, -0.5, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 0.5, -0.5,  0.5, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		 // back
		 -0.5, -0.5, -0.5, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		  0.5, -0.5, -0.5, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		  0.5,  0.5, -0.5, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		 -0.5,  0.5, -0.5, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 -0.5, -0.5, -0.5, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 -0.5, -0.5,  0.5, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 -0.5,  0.5,  0.5, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 -0.5,  0.5, -0.5, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		 // upper
		  0.5, 0.5,  0.5, 0, 0, 0.0f,  1.0f,  0.0f, // 16
		 -0.5, 0.5,  0.5, 1, 0, 0.0f,  1.0f,  0.0f, // 17
		 -0.5, 0.5, -0.5, 1, 1, 0.0f,  1.0f,  0.0f, // 18
		  0.5, 0.5, -0.5, 0, 1, 0.0f,  1.0f,  0.0f, // 19

		  // bottom
		  -0.5, -0.5, -0.5, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		   0.5, -0.5, -0.5, 1, 0, 0.0f,  -1.0f,  0.0f, // 21
		   0.5, -0.5,  0.5, 1, 1, 0.0f,  -1.0f,  0.0f, // 22
		  -0.5, -0.5,  0.5, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// define normal pointer layout 2
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void LightSaber::BuildCubeHitamPutih() {

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		 0.5, -0.5, 0.5, 1, 0, 0.0f,  0.0f,  1.0f, // 1
		 0.5,  0.5, 0.5, 1, 1, 0.0f,  0.0f,  1.0f, // 2
		-0.5,  0.5, 0.5, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		// right
		 0.5,  0.5,  0.5, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 0.5,  0.5, -0.5, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 0.5, -0.5, -0.5, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 0.5, -0.5,  0.5, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		 // back
		 -0.5, -0.5, -0.5, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		  0.5, -0.5, -0.5, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		  0.5,  0.5, -0.5, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		 -0.5,  0.5, -0.5, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 -0.5, -0.5, -0.5, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 -0.5, -0.5,  0.5, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 -0.5,  0.5,  0.5, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 -0.5,  0.5, -0.5, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		 // upper
		  0.5, 0.5,  0.5, 0, 0, 0.0f,  1.0f,  0.0f, // 16
		 -0.5, 0.5,  0.5, 1, 0, 0.0f,  1.0f,  0.0f, // 17
		 -0.5, 0.5, -0.5, 1, 1, 0.0f,  1.0f,  0.0f, // 18
		  0.5, 0.5, -0.5, 0, 1, 0.0f,  1.0f,  0.0f, // 19

		  // bottom
		  -0.5, -0.5, -0.5, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		   0.5, -0.5, -0.5, 1, 0, 0.0f,  -1.0f,  0.0f, // 21
		   0.5, -0.5,  0.5, 1, 1, 0.0f,  -1.0f,  0.0f, // 22
		  -0.5, -0.5,  0.5, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// define normal pointer layout 2
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void LightSaber::BuildAll() {
	BuildCube();
	loadColor("colorTexture/putih.png", 0);
	loadColor("colorTexture/hitam.png", 1);
	loadColor("colorTexture/hitam_putih.png", 2);
	loadColor("colorTexture/kuning.png", 3);
}

void LightSaber::DrawAll(GLuint shaderProgram) {
	this->shaderProgram = shaderProgram;
	//1 kotak -> 0.0625
	//2 kotak -> 0.125
	//3 kotak -> 0.1875
	//4 kotak -> 0.25
	//5 kotak -> 0.3125
	//6 kotak -> 0.375
	//7 kotak -> 0.4375

	//Bagian Paling Bawah Bentuk Simbol Swiss
	DrawCube(0 / p, 0 / p, 0 / p, 0.1875 / p, 0.0625 / p, 0.3125 / p, 0); //Vertical
	DrawCube(0 / p, 0 / p, 0 / p, 0.3125 / p, 0.0625 / p, 0.1875 / p, 0); //Horizontal

	//Batang garis vertikal hitam-putih
	DrawCube(0 / p, 0.53125 / p, 0 / p, 0.3125 / p, 1.0000 / p, 0.3125 / p, 2);

	//Batang Hitam di luar Garis Vertikal Hitam-Putih
	DrawCube(0 / p, 0.53125 / p,  0.1875 / p, 0.0625 / p, 1.0000 / p, 0.0625 / p, 1); //Depan
	DrawCube(0 / p, 0.53125 / p, -0.1875 / p, 0.0625 / p, 1.0000 / p, 0.0625 / p, 1); //Belakang
	DrawCube( 0.1875 / p, 0.53125 / p, 0 / p, 0.0625 / p, 1.0000 / p, 0.0625 / p, 1); //Kanan
	DrawCube(-0.1875 / p, 0.53125 / p, 0 / p, 0.0625 / p, 1.0000 / p, 0.0625 / p, 1); //Kiri

	//Bagian di Atasnya Bentuk Simbol Swiss | y = 1 blok Saja | Warna Putih
	DrawCube(0 / p, 1.0625 / p, 0 / p, 0.1875 / p, 0.0625 / p, 0.3125 / p, 0); //Vertical
	DrawCube(0 / p, 1.0625 / p, 0 / p, 0.3125 / p, 0.0625 / p, 0.1875 / p, 0); //Horizontal

	//Bagian di Atasnya Bentuk Simbol Swiss | y = 5 blok Saja | Warna Hitam
	DrawCube(0 / p, 1.25 / p, 0 / p, 0.1875 / p, 0.3125 / p, 0.3125 / p, 1); //Vertical
	DrawCube(0 / p, 1.25 / p, 0 / p, 0.3125 / p, 0.3125 / p, 0.1875 / p, 1); //Horizontal

	//Samping kiri Swiss Hitam
	DrawCube(-0.1875 / p, 1.25 / p, 0 / p, 0.0625 / p, 0.3125 / p, 0.0625 / p, 1); //Kiri
	DrawCube(-0.25 / p, 1.25 / p, 0 / p, 0.0625 / p, 0.3125 / p, 0.1875 / p, 1); //Kiri lagi

	//Bagian di Atasnya Bentuk Simbol Swiss | y = 7 blok Saja | Warna Putih
	DrawCube(0 / p, 1.625 / p, 0 / p, 0.1875 / p, 0.4375 / p, 0.3125 / p, 0); //Vertical
	DrawCube(0 / p, 1.625 / p, 0 / p, 0.3125 / p, 0.4375 / p, 0.1875 / p, 0); //Horizontal

	//Tombol Kuning di Depan
	DrawCube((0 * x) / p, (26 * x) / p, (3 * x) / p, (1 * x) / p, (2 * x) / p, (1 * x) / p, 3); //Depan

	//Bagian di Atasnya Bentuk Simbol Swiss | y = 7 blok Saja | Warna Hitam
	DrawCube((0 * x) / p, (33 * x) / p, (0 * x) / p, (3 * x) / p, (7 * x) / p, (5 * x) / p, 1); //Vertical
	DrawCube((0 * x) / p, (33 * x) / p, (0 * x) / p, (5 * x) / p, (7 * x) / p, (3 * x) / p, 1); //Horizontal

	//Sebelah Kanan
	DrawCube((3 * x) / p, (32.5 * x) / p, (0 * x) / p, (1 * x) / p, (10 * x) / p, (1 * x) / p, 1); //Kanan
	DrawCube((4 * x) / p, (34.5 * x) / p, (0 * x) / p, (1 * x) / p, (1 * x) / p, (1 * x) / p, 3); //Kanan Kuning
	DrawCube((4 * x) / p, (31.5 * x) / p, (0 * x) / p, (1 * x) / p, (1 * x) / p, (1 * x) / p, 0); //Kanan Putih

	//Sebelah Kanan
	DrawCube((2 * x) / p, (37.0 * x) / p, (0 * x) / p, (1 * x) / p, (1 * x) / p, (3 * x) / p, 1); //Kanan
	DrawCube((1 * x) / p, (37.0 * x) / p, (2 * x) / p, (1 * x) / p, (1 * x) / p, (1 * x) / p, 1); //Kanan
	DrawCube((1 * x) / p, (37.0 * x) / p, (-2 * x) / p, (1 * x) / p, (1 * x) / p, (1 * x) / p, 1); //Kanan

	//Atas
	DrawCube((2 * x) / p, (38.0 * x) / p, (0 * x) / p, (1 * x) / p, (1 * x) / p, (1 * x) / p, 1); //Kanan
}

void LightSaber::DrawCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureColor[i]);
	//glUniform1i(glGetUniformLocation(shaderProgram1, "ourTexture"), 0);

	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	/*GLint objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
	glUniform3f(objectColorLoc, rColor, gColor, bColor);*/

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, anglep, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


	glBindVertexArray(0);
}

void LightSaber::DrawLight(GLuint lightShader) {
	//glUseProgram(shaderProgram);

	/*glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureColor[i]);*/
	//glUniform1i(glGetUniformLocation(shaderProgram1, "ourTexture"), 0);

	//lightColor
	GLint lightColorLoc = glGetUniformLocation(lightShader, "lightColor");
	glUniform3f(lightColorLoc, 1.0f, 0.0f, 0.0f);

	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	/*GLint objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
	glUniform3f(objectColorLoc, rColor, gColor, bColor);*/


	float xPos = (0 * x) /p;
	float yPos = (86 * x) /p;
	float zPos = (0 * x) /p;

	float xSize = (3 * x) /p;
	float ySize = (99 * x) /p;
	float zSize = (3 * x) /p;

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, anglep, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(lightShader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


	glBindVertexArray(0);
}

void LightSaber::scaling(float x, float y, float z) {
	//float p = 0.0625 * (scale);
	mX = x;
	mY = y;
	mZ = z;
	//sX = p;
	//sY = p;
	//sZ = p;
}

void LightSaber::loadColor(const char* textureLoc, int i) {
	// Load and create a texture 
	glGenTextures(1, &textureColor[i]);
	glBindTexture(GL_TEXTURE_2D, textureColor[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image(textureLoc, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &stextureColor[i]);
	glBindTexture(GL_TEXTURE_2D, stextureColor[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("marble_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void LightSaber::setPosition(glm::vec3 location) {
	//this->location = location;
	mX = location.x;
	mY = location.y;
	mZ = location.z;
}