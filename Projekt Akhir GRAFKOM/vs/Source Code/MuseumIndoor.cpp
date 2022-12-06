#include "MuseumIndoor.h"

MuseumIndoor::MuseumIndoor() {

}

void MuseumIndoor::BuildAll(unsigned int* depthCubeMap, unsigned int sizeOfLights) {

	//Masukin depthCubeMap
	this->depthCubeMap = depthCubeMap;
	this->sizeOfLights = sizeOfLights;

	//Build berbagai macam objek
	BuildLantai();
	BuildDinding();
	BuildKarpet();
	BuildPillar();
	BuildDoor();
	BuildPedestal1();
}

void MuseumIndoor::BuildLantai()
{
	// Load and create a texture 
	glGenTextures(1, &textureLantai);
	glBindTexture(GL_TEXTURE_2D, textureLantai);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("marble.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &stexture2);
	glBindTexture(GL_TEXTURE_2D, stexture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("marble_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords

		// Lantai
		-10.0, -0.5, -25.0,  0,  0, 0.0f,  1.0f,  0.0f, // 0 Kiri Depan
		 10.0, -0.5, -25.0, 10,  0, 0.0f,  1.0f,  0.0f, // 1 Kanan Depan
		 10.0, -0.5,  25.0, 10, 15, 0.0f,  1.0f,  0.0f, // 2 Kanan Belakang
		-10.0, -0.5,  25.0,  0, 15, 0.0f,  1.0f,  0.0f, // 3 Kiri Belakang

		// Tembok depan
		-10.0, -0.5, -15.0,  0,  0, 0.0f,  0.0f,  1.0f, // 4 Kiri Bawah
		 10.0, -0.5, -15.0, 50,  0, 0.0f,  0.0f,  1.0f, // 5 Kanan Bawah
		 10.0, 10.0, -15.0, 50, 50, 0.0f,  0.0f,  1.0f, // 6 Kanan Atas
		-10.0, 10.0, -15.0,  0, 50, 0.0f,  0.0f,  1.0f, // 7 Kiri Atas

		// Tembok kiri
		-10.0, -0.5, -15.0,  0,  0, 1.0f,  0.0f,  0.0f, // 8 Depan Atas
		-10.0, -0.5,  15.0, 50,  0, 1.0f,  0.0f,  0.0f, // 9 Belakang Bawah
		-10.0, 10.0,  15.0, 50, 50, 1.0f,  0.0f,  0.0f, // 10 Belakang Atas
		-10.0, 10.0, -15.0,  0, 50, 1.0f,  0.0f,  0.0f, // 11 Depan Atas

		// Tembok Kanan
		10.0, -0.5, -15.0,  0,  0, -1.0f,  0.0f,  0.0f, // 12 Depan Atas
		10.0, -0.5,  15.0, 50,  0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		10.0, 10.0,  15.0, 50, 50, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		10.0, 10.0, -15.0,  0, 50, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// Tembok Belakang

		-10.0, -0.5, 15.0,  0,  0, 0.0f,  0.0f,  -1.0f, // 16 Kiri Bawah
		 10.0, -0.5, 15.0, 50,  0, 0.0f,  0.0f,  -1.0f, // 17 Kanan Bawah
		 10.0, 10.0, 15.0, 50, 50, 0.0f,  0.0f,  -1.0f, // 18 Kanan Atas
		-10.0, 10.0, 15.0,  0, 50, 0.0f,  0.0f,  -1.0f, // 19 Kiri Atas

		// Atap
		-10.0, 10.0, -15.0,  0,  0, 0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		 10.0, 10.0, -15.0, 10,  0, 0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		 10.0, 10.0,  15.0, 10, 10, 0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		-10.0, 10.0,  15.0,  0, 10, 0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	GLuint indices[] = {
		//Lantai
		0, 2, 1, 0, 3, 2,
		//Tembok depan
		//4, 6 ,5 ,4 ,7 ,6,
		//Tembok kiri
		//8, 9, 10, 8, 11, 10,
		//Tembok kanan
		//12,13,14,12,15,14,
		//Tembok belakang
		//16,17,18,16,19,18,
		//Atap
		//20,21,22,20,23,22
	};

	glGenVertexArrays(1, &VAOLantai);
	glGenBuffers(1, &VBOLantai);
	glGenBuffers(1, &EBOLantai);

	glBindVertexArray(VAOLantai);

	glBindBuffer(GL_ARRAY_BUFFER, VBOLantai);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOLantai);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);


	glBindVertexArray(0); // Unbind VAO
}

void MuseumIndoor::BuildKarpet()
{
	// Load and create a texture 
	glGenTextures(1, &textureKarpet);
	glBindTexture(GL_TEXTURE_2D, textureKarpet);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("red_carpet.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	/*glGenTextures(1, &stexture2);
	glBindTexture(GL_TEXTURE_2D, stexture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("marble_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);*/

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords

		// Lantai
		-2.5, -0.4, -19.0,  0,  0, 0.0f,  1.0f,  0.0f, // 0 Kiri Depan
		 2.5, -0.4, -19.0, 10,  0, 0.0f,  1.0f,  0.0f, // 1 Kanan Depan
		 2.5, -0.4,  19.0, 10, 15, 0.0f,  1.0f,  0.0f, // 2 Kanan Belakang
		-2.5, -0.4,  19.0,  0, 15, 0.0f,  1.0f,  0.0f, // 3 Kiri Belakang

		// Tembok depan
		-10.0, -0.5, -15.0,  0,  0, 0.0f,  0.0f,  1.0f, // 4 Kiri Bawah
		 10.0, -0.5, -15.0, 50,  0, 0.0f,  0.0f,  1.0f, // 5 Kanan Bawah
		 10.0, 10.0, -15.0, 50, 50, 0.0f,  0.0f,  1.0f, // 6 Kanan Atas
		-10.0, 10.0, -15.0,  0, 50, 0.0f,  0.0f,  1.0f, // 7 Kiri Atas

		// Tembok kiri
		-10.0, -0.5, -15.0,  0,  0, 1.0f,  0.0f,  0.0f, // 8 Depan Atas
		-10.0, -0.5,  15.0, 50,  0, 1.0f,  0.0f,  0.0f, // 9 Belakang Bawah
		-10.0, 10.0,  15.0, 50, 50, 1.0f,  0.0f,  0.0f, // 10 Belakang Atas
		-10.0, 10.0, -15.0,  0, 50, 1.0f,  0.0f,  0.0f, // 11 Depan Atas

		// Tembok Kanan
		10.0, -0.5, -15.0,  0,  0, -1.0f,  0.0f,  0.0f, // 12 Depan Atas
		10.0, -0.5,  15.0, 50,  0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		10.0, 10.0,  15.0, 50, 50, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		10.0, 10.0, -15.0,  0, 50, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// Tembok Belakang

		-10.0, -0.5, 15.0,  0,  0, 0.0f,  0.0f,  -1.0f, // 16 Kiri Bawah
		 10.0, -0.5, 15.0, 50,  0, 0.0f,  0.0f,  -1.0f, // 17 Kanan Bawah
		 10.0, 10.0, 15.0, 50, 50, 0.0f,  0.0f,  -1.0f, // 18 Kanan Atas
		-10.0, 10.0, 15.0,  0, 50, 0.0f,  0.0f,  -1.0f, // 19 Kiri Atas

		// Atap
		-10.0, 10.0, -15.0,  0,  0, 0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		 10.0, 10.0, -15.0, 10,  0, 0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		 10.0, 10.0,  15.0, 10, 10, 0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		-10.0, 10.0,  15.0,  0, 10, 0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	GLuint indices[] = {
		//Lantai
		0, 2, 1, 0, 3, 2,
		//Tembok depan
		//4, 6 ,5 ,4 ,7 ,6,
		//Tembok kiri
		//8, 9, 10, 8, 11, 10,
		//Tembok kanan
		//12,13,14,12,15,14,
		//Tembok belakang
		//16,17,18,16,19,18,
		//Atap
		//20,21,22,20,23,22
	};

	glGenVertexArrays(1, &VAOKarpet);
	glGenBuffers(1, &VBOKarpet);
	glGenBuffers(1, &EBOKarpet);

	glBindVertexArray(VAOKarpet);

	glBindBuffer(GL_ARRAY_BUFFER, VBOKarpet);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOKarpet);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);


	glBindVertexArray(0); // Unbind VAO
}

void MuseumIndoor::BuildDinding()
{
	// Load and create a texture 
	glGenTextures(1, &textureDinding);
	glBindTexture(GL_TEXTURE_2D, textureDinding);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("wall.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &stextureDinding);
	glBindTexture(GL_TEXTURE_2D, stextureDinding);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords

		// Lantai
		-10.0, -0.5, -25.0,  0,  0, 0.0f,  1.0f,  0.0f, // 0 Kiri Depan
		 10.0, -0.5, -25.0, 10,  0, 0.0f,  1.0f,  0.0f, // 1 Kanan Depan
		 10.0, -0.5,  25.0, 10, 10, 0.0f,  1.0f,  0.0f, // 2 Kanan Belakang
		-10.0, -0.5,  25.0,  0, 10, 0.0f,  1.0f,  0.0f, // 3 Kiri Belakang

		// Tembok depan
		-10.0, -0.5, -25.0,  0,  0, 0.0f,  0.0f,  1.0f, // 4 Kiri Bawah
		 10.0, -0.5, -25.0, 10,  0, 0.0f,  0.0f,  1.0f, // 5 Kanan Bawah
		 10.0, 10.0, -25.0,  3,  7, 0.0f,  0.0f,  1.0f, // 6 Kanan Atas
		-10.0, 10.0, -25.0,  0,  8, 0.0f,  0.0f,  1.0f, // 7 Kiri Atas

		// Tembok kiri
		-10.0, -0.5, -25.0,  0,  0, 1.0f,  0.0f,  0.0f, // 8 Depan Atas
		-10.0, -0.5,  25.0,  4,  0, 1.0f,  0.0f,  0.0f, // 9 Belakang Bawah
		-10.0, 10.0,  25.0,  9,  5, 1.0f,  0.0f,  0.0f, // 10 Belakang Atas
		-10.0, 10.0, -25.0,  0,  3, 1.0f,  0.0f,  0.0f, // 11 Depan Atas

		// Tembok Kanan
		10.0, -0.5, -25.0,  0,  0, -1.0f,  0.0f,  0.0f, // 12 Depan Atas
		10.0, -0.5,  25.0,  7,  0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		10.0, 10.0,  25.0, 10,  2, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		10.0, 10.0, -25.0,  0,  5, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// Tembok Belakang

		-10.0, -0.5, 25.0,  0,  0, 0.0f,  0.0f,  -1.0f, // 16 Kiri Bawah
		 10.0, -0.5, 25.0,  7,  0, 0.0f,  0.0f,  -1.0f, // 17 Kanan Bawah
		 10.0, 10.0, 25.0,  6,  5, 0.0f,  0.0f,  -1.0f, // 18 Kanan Atas
		-10.0, 10.0, 25.0,  0,  4, 0.0f,  0.0f,  -1.0f, // 19 Kiri Atas

		// Atap
		-10.0, 10.0, -25.0,  0,  0, 0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		 10.0, 10.0, -25.0, 1,  0, 0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		 10.0, 10.0,  25.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		-10.0, 10.0,  25.0,  0, 1, 0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	GLuint indices[] = {
		//Lantai
		//0, 2, 1, 0, 3, 2,
		//Tembok depan
		4, 6 ,5 ,4 ,7 ,6,
		//Tembok kiri
		8, 9, 10, 8, 11, 10,
		//Tembok kanan
		12,13,14,12,15,14,
		//Tembok belakang
		16,17,18,16,19,18,
		//Atap
		20,21,22,20,23,22
	};

	glGenVertexArrays(1, &VAODinding);
	glGenBuffers(1, &VBODinding);
	glGenBuffers(1, &EBODinding);

	glBindVertexArray(VAODinding);

	glBindBuffer(GL_ARRAY_BUFFER, VBODinding);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBODinding);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);


	glBindVertexArray(0); // Unbind VAO
}

void MuseumIndoor::BuildPillar()
{
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &texturePillar);
	glBindTexture(GL_TEXTURE_2D, texturePillar);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("wall.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &VAOPillar);
	glBindTexture(GL_TEXTURE_2D, VAOPillar);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		0.5, -0.5, 0.5, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		0.5,  0.5, 0.5, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		-0.5,  0.5, 0.5, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		// right
		0.5,  0.5,  0.5, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		0.5,  0.5, -0.5, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		0.5, -0.5, -0.5, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		0.5, -0.5,  0.5, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		-0.5, -0.5, -0.5, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		0.5,  -0.5, -0.5, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		0.5,   0.5, -0.5, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		-0.5, -0.5,  0.5, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		-0.5,  0.5,  0.5, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		-0.5,  0.5, -0.5, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.5, 0.5,  0.5, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		-0.5, 0.5, 0.5, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		-0.5, 0.5, -0.5, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.5, 0.5, -0.5, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		-0.5, -0.5, -0.5, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		0.5, -0.5, -0.5, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		0.5, -0.5,  0.5, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
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

	glGenVertexArrays(1, &VAOPillar);
	glGenBuffers(1, &VBOPillar);
	glGenBuffers(1, &EBOPillar);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOPillar);

	glBindBuffer(GL_ARRAY_BUFFER, VBOPillar);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPillar);
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

void MuseumIndoor::BuildDoor()
{
	// Load and create a texture 
	glGenTextures(1, &textureDoor);
	glBindTexture(GL_TEXTURE_2D, textureDoor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("door.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	/*glGenTextures(1, &stextureDinding);
	glBindTexture(GL_TEXTURE_2D, stextureDinding);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("wall_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);*/

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords

		// Lantai
		-10.0, -0.5, -25.0,  0,  0, 0.0f,  1.0f,  0.0f, // 0 Kiri Depan
		 10.0, -0.5, -25.0, 10,  0, 0.0f,  1.0f,  0.0f, // 1 Kanan Depan
		 10.0, -0.5,  25.0, 10, 10, 0.0f,  1.0f,  0.0f, // 2 Kanan Belakang
		-10.0, -0.5,  25.0,  0, 10, 0.0f,  1.0f,  0.0f, // 3 Kiri Belakang

		// Tembok depan
		-10.0, -0.5, -25.0,  0,  0, 0.0f,  0.0f,  -1.0f, // 4 Kiri Bawah
		 10.0, -0.5, -25.0, 10,  0, 0.0f,  0.0f,  -1.0f, // 5 Kanan Bawah
		 10.0, 10.0, -25.0,  3,  7, 0.0f,  0.0f,  -1.0f, // 6 Kanan Atas
		-10.0, 10.0, -25.0,  0,  8, 0.0f,  0.0f,  -1.0f, // 7 Kiri Atas

		// Tembok kiri
		-10.0, -0.5, -25.0,  0,  0, 1.0f,  0.0f,  0.0f, // 8 Depan Atas
		-10.0, -0.5,  25.0, 4,  0, 1.0f,  0.0f,  0.0f, // 9 Belakang Bawah
		-10.0, 10.0,  25.0, 9, 5, 1.0f,  0.0f,  0.0f, // 10 Belakang Atas
		-10.0, 10.0, -25.0,  0, 3, 1.0f,  0.0f,  0.0f, // 11 Depan Atas

		// Tembok Kanan
		10.0, -0.5, -25.0,  0,  0, -1.0f,  0.0f,  0.0f, // 12 Depan Atas
		10.0, -0.5,  25.0, 7,  0, -1.0f,  0.0f,  0.0f, // 13 Belakang Bawah
		10.0, 10.0,  25.0, 10, 2, -1.0f,  0.0f,  0.0f, // 14 Belakang Atas
		10.0, 10.0, -25.0,  0, 5, -1.0f,  0.0f,  0.0f, // 15 Depan Atas

		// Tembok Belakang

		-1.5, -0.5, 24.9,  0,  0, 0.0f,  0.0f,  1.0f, // 16 Kiri Bawah
		 1.5, -0.5, 24.9,  1,  0, 0.0f,  0.0f,  1.0f, // 17 Kanan Bawah
		 1.5,  3.0, 24.9,  1,  1, 0.0f,  0.0f,  1.0f, // 18 Kanan Atas
		-1.5,  3.0, 24.9,  0,  1, 0.0f,  0.0f,  1.0f, // 19 Kiri Atas

		// Atap
		-10.0, 10.0, -25.0,  0,  0, 0.0f,  -1.0f,  0.0f, // 20 Kiri Depan
		 10.0, 10.0, -25.0, 1,  0, 0.0f,  -1.0f,  0.0f, // 21 Kanan Depan
		 10.0, 10.0,  25.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 22 Kanan Belakang
		-10.0, 10.0,  25.0,  0, 1, 0.0f,  -1.0f,  0.0f, // 23 Kiri Belakang
	};

	GLuint indices[] = {
		//Lantai
		//0, 2, 1, 0, 3, 2,
		//Tembok depan
		//4, 6 ,5 ,4 ,7 ,6,
		//Tembok kiri
		//8, 9, 10, 8, 11, 10,
		//Tembok kanan
		//12,13,14,12,15,14,
		//Tembok belakang
		16,17,18,16,19,18,
		//Atap
		//20,21,22,20,23,22
	};

	glGenVertexArrays(1, &VAODoor);
	glGenBuffers(1, &VBODoor);
	glGenBuffers(1, &EBODoor);

	glBindVertexArray(VAODoor);

	glBindBuffer(GL_ARRAY_BUFFER, VBODoor);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBODoor);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);


	glBindVertexArray(0); // Unbind VAO
}

void MuseumIndoor::BuildPedestal1(){
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &texturePedestal1);
	glBindTexture(GL_TEXTURE_2D, texturePedestal1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("concrete.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &stexturePedestal1);
	glBindTexture(GL_TEXTURE_2D, stexturePedestal1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("lighting_maps_specular_color.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.75, -0.32,  0.29, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		 0.75, -0.32,  0.29, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		 0.25,  0.32,  0.29, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		-0.25,  0.32,  0.29, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		// right
		 0.25,  0.32,  0.29, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 0.25,  0.32, -0.29, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 0.75, -0.32, -0.29, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 0.75, -0.32,  0.29, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		-0.75, -0.32, -0.29, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		 0.75, -0.32, -0.29, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		 0.25,  0.32, -0.29, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		-0.25,  0.32, -0.29, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.75, -0.32, -0.29, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		-0.75, -0.32,  0.29, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		-0.25,  0.32,  0.29, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		-0.25,  0.32, -0.29, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		 0.25,  0.32,  0.29, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		-0.25,  0.32,  0.29, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		-0.25,  0.32, -0.29, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		 0.25,  0.32, -0.29, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		-0.75, -0.32, -0.29, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		 0.75, -0.32, -0.29, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		 0.75, -0.32,  0.29, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		-0.75, -0.32,  0.29, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &VAOPedestal1);
	glGenBuffers(1, &VBOPedestal1);
	glGenBuffers(1, &EBOPedestal1);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOPedestal1);

	glBindBuffer(GL_ARRAY_BUFFER, VBOPedestal1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPedestal1);
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

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void MuseumIndoor::DrawAll(GLuint shaderProgram) {
	//Masukin shaderProgram dari input ke shaderProgram kelas ini
	this->shaderProgram = shaderProgram;

	DrawLantai();
	DrawDinding();
	DrawKarpet();
	//Pillar Sebelah kiri
	DrawPillar(-3.5, -6);
	DrawPillar(-3.5, 0);
	DrawPillar(-3.5, 6);
	DrawPillar(-3.5, 12);
	DrawPillar(-3.5, 18);
	//Pillar Sebelah Kanan
	DrawPillar(3.5, -6);
	DrawPillar(3.5, 0);
	DrawPillar(3.5, 6);
	DrawPillar(3.5, 12);
	DrawPillar(3.5, 18);
	//Pintu Masuk
	DrawDoor();
	//Pedetals
	DrawPedestal1(0, -0.25, -22.5);
}

void MuseumIndoor::DrawLantai() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureLantai);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		glActiveTexture(GL_TEXTURE1 + i + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(VAOLantai); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void MuseumIndoor::DrawKarpet() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureKarpet);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		glActiveTexture(GL_TEXTURE1 + i + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(VAOKarpet); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void MuseumIndoor::DrawDinding() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureDinding);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		glActiveTexture(GL_TEXTURE1 + i + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	//Specular
	GLint light_specular = glGetUniformLocation(shaderProgram, "light.specular");
	glUniform3f(light_specular, 0.2f, 0.2f, 0.2f);

	// material properties
	GLint material_shininess = glGetUniformLocation(shaderProgram, "material.shininess");
	glUniform1f(material_shininess, 32.0f);

	glBindVertexArray(VAODinding); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void MuseumIndoor::DrawDoor() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureDoor);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		glActiveTexture(GL_TEXTURE1 + i + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(VAODoor); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void MuseumIndoor::DrawPillar(float xPos, float zPos)
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturePillar);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		glActiveTexture(GL_TEXTURE1 + i + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(VAOPillar); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0, 0, 0));

	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	/*glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);*/

	for (int i = 3; i > 0; i--) {
		glm::mat4 model2;
		model2 = glm::translate(model2, glm::vec3(xPos, 0 - i * 0.125, zPos));
		if (i > 1) {
			model2 = glm::scale(model2, glm::vec3(0.2 + i * 0.4, 0.2, 0.2 + i * 0.4));
		}
		else {
			model2 = glm::scale(model2, glm::vec3(0.2 + i * 0.5, 20, 0.2 + i * 0.5));
		}


		glGetUniformLocation(this->shaderProgram, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model2));

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		
	}

	for (int i = 0; i < 3; i++) {

		glm::mat4 model2;
		model2 = glm::translate(model2, glm::vec3(xPos, 9.65 + i * 0.125, zPos));
		model2 = glm::scale(model2, glm::vec3(0.2 + i * 0.5, 0.2, 0.2 + i * 0.5));

		glGetUniformLocation(this->shaderProgram, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model2));

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void MuseumIndoor::DrawPedestal1(float xPos, float yPos, float zPos){
	glUseProgram(shaderProgram);

	// bind diffuse map
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturePedestal1);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		glActiveTexture(GL_TEXTURE1 + i + 1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(VAOPedestal1);

	//set mat4 model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, 0.0f, glm::vec3(0, 0, 1));

	model = glm::scale(model, glm::vec3(0.8, 0.8, 0.8));

	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

