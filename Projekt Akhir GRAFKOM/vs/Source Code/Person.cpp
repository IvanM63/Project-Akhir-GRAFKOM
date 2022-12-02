#include "Person.h"

Person::Person() {

}

void Person::position(float xPos, float yPos, float zPos) {
	this->mX += xPos;
	this->mY += yPos;
	this->mZ += zPos;
}

void Person::changeRotationX(float radian) {
	this->angle = radian;
}

void Person::BuildAll(GLuint shaderProgram, const char *textureLoc) {
	//Masukin shaderProgram dari input ke shaderProgram kelas ini
	this->shaderProgram = shaderProgram;
	this->textureLoc = textureLoc;

	//Build berbagai macam objek
	BuildHead();
	BuildBody();
	BuildArms();
	BuildLegs();
}

void Person::BuildHead() {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &headTexture);
	glBindTexture(GL_TEXTURE_2D, headTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image(textureLoc, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &headTextures);
	glBindTexture(GL_TEXTURE_2D, headTextures);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5, 8.0/64.0, 16.0/64.0, 0.0f,  0.0f,  1.0f, // 0  Kiri Bawah
		0.5, -0.5, 0.5, 16.0/64.0, 16.0/64.0, 0.0f,  0.0f,  1.0f, // 1	Kanan Bawah
		0.5,  0.5, 0.5, 16.0/64.0,  8.0/64.0, 0.0f,  0.0f,  1.0f, // 2	Kanan Atas
		-0.5,  0.5, 0.5, 8.0/64.0,  8.0/64.0, 0.0f,  0.0f,  1.0f, // 3	Kiri Atas

		// right
		0.5,  0.5,  0.5, 16.0/64.0, 8.0 /64, 1.0f,  0.0f,  0.0f, // 4   Depan Atas
		0.5,  0.5, -0.5, 24.0/64.0, 8.0 /64, 1.0f,  0.0f,  0.0f, // 5	Belakang Bawah
		0.5, -0.5, -0.5, 24.0/64.0, 16.0/64, 1.0f,  0.0f,  0.0f, // 6	Belakang Atas
		0.5, -0.5,  0.5, 16.0/64.0, 16.0/64, 1.0f,  0.0f,  0.0f, // 7	Depan Atas

		// back
		-0.5, -0.5, -0.5, 32.0/64.0, 16.0 /64, 0.0f,  0.0f,  -1.0f, // 8 
		0.5,  -0.5, -0.5, 24.0/64.0, 16.0 /64, 0.0f,  0.0f,  -1.0f, // 9
		0.5,   0.5, -0.5, 24.0/64.0, 8.0  /64, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 32.0/64.0, 8.0  /64, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5,  0.0/64.0, 16.0/64.0, -1.0f,  0.0f,  0.0f, // 12 Depan Atas
		-0.5, -0.5,  0.5,  8.0/64.0, 16.0/64.0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		-0.5,  0.5,  0.5,  8.0/64.0,  8.0/64.0, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		-0.5,  0.5, -0.5,  0.0/64.0,  8.0/64.0, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// upper
		 0.5, 0.5,  0.5,  8.0/64.0, 16.0/64.0,   0.0f,  1.0f,  0.0f, // 16 Kiri Depan
		-0.5, 0.5,  0.5, 16.0/64.0, 16.0/64.0,   0.0f,  1.0f,  0.0f, // 17 Kanan Depan
		-0.5, 0.5, -0.5, 16.0/64.0, 8.0/64.0,  0.0f,  1.0f,  0.0f, // 18 Kanan Belakang
		 0.5, 0.5, -0.5,  8.0/64.0, 8.0/64.0,   0.0f,  1.0f,  0.0f, // 19 Kiri Belakang

		// bottom
		-0.5, -0.5, -0.5, 16.0/64.0, 64.0/64,  0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		 0.5, -0.5, -0.5, 24.0/64.0, 64.0/64,  0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		 0.5, -0.5,  0.5, 24.0/64.0, 8.0/64,  0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		-0.5, -0.5,  0.5, 16.0/64.0, 8.0/64,  0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &headVAO);
	glGenBuffers(1, &headVBO);
	glGenBuffers(1, &headEBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(headVAO);

	glBindBuffer(GL_ARRAY_BUFFER, headVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, headEBO);
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

void Person::BuildBody() {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &bodyTexture);
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image(textureLoc, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &bodyTextures);
	glBindTexture(GL_TEXTURE_2D, bodyTextures);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5, 20.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  1.0f, // 0  Kiri Bawah
		 0.5, -0.5, 0.5, 28.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  1.0f, // 1	Kanan Bawah
		 0.5,  0.5, 0.5, 28.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  1.0f, // 2	Kanan Atas
		-0.5,  0.5, 0.5, 20.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  1.0f, // 3	Kiri Atas

		// right
		0.5,  0.5,  0.5, 16.0 / 64.0, 8.0 / 64, 1.0f,  0.0f,  0.0f, // 4   Depan Atas
		0.5,  0.5, -0.5, 24.0 / 64.0, 8.0 / 64, 1.0f,  0.0f,  0.0f, // 5	Belakang Bawah
		0.5, -0.5, -0.5, 24.0 / 64.0, 16.0 / 64, 1.0f,  0.0f,  0.0f, // 6	Belakang Atas
		0.5, -0.5,  0.5, 16.0 / 64.0, 16.0 / 64, 1.0f,  0.0f,  0.0f, // 7	Depan Atas

		// back
		-0.5, -0.5, -0.5, 32.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 8 
		0.5,  -0.5, -0.5, 40.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 9
		0.5,   0.5, -0.5, 40.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 32.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5,  0.0 / 64.0, 16.0 / 64.0, -1.0f,  0.0f,  0.0f, // 12 Depan Atas
		-0.5, -0.5,  0.5,  8.0 / 64.0, 16.0 / 64.0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		-0.5,  0.5,  0.5,  8.0 / 64.0, 8.0 / 64.0, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		-0.5,  0.5, -0.5,  0.0 / 64.0, 8.0 / 64.0, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// upper
		 0.5, 0.5,  0.5,  8.0 / 64.0, 16.0 / 64.0,   0.0f,  1.0f,  0.0f, // 16 Kiri Depan
		-0.5, 0.5,  0.5, 16.0 / 64.0, 16.0 / 64.0,   0.0f,  1.0f,  0.0f, // 17 Kanan Depan
		-0.5, 0.5, -0.5, 16.0 / 64.0, 8.0 / 64.0,  0.0f,  1.0f,  0.0f, // 18 Kanan Belakang
		 0.5, 0.5, -0.5,  8.0 / 64.0, 8.0 / 64.0,   0.0f,  1.0f,  0.0f, // 19 Kiri Belakang

		 // bottom
		 -0.5, -0.5, -0.5, 16.0 / 64.0, 64.0 / 64,  0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		  0.5, -0.5, -0.5, 24.0 / 64.0, 64.0 / 64,  0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		  0.5, -0.5,  0.5, 24.0 / 64.0, 8.0 / 64,  0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		 -0.5, -0.5,  0.5, 16.0 / 64.0, 8.0 / 64,  0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &BodyVAO);
	glGenBuffers(1, &BodyVBO);
	glGenBuffers(1, &BodyEBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(BodyVAO);

	glBindBuffer(GL_ARRAY_BUFFER, BodyVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BodyEBO);
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

void Person::BuildArms() {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &armsTexture);
	glBindTexture(GL_TEXTURE_2D, armsTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image(textureLoc, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &armsTextures);
	glBindTexture(GL_TEXTURE_2D, armsTextures);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5, 44.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  1.0f, // 0  Kiri Bawah
		 0.5, -0.5, 0.5, 48.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  1.0f, // 1	Kanan Bawah
		 0.5,  0.5, 0.5, 48.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  1.0f, // 2	Kanan Atas
		-0.5,  0.5, 0.5, 44.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  1.0f, // 3	Kiri Atas

		// right
		0.5,  0.5,  0.5, 52.0 / 64.0, 20.0 / 64.0, 1.0f,  0.0f,  0.0f, // 4   Depan Bawah
		0.5,  0.5, -0.5, 48.0 / 64.0, 20.0 / 64.0, 1.0f,  0.0f,  0.0f, // 5	Belakang Bawah
		0.5, -0.5, -0.5, 48.0 / 64.0, 32.0 / 64.0, 1.0f,  0.0f,  0.0f, // 6	Belakang Atas
		0.5, -0.5,  0.5, 52.0 / 64.0, 32.0 / 64.0, 1.0f,  0.0f,  0.0f, // 7	Depan Atas

		// back
		-0.5, -0.5, -0.5, 52.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 8 
		 0.5, -0.5, -0.5, 56.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 9
		 0.5,  0.5, -0.5, 56.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 52.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5,  44.0 / 64.0, 32.0 / 64.0, -1.0f,  0.0f,  0.0f, // 12 Depan Bawah
		-0.5, -0.5,  0.5,  40.0 / 64.0, 32.0 / 64.0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		-0.5,  0.5,  0.5,  40.0 / 64.0, 20.0 / 64.0, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		-0.5,  0.5, -0.5,  44.0 / 64.0, 20.0 / 64.0, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// upper
		 0.5, 0.5,  0.5,  8.0 / 64.0, 16.0 / 64.0,   0.0f,  1.0f,  0.0f, // 16 Kiri Depan
		-0.5, 0.5,  0.5, 16.0 / 64.0, 16.0 / 64.0,   0.0f,  1.0f,  0.0f, // 17 Kanan Depan
		-0.5, 0.5, -0.5, 16.0 / 64.0, 8.0 / 64.0,  0.0f,  1.0f,  0.0f, // 18 Kanan Belakang
		 0.5, 0.5, -0.5,  8.0 / 64.0, 8.0 / 64.0,   0.0f,  1.0f,  0.0f, // 19 Kiri Belakang

		 // bottom
		 -0.5, -0.5, -0.5, 16.0 / 64.0, 64.0 / 64,  0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		  0.5, -0.5, -0.5, 24.0 / 64.0, 64.0 / 64,  0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		  0.5, -0.5,  0.5, 24.0 / 64.0, 8.0 / 64,  0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		 -0.5, -0.5,  0.5, 16.0 / 64.0, 8.0 / 64,  0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &ArmsVAO);
	glGenBuffers(1, &ArmsVBO);
	glGenBuffers(1, &ArmsEBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(ArmsVAO);

	glBindBuffer(GL_ARRAY_BUFFER, ArmsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ArmsEBO);
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

void Person::BuildLegs() {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &legsTexture);
	glBindTexture(GL_TEXTURE_2D, legsTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image(textureLoc, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &legsTextures);
	glBindTexture(GL_TEXTURE_2D, legsTextures);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5,  4.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  1.0f, // 0  Kiri Bawah
		 0.5, -0.5, 0.5,  8.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  1.0f, // 1	Kanan Bawah
		 0.5,  0.5, 0.5,  8.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  1.0f, // 2	Kanan Atas
		-0.5,  0.5, 0.5,  4.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  1.0f, // 3	Kiri Atas

		// right
		0.5,  0.5,  0.5,  8.0 / 64.0, 20.0 / 64.0, 1.0f,  0.0f,  0.0f, // 4   Depan Bawah
		0.5,  0.5, -0.5, 12.0 / 64.0, 20.0 / 64.0, 1.0f,  0.0f,  0.0f, // 5	Belakang Bawah
		0.5, -0.5, -0.5, 12.0 / 64.0, 32.0 / 64.0, 1.0f,  0.0f,  0.0f, // 6	Belakang Atas
		0.5, -0.5,  0.5,  8.0 / 64.0, 32.0 / 64.0, 1.0f,  0.0f,  0.0f, // 7	Depan Atas

		// back
		-0.5, -0.5, -0.5, 12.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 8 
		 0.5, -0.5, -0.5, 16.0 / 64.0, 32.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 9
		 0.5,  0.5, -0.5, 16.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 12.0 / 64.0, 20.0 / 64.0, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5,  0.0 / 64.0, 32.0 / 64.0, -1.0f,  0.0f,  0.0f, // 12 Depan Bawah
		-0.5, -0.5,  0.5,  4.0 / 64.0, 32.0 / 64.0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		-0.5,  0.5,  0.5,  4.0 / 64.0, 20.0 / 64.0, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		-0.5,  0.5, -0.5,  0.0 / 64.0, 20.0 / 64.0, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// upper
		 0.5, 0.5,  0.5,  8.0 / 64.0, 16.0 / 64.0,   0.0f,  1.0f,  0.0f, // 16 Kiri Depan
		-0.5, 0.5,  0.5, 16.0 / 64.0, 16.0 / 64.0,   0.0f,  1.0f,  0.0f, // 17 Kanan Depan
		-0.5, 0.5, -0.5, 16.0 / 64.0, 8.0 / 64.0,  0.0f,  1.0f,  0.0f, // 18 Kanan Belakang
		 0.5, 0.5, -0.5,  8.0 / 64.0, 8.0 / 64.0,   0.0f,  1.0f,  0.0f, // 19 Kiri Belakang

		 // bottom
		 -0.5, -0.5, -0.5, 16.0 / 64.0, 64.0 / 64,  0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		  0.5, -0.5, -0.5, 24.0 / 64.0, 64.0 / 64,  0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		  0.5, -0.5,  0.5, 24.0 / 64.0, 8.0 / 64,  0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		 -0.5, -0.5,  0.5, 16.0 / 64.0, 8.0 / 64,  0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &LegsVAO);
	glGenBuffers(1, &LegsVBO);
	glGenBuffers(1, &LegsEBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(LegsVAO);

	glBindBuffer(GL_ARRAY_BUFFER, LegsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, LegsEBO);
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

void Person::DrawAll() {
	//1 kotak -> 0.0625
	//2 kotak -> 0.125
	//3 kotak -> 0.1875
	//4 kotak -> 0.25
	//6 kotak -> 0.375
	//7 kotak -> 0.4375

	float personSize = 1.1875f;

	DrawHead(     0 / personSize,   1.5 / personSize, 1 / personSize,  0.5 / personSize,  0.5 / personSize,  0.5 / personSize);
	DrawBody(     0 / personSize, 0.875 / personSize, 1 / personSize,  0.5 / personSize, 0.75 / personSize, 0.25 / personSize);

	//Draw Arms
	DrawArms( 0.375 / personSize, 0.875 / personSize, 1 / personSize, 0.25 / personSize, 0.75 / personSize, 0.25 / personSize); //left arm
	DrawArms(-0.375 / personSize, 0.875 / personSize, 1 / personSize, 0.25 / personSize, 0.75 / personSize, 0.25 / personSize); //right arm

	//Draw Legs
	DrawLegs( 0.125 / personSize, 0.125 / personSize, 1 / personSize, 0.25 / personSize, 0.75 / personSize, 0.25 / personSize); //left leg
	DrawLegs(-0.125 / personSize, 0.125 / personSize, 1 / personSize, 0.25 / personSize, 0.75 / personSize, 0.25 / personSize); //right leg
}

void Person::DrawHead(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, headTexture);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, headTextures);

	glBindVertexArray(headVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);
}

void Person::DrawBody(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "material.diffuse"), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, bodyTextures);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "material.specular"), 1);

	GLint shininessMatLoc = glGetUniformLocation(this->shaderProgram, "material.shininess");
	glUniform1f(shininessMatLoc, 10.0f);

	glBindVertexArray(BodyVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);
}

void Person::DrawArms(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, armsTexture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "material.diffuse"), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, armsTexture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "material.specular"), 1);

	GLint shininessMatLoc = glGetUniformLocation(this->shaderProgram, "material.shininess");
	glUniform1f(shininessMatLoc, 10.0f);

	glBindVertexArray(ArmsVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);
}

void Person::DrawLegs(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, legsTexture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "material.diffuse"), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, legsTexture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "material.specular"), 1);

	GLint shininessMatLoc = glGetUniformLocation(this->shaderProgram, "material.shininess");
	glUniform1f(shininessMatLoc, 10.0f);

	glBindVertexArray(LegsVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);
}