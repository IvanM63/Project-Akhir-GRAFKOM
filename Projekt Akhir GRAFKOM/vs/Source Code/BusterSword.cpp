#include "BusterSword.h"

BusterSword::BusterSword() {

}

void BusterSword::BuildAll() {
	BuildCube();
	BuildPrism();
	BuildPrismBilahTumpul();
	BuildPrismBilahTajam();
	BuildTexturedBilahKiri();

	//Load Texture warna
	loadTexture("colorTexture/coklat.png", 0);
	loadTexture("colorTexture/yellow_softDark.png", 1);
	loadTexture("colorTexture/light_grey.png", 2);
	loadTexture("colorTexture/dark_grey.png", 3);
}

void BusterSword::BuildCube() {
	//Taro shaderProgram ke this

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

	glGenVertexArrays(1, &VAO4);
	glGenBuffers(1, &VBO4);
	glGenBuffers(1, &EBO4);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO4);

	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO4);
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

void BusterSword::BuildPrism() {
	//Taro shaderProgram ke this
	// 
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 


	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		// front
		-0.5, -0.5, 0.5,  0.0f,  0.0f,  1.0f, // 0
		0.5, -0.5, 0.0,   0.0f,  0.0f,  1.0f, // 1 Titik Tengah
		0.5,  0.575, 0.0,   0.0f,  0.0f,  1.0f, // 2 Titik Tengah || Moncong Ke atas
		-0.5,  0.5, 0.5,  0.0f,  0.0f,  1.0f, // 3

		// back
		-0.5, -0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 4 
		0.5,  -0.5, -0.0, 0.0f,  0.0f,  -1.0f, // 5 Titik Tengah
		0.5,   0.575, -0.0, 0.0f,  0.0f,  -1.0f, // 6 Titik Tengah || Moncong ke atas
		-0.5,  0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 7

		// left
		-0.5, -0.5, -0.5, -1.0f,  0.0f,  0.0f, // 8
		-0.5, -0.5,  0.5, -1.0f,  0.0f,  0.0f, // 9
		-0.5,  0.5,  0.5, -1.0f,  0.0f,  0.0f, // 10
		-0.5,  0.5, -0.5, -1.0f,  0.0f,  0.0f, // 11

		// upper
		0.5, 0.575,  0.0, 0.0f,  1.0f,  0.0f, // 12 Titik Tengah
		-0.5, 0.5, 0.5, 0.0f,  1.0f,  0.0f, // 13
		-0.5, 0.5, -0.5,0.0f,  1.0f,  0.0f, // 14
		0.5, 0.5, -0.5, 0.0f,  1.0f,  0.0f, // 15 Ga dipake

		// bottom
		-0.5, -0.5, -0.5, 0.0f,  -1.0f,  0.0f, // 16
		0.5, -0.5, -0.5,  0.0f,  -1.0f,  0.0f, // 17 Ga dipake
		0.5, -0.5,  0.0,  0.0f,  -1.0f,  0.0f, // 18 Titik Tengah
		-0.5, -0.5,  0.5, 0.0f,  -1.0f,  0.0f, // 19
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // back
		8,  9,  10, 8,  10, 11,  // left
		12, 14, 13,   // upper
		16, 19, 18,  // bottom
	};

	glGenVertexArrays(1, &VAOPrism);
	glGenBuffers(1, &VBOPrism);
	glGenBuffers(1, &EBOPrism);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOPrism);

	glBindBuffer(GL_ARRAY_BUFFER, VBOPrism);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPrism);
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

void BusterSword::BuildPrismBilahTumpul() {
	//Taro shaderProgram ke this

	// load image into texture memory
	// ------------------------------
	// Load and create a texture 


	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		// front
		-0.5, -0.5, 0.5,  0.0f,  0.0f,  1.0f, // 0 yes
		0.5, -0.5, 0.5,   0.0f,  0.0f,  1.0f, // 1 yes
		0.5,  0.5, 0.0,   0.0f,  0.0f,  1.0f, // 2 no gadipake
		-0.5,  0.5, 0.0,  0.0f,  0.0f,  1.0f, // 3 yes

		// back
		-0.5, -0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 4 yes
		0.5,  -0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 5 yes
		0.5,   0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 6 no
		-0.5,  0.5, -0.0, 0.0f,  0.0f,  -1.0f, // 7 yes Titik Tengah

		// left
		-0.5, -0.5, -0.5, -1.0f,  0.0f,  0.0f, // 8 di bawah belakang
		-0.5, -0.5,  0.5, -1.0f,  0.0f,  0.0f, // 9 di bawah depan
		-0.5,  0.5,  0.0, -1.0f,  0.0f,  0.0f, // 10 di atas depan || Titik Tengah
		-0.5,  0.5, -0.5, -1.0f,  0.0f,  0.0f, // 11 di atas belakang || Ga dipake
		
		// upper [Ga dipake]
		0.5, 0.5,  0.0, 0.0f,  1.0f,  0.0f, // 12 Titik Tengah
		-0.5, 0.5, 0.5, 0.0f,  1.0f,  0.0f, // 13
		-0.5, 0.5, -0.5,0.0f,  1.0f,  0.0f, // 14
		0.5, 0.5, -0.5, 0.0f,  1.0f,  0.0f, // 15 Ga dipake

		// bottom
		-0.5, -0.5, -0.5, 0.0f,  -1.0f,  0.0f, // 16
		0.5, -0.5, -0.5,  0.0f,  -1.0f,  0.0f, // 17 
		0.5, -0.5,  0.5,  0.0f,  -1.0f,  0.0f, // 18 
		-0.5, -0.5,  0.5, 0.0f,  -1.0f,  0.0f, // 19
	};

	unsigned int indices[] = {
		0,  1,  3,				// front
		4,  5,  7,				// back
		8,  9,  10,				// left
		16, 18, 17, 16,19,18	// bottom
	};

	glGenVertexArrays(1, &VAOPrismBilahTumpul);
	glGenBuffers(1, &VBOPrismBilahTumpul);
	glGenBuffers(1, &EBOPrismBilahTumpul);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOPrismBilahTumpul);

	glBindBuffer(GL_ARRAY_BUFFER, VBOPrismBilahTumpul);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPrismBilahTumpul);
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

void BusterSword::BuildPrismBilahTajam() {
	//Taro shaderProgram ke this

	// load image into texture memory
	// ------------------------------
	// Load and create a texture 


	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		// front
		-0.5, -0.5, 0.5,  0.0f,  0.0f,  1.0f, // 0 yes
		0.5, -0.5, 0.0,   0.0f,  0.0f,  1.0f, // 1 yes
		0.5,  0.5, 0.0,   0.0f,  0.0f,  1.0f, // 2 no gadipake
		-0.5,  0.5, 0.0,  0.0f,  0.0f,  1.0f, // 3 yes

		// back
		-0.5, -0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 4 yes
		0.5,  -0.5, -0.0, 0.0f,  0.0f,  -1.0f, // 5 yes
		0.5,   0.5, -0.5, 0.0f,  0.0f,  -1.0f, // 6 no
		-0.5,  0.5, -0.0, 0.0f,  0.0f,  -1.0f, // 7 yes Titik Tengah

		// left
		-0.5, -0.5, -0.5, -1.0f,  0.0f,  0.0f, // 8 di bawah belakang
		-0.5, -0.5,  0.5, -1.0f,  0.0f,  0.0f, // 9 di bawah depan
		-0.5,  0.5,  0.0, -1.0f,  0.0f,  0.0f, // 10 di atas depan || Titik Tengah
		-0.5,  0.5, -0.5, -1.0f,  0.0f,  0.0f, // 11 di atas belakang || Ga dipake

		// upper [Ga dipake]
		0.5, 0.5,  0.0, 0.0f,  1.0f,  0.0f, // 12 Titik Tengah
		-0.5, 0.5, 0.5, 0.0f,  1.0f,  0.0f, // 13
		-0.5, 0.5, -0.5,0.0f,  1.0f,  0.0f, // 14
		0.5, 0.5, -0.5, 0.0f,  1.0f,  0.0f, // 15 Ga dipake

		// bottom
		-0.5, -0.5, -0.5, 0.0f,  -1.0f,  0.0f, // 16
		0.5, -0.5, -0.0,  0.0f,  -1.0f,  0.0f, // 17 
		0.5, -0.5,  0.5,  0.0f,  -1.0f,  0.0f, // 18 Ga dipake
		-0.5, -0.5,  0.5, 0.0f,  -1.0f,  0.0f, // 19
	};

	unsigned int indices[] = {
		0,  1,  3,				// front
		4,  5,  7,				// back
		8,  9,  10,				// left
		16, 17, 19,	// bottom
	};

	glGenVertexArrays(1, &VAOPrismBilahLancip);
	glGenBuffers(1, &VBOPrismBilahLancip);
	glGenBuffers(1, &EBOPrismBilahLancip);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOPrismBilahLancip);

	glBindBuffer(GL_ARRAY_BUFFER, VBOPrismBilahLancip);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPrismBilahLancip);
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

void BusterSword::BuildTexturedBilahKiri() {
	//Taro shaderProgram ke this

	// load image into texture memory
	// ------------------------------
	// Load and create a texture 

	glGenTextures(1, &textureBilahKiri);
	glBindTexture(GL_TEXTURE_2D, textureBilahKiri);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("metal.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &stextureBilahKiri);
	glBindTexture(GL_TEXTURE_2D, stextureBilahKiri);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("metalSpecular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5, -0.5, 0.5,  0,  0, 0.0f,  0.0f,  1.0f, // 0 kiri bawah
		 0.5, -0.5, 0.5,  1,  0, 0.0f,  0.0f,  1.0f, // 1 kanan bawah
		 0.5,  0.5, 0.5,  1,  1, 0.0f,  0.0f,  1.0f, // 2 kanan atas
		-0.5,  0.5, 0.5,  0,  1, 0.0f,  0.0f,  1.0f, // 3 kiri atas

		// right
		0.5,  0.5,  0.5, 0,  0, 1.0f,  0.0f,  0.0f, // 4
		0.5,  0.5, -0.5,1,  0, 1.0f,  0.0f,  0.0f, // 5
		0.5, -0.5, -0.5,1, 1, 1.0f,  0.0f,  0.0f, // 6
		0.5, -0.5,  0.5, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		-0.5, -0.5, -0.5, 0,  0, 0.0f,  0.0f,  -1.0f, // 8 
		0.5,  -0.5, -0.5,1,  0, 0.0f,  0.0f,  -1.0f, // 9
		0.5,   0.5, -0.5,1, 1, 0.0f,  0.0f,  -1.0f, // 10
		-0.5,  0.5, -0.5, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		// left
		-0.5, -0.5, -0.5,  0,  0, -1.0f,  0.0f,  0.0f, // 12
		-0.5, -0.5,  0.5, 1,  0,-1.0f,  0.0f,  0.0f, // 13
		-0.5,  0.5,  0.5, 1, 1,-1.0f,  0.0f,  0.0f, // 14
		-0.5,  0.5, -0.5,  0, 1,-1.0f,  0.0f,  0.0f, // 15

		// upper
		0.5, 0.5,  0.5,  0,  0, 0.0f,  1.0f,  0.0f, // 16
		-0.5, 0.5, 0.5, 1,  0, 0.0f,  1.0f,  0.0f, // 17
		-0.5, 0.5, -0.5, 1, 1, 0.0f,  1.0f,  0.0f, // 18
		0.5, 0.5, -0.5,  0, 1, 0.0f,  1.0f,  0.0f, // 19

		// bottom
		-0.5, -0.5, -0.5, 0,  0, 0.0f,  -1.0f,  0.0f, // 20
		0.5, -0.5, -0.5, 1,  0, 0.0f,  -1.0f,  0.0f, // 21
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

	glGenVertexArrays(1, &VAOb);
	glGenBuffers(1, &VBOb);
	glGenBuffers(1, &EBOb);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOb);

	glBindBuffer(GL_ARRAY_BUFFER, VBOb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOb);
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

void BusterSword::DrawAll(GLuint shaderProgram) {
	shaderProgram1 = shaderProgram;
	//1 kotak -> 0.0625
	//2 kotak -> 0.125
	//3 kotak -> 0.1875
	//4 kotak -> 0.25
	//6 kotak -> 0.375
	//7 kotak -> 0.4375

	float busterSize = 2.25;

	//Pegangan
	DrawColoredCube(0       , 0.375 / busterSize , 5 / busterSize, 0.1875 / busterSize, 0.9375 / busterSize, 0.1875 / busterSize, 0);
	//gagangTengah
	DrawColoredCube(0       ,0.90625 / busterSize, 5 / busterSize, 0.3125 / busterSize, 0.125 / busterSize , 0.1875 / busterSize, 2);
	//gagangKuningKiri
	DrawColoredCube(-0.3125 / busterSize,0.90625 / busterSize, 5 / busterSize, 0.3125 / busterSize, 0.125 / busterSize, 0.1875 / busterSize, 1);
	//gagangKuningKiri
	DrawColoredCube( 0.3125 / busterSize,0.90625 / busterSize, 5 / busterSize, 0.3125 / busterSize, 0.125 / busterSize, 0.1875 / busterSize, 1);

	//Tengah Atas Gagang
	DrawColoredCube(0       ,1.21875 / busterSize, 5 / busterSize, 0.3125 / busterSize, 0.5 / busterSize, 0.1875 / busterSize, 3);
	//KuningAtasGagangKiri
	DrawColoredCube(-0.1875 / busterSize,1.25 / busterSize, 5 / busterSize, 0.0625 / busterSize, 0.5625 / busterSize, 0.1875 / busterSize, 1);
	//KuningAtasGagangKiri
	DrawColoredCube(0.1875 / busterSize,1.25 / busterSize, 5 / busterSize, 0.0625 / busterSize, 0.5625 / busterSize, 0.1875 / busterSize, 1);
	//KuningAtasGagangAtas
	DrawColoredCube(0       ,1.5 / busterSize, 5 / busterSize, 0.3125 / busterSize, 0.0625 / busterSize, 0.1875 / busterSize, 1);

	//Bilah Pedang Tumpul Kiri
	//DrawColoredCube(-0.34375 / busterSize,2.53125 / busterSize, 5 / busterSize, 0.25 / busterSize, 3.125 / busterSize, 0.1875 / busterSize, 0.58039f, 0.58039f, 0.57255f);
	DrawTexturedBilahKiri(-0.34375 / busterSize,2.53125 / busterSize, 5 / busterSize, 0.25 / busterSize, 3.125 / busterSize, 0.1875 / busterSize, 3);
	
	//Bilah Pedang Tumpul Tengah
	DrawColoredCube(0       , 2.8125 / busterSize, 5 / busterSize, 0.4375 / busterSize, 2.5625 / busterSize, 0.1875 / busterSize, 3);

	//Prism Bilah Tajam Kanan
	DrawColoredPrism(0.34375 / busterSize, 2.53125 / busterSize,5 / busterSize, 0.25 / busterSize, 3.125 / busterSize, 0.1875 / busterSize, 2);

	//Prism Bilah Tumpul atas
	DrawColoredPrismBilahTumpul(-0.125 / busterSize, 4.46875 / busterSize, 5 / busterSize, 0.6875 / busterSize, 0.75 / busterSize, 0.1875 / busterSize, 3);

	//Prism Bilah Lancip Atas
	DrawColoredPrismBilahLancip(0 / busterSize, 4.59375 / busterSize, 5 / busterSize, 0.46875 / busterSize, 1.0174262872562 / busterSize, 0.1875 / busterSize, 2);
}

void BusterSword::DrawColoredCube(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i) {
	glUseProgram(shaderProgram1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	glBindVertexArray(VAO4); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized


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

void BusterSword::DrawColoredPrism(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i) {
	glUseProgram(shaderProgram1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	glBindVertexArray(VAOPrism); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

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

void BusterSword::DrawColoredPrismBilahTumpul(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i) {
	glUseProgram(shaderProgram1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	glBindVertexArray(VAOPrismBilahTumpul); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

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

void BusterSword::DrawColoredPrismBilahLancip(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i) {
	glUseProgram(shaderProgram1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	glBindVertexArray(VAOPrismBilahLancip); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized


	xPos += mX;
	yPos += mY;
	zPos += mZ;

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xPos, yPos, zPos));

	model = glm::rotate(model, 0.6f, glm::vec3(0, 0, 1));

	model = glm::scale(model, glm::vec3(xSize, ySize, zSize));

	GLint modelLoc = glGetUniformLocation(shaderProgram1, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void BusterSword::DrawTexturedBilahKiri(float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, int i) {
	glUseProgram(shaderProgram1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, stextureBilahKiri);
	glUniform1i(glGetUniformLocation(this->shaderProgram1, "material.specular"), 1);

	GLint shininessMatLoc = glGetUniformLocation(this->shaderProgram1, "material.shininess");
	glUniform1f(shininessMatLoc, 10.0f);

	glBindVertexArray(VAOb); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

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
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);
}

void BusterSword::scaling(float x, float y, float z) {
	//float p = 0.0625 * (scale);
	//mX = x;
	//mY = y;
	//mZ = z;
	//sX = p;
	//sY = p;
	//sZ = p;
}

void BusterSword::setPosition(glm::vec3 position) {
	this->mX = position.x;
	this->mY = position.y;
	this->mZ = position.z;
}

void BusterSword::loadTexture(const char* textureLoc, int i) {
	// Load and create a texture 
	glGenTextures(1, &textures[i]);
	glBindTexture(GL_TEXTURE_2D, textures[i]);
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

	/*glGenTextures(1, &stextures[i]);
	glBindTexture(GL_TEXTURE_2D, stextures[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("marble_specular.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);*/
}