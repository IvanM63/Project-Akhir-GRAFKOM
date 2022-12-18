#include "Demo.h"
#include <vector>



Demo::Demo() {

}


Demo::~Demo() {
}


void Demo::BuildLight() {
	float vertices[] = {
		// format position, Vector Normal
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

	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &lightVBO);
	glGenBuffers(1, &lightEBO);
	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

}

void Demo::DrawLight(float lightX, float lightY, float lightZ, float colorR, float colorG, float colorB) {
	glUseProgram(lightShader);

	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	//lightColor
	GLint lightColorLoc = glGetUniformLocation(lightShader, "lightColor");
	glUniform3f(lightColorLoc, colorR, colorG, colorB);

	//set mat4 model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(lightX, lightY, lightZ));

	model = glm::rotate(model, 0.0f, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

	GLint modelLoc = glGetUniformLocation(this->lightShader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glBindVertexArray(lightVAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Demo::BuildLightSegitiga() {
	float vertices[] = {
		// format position, Vector Normal
		// front
		 -0.5, -0.5, 0.5, 0.0f,  0.0f,  1.0f, // 0
		  0.0,  0.5, 0.5, 0.0f,  0.0f,  1.0f, // 1
		  0.5, -0.5, 0.5, 0.0f,  0.0f,  1.0f, // 2
	
	};

	unsigned int indices[] = {
		0,  1,  2,   // front

	};

	glGenVertexArrays(1, &lightSegitigaVAO);
	glGenBuffers(1, &lightSegitigaVBO);
	glGenBuffers(1, &lightSegitigaEBO);
	glBindVertexArray(lightSegitigaVAO);

	glBindBuffer(GL_ARRAY_BUFFER, lightSegitigaVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightSegitigaEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

}

void Demo::DrawLightSegitiga(float lightX, float lightY, float lightZ, float colorR, float colorG, float colorB) {
	glUseProgram(lightShader);

	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	//lightColor
	GLint lightColorLoc = glGetUniformLocation(lightShader, "lightColor");
	glUniform3f(lightColorLoc, colorR, colorG, colorB);

	//set mat4 model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(lightX, lightY, lightZ));

	model = glm::rotate(model, 0.0f, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.18f));

	GLint modelLoc = glGetUniformLocation(this->lightShader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glBindVertexArray(lightSegitigaVAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Demo::BuildPlane() {
	// Load and create a texture 
	glGenTextures(1, &plane_texture);
	glBindTexture(GL_TEXTURE_2D, plane_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("wood.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);


	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords
		// bottom
		-25.0f,	-0.5f, -25.0f,  0,  0, 0.0f,  1.0f,  0.0f,
		 25.0f,	-0.5f, -25.0f, 25,  0, 0.0f,  1.0f,  0.0f,
		 25.0f,	-0.5f,  25.0f, 25, 25, 0.0f,  1.0f,  0.0f,
		-25.0f,	-0.5f,  25.0f,  0, 25, 0.0f,  1.0f,  0.0f,
	};

	GLuint indices[] = { 0,  2,  1,  0,  3,  2 };

	glGenVertexArrays(1, &planeVAO);
	glGenBuffers(1, &planeVBO);
	glGenBuffers(1, &planeEBO);

	glBindVertexArray(planeVAO);

	glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planeEBO);
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

void Demo::DrawPlane(GLuint shader) {
	UseShader(shader);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, plane_texture);

	for (unsigned int i = 0; i < 2; ++i) {
		glActiveTexture(GL_TEXTURE0 + i+1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(planeVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildTexturedCube() {

	//Load Texture
	glGenTextures(1, &textureCube);
	glBindTexture(GL_TEXTURE_2D, textureCube);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("crate.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	//Load Specular
	/*glGenTextures(1, &textureCubeSpecular);
	glBindTexture(GL_TEXTURE_2D, textureCubeSpecular);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image("lighting_maps_specular_color.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);*/

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
		-0.5, 0.5,  0.5, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		-0.5, 0.5, -0.5, 1, 1,   0.0f,  1.0f,  0.0f, // 18
		 0.5, 0.5, -0.5, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		 // bottom
		 -0.5, -0.5, -0.5, 0, 0,  0.0f,  -1.0f,  0.0f, // 20
		  0.5, -0.5, -0.5, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		  0.5, -0.5,  0.5, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		 -0.5, -0.5,  0.5, 0, 1,  0.0f,  -1.0f,  0.0f, // 23
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
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
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


	glBindVertexArray(0);

}

void Demo::DrawTexturedCube(GLuint shader)
{
	UseShader(shader);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureCube);

	for (unsigned int i = 0; i < 2; ++i) {
		glActiveTexture(GL_TEXTURE0 + i+1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i]);
	}

	glBindVertexArray(VAO);

	//set mat4 model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(2, 0.5, 0));

	model = glm::rotate(model, angle, glm::vec3(0, 0, 1));

	model = glm::scale(model, glm::vec3(1, 1, 1));

	GLint modelLoc = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}

void Demo::Init() {
	//|----- Build and Compile Our Shader Program -----|\\
	// ------------------------------------
	lightShader = BuildShader("lightShader.vert", "lightShader.frag", nullptr);
	shader = BuildShader("point_shadow.vert", "point_shadow.frag", nullptr);
	simpleDepthShader = BuildShader("point_shadows_depth.vert", "point_shadows_depth.frag", "point_shadows_depth.geom");
	
	BuildPlane();
	BuildTexturedCube();

	InitCamera();

	// Configure depthMap 
	// -----------------------

	for (unsigned int x = 0; x < sizeOfLights; ++x) {
		glGenFramebuffers(1, &depthMapFBO[x]);
		// create depth cubemap texture
		glGenTextures(1, &depthCubeMap[x]);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[x]);
		for (unsigned int i = 0; i < 6; ++i) {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		// attach depth texture as FBO's depth buffer
		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO[x]);
		glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthCubeMap[x], 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	//----------------------------------------//

	//Position For Lightning
	lightPos[0] = glm::vec3(0.0, 5.0,  15.0); //Putih Lampu Atas
	lightPos[1] = glm::vec3(saberPos.x, saberPos.y + 1.5, saberPos.z); //Merah LightSaber
	lightPos[2] = glm::vec3(masterPos.x, masterPos.y, masterPos.z + 1.0); //Kuning Pedestal Master Sword
	lightPos[3] = glm::vec3(0.0, 5.0, -16.5); //Putih Lampu Atas Tempat Pedang	  

	//|------- BUILD FUNCTION ALL -------|\\

	//Build Lingkungan Musium
	mi1.BuildAll(depthCubeMap, sizeOfLights);

	//Build Master Sword 1
	ms1.BuildAll();
	ms1.setPosition(masterPos);
	mi1.positionPedestal1(masterPos);

	//Build Buster Sword 1
	bs1.BuildAll();
	bs1.setPosition(busterPos);

	//Build LightSaber 1	
	ls1.BuildAll();
	ls1.setPosition(lightPos[1]);

	//Build Lampu Beda shader
	BuildLight();
	BuildLightSegitiga();

	//Build Person 1
	person1.BuildAll(shaderProgram, "knight_skin.png");
	person1.position(-2, 0, 23);

	//Build Person 2
	person2.BuildAll(shaderProgram, "knight_skin.png");
	person2.position(2, 0, 23);

	//Build Person 3
	person3.BuildAll(shaderProgram, "king_skin.png");
	person3.position(0, 0, 15);
	person3.changeRotationX(0);

	//Shader Config for Shadow
	UseShader(shader);
	glUniform1i(glGetUniformLocation(shader, "material.diffuse"), 0);
	glUniform1i(glGetUniformLocation(shader, "material.specular"), 1);
	//std::cout << lightConfig[6][0] << '\n';
	//std::cout << lightConfig[6][1];
}

void Demo::DeInit() {
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
	glDeleteBuffers(1, &EBO2);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Demo::ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	//CHANGE LAMPU WARNA

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		lc = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		lc = 1;
	}

	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		lc = 2;
	}

	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		lc = 3;
	}

	//Change Lightning in Tempat Pedang
	//PENCET ARROW KANAN
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && rightArrowKeyPressed) {
		if (lk > 6) {
			lk = 0;
		}
		else {
			lk++;
		}
		rightArrowKeyPressed = !rightArrowKeyPressed;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_RELEASE)
	{
		rightArrowKeyPressed = true;
	}

	//PENCET ARROW KIRI
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && leftArrowKeyPressed) {
		if (lk < 0) {
			lk = 6;
		}
		else {
			lk--;
		}
		leftArrowKeyPressed = !leftArrowKeyPressed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_RELEASE)
	{
		leftArrowKeyPressed = true;
	}

	//Camera Config
	// zoom camera
	// -----------
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		if (fovy < 90) {
			fovy += 0.0001f;
		}
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if (fovy > 0) {
			fovy -= 0.0001f;
		}
	}

	// update camera movement 
	// -------------
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		MoveCamera(CAMERA_SPEED);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		MoveCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		StrafeCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		StrafeCamera(CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !shadowsKeyPressed)
	{
		shadows = !shadows;
		shadowsKeyPressed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
	{
		shadowsKeyPressed = false;
	}

	// update camera speed
	
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		CAMERA_SPEED = 0.01f;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		CAMERA_SPEED = 0.005f;
	}

	// update camera rotation
	// ----------------------
	double mouseX, mouseY;
	double midX = screenWidth / 2;
	double midY = screenHeight / 2;
	float angleY = 0.0f;
	float angleZ = 0.0f;

	// Get mouse position
	glfwGetCursorPos(window, &mouseX, &mouseY);
	if ((mouseX == midX) && (mouseY == midY)) {
		return;
	}

	// Set mouse position
	glfwSetCursorPos(window, midX, midY);

	// Get the direction from the mouse cursor, set a resonable maneuvering speed
	angleY = (float)((midX - mouseX)) / 1000;
	angleZ = (float)((midY - mouseY)) / 1000;

	// The higher the value is the faster the camera looks around.
	viewCamY += angleZ * 2;

	// limit the rotation around the x-axis
	if ((viewCamY - posCamY) > 8) {
		viewCamY = posCamY + 8;
	}
	if ((viewCamY - posCamY) < -8) {
		viewCamY = posCamY - 8;
	}
	RotateCamera(-angleY);

}

void Demo::Update(double deltaTime) {
	//ms1.anglep += (float) ((deltaTime * 1.5f) / 1000);
	//ms1.moveX = -1.5;
	//std::cout << sizeOfLights;
	//zLight = 24.0f * cos(glfwGetTime()/2);
	//lightPos[2].z = 8.0 * cos(glfwGetTime());

	
	person3.position(0, 0, 30.0 * cos(glfwGetTime())/100);
}

void Demo::Render() {
	//Start
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 1.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	UseShader(shader);
	// point light 1 putih
	glUniform3f(glGetUniformLocation(shader, "pointLights[0].position"), lightPos[0].x, lightPos[0].y, lightPos[0].z);
	glUniform3f(glGetUniformLocation(shader, "pointLights[0].ambient"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(shader, "pointLights[0].diffuse"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(shader, "pointLights[0].specular"), 0.5f, 0.5f, 0.5f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[0].linear"), 0.14f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[0].quadratic"), 0.07f);
	// point light 2 Merah LightSaber
	glUniform3f(glGetUniformLocation(shader, "pointLights[1].position"), lightPos[1].x, lightPos[1].y, lightPos[1].z);
	glUniform3f(glGetUniformLocation(shader, "pointLights[1].ambient"), 0.5f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shader, "pointLights[1].diffuse"), 0.5f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shader, "pointLights[1].specular"), 0.5f, 0.0f, 0.0f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[1].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[1].linear"), 0.7f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[1].quadratic"), 1.8f);
	// point light 4 Kuning
	glUniform3f(glGetUniformLocation(shader, "pointLights[2].position"), lightPos[2].x, lightPos[2].y, lightPos[2].z);
	glUniform3f(glGetUniformLocation(shader, "pointLights[2].ambient"), 0.5f, 0.5f, 0.0f);
	glUniform3f(glGetUniformLocation(shader, "pointLights[2].diffuse"), 0.5f, 0.5f, 0.0f);
	glUniform3f(glGetUniformLocation(shader, "pointLights[2].specular"), 0.5f, 0.5f, 0.0f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[2].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[2].linear"), 0.7f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[2].quadratic"), 1.8f);
	// point light 1 putih Tempat Pedang
	glUniform3f(glGetUniformLocation(shader, "pointLights[3].position"), lightPos[3].x, lightPos[3].y, lightPos[3].z);
	glUniform3fv(glGetUniformLocation(shader, "pointLights[3].ambient"), 1, &lightColor[lc][0]);
	glUniform3fv(glGetUniformLocation(shader, "pointLights[3].diffuse"), 1, &lightColor[lc][0]);
	glUniform3fv(glGetUniformLocation(shader, "pointLights[3].specular"), 1, &lightColor[lc][0]);
	glUniform1f(glGetUniformLocation(shader, "pointLights[3].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shader, "pointLights[3].linear"), lightConfig[lk][0]);
	glUniform1f(glGetUniformLocation(shader, "pointLights[3].quadratic"), lightConfig[lk][1]);

	//LOOP

	float near_plane = 1.0f;
	float far_plane = 25.0f;
	glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), (float)SHADOW_WIDTH / (float)SHADOW_HEIGHT, near_plane, far_plane);

	for (unsigned int i = 0; i < sizeOfLights; ++i) {
		std::vector<glm::mat4> shadowTransforms;
		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos[i], lightPos[i] + glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos[i], lightPos[i] + glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos[i], lightPos[i] + glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos[i], lightPos[i] + glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)));
		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos[i], lightPos[i] + glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos[i], lightPos[i] + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));

		glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO[i]);
		glClear(GL_DEPTH_BUFFER_BIT);
		UseShader(simpleDepthShader);
		for (unsigned int x = 0; x < 6; ++x) {
			glUniformMatrix4fv(glGetUniformLocation(simpleDepthShader, ("shadowMatrices[" + std::to_string(x) + "]").c_str()), 1, GL_FALSE, glm::value_ptr(shadowTransforms[x]));
		}
		glUniform1f(glGetUniformLocation(simpleDepthShader, "far_plane"), far_plane);
		glUniform3f(glGetUniformLocation(simpleDepthShader, "lightPos"), lightPos[i].x, lightPos[i].y, lightPos[i].z);
		mi1.DrawAll(simpleDepthShader);
		ms1.DrawAll(simpleDepthShader);
		person1.DrawAll(simpleDepthShader);
		person2.DrawAll(simpleDepthShader);
		person3.DrawAll(simpleDepthShader);
		bs1.DrawAll(simpleDepthShader);
		ls1.DrawAll(simpleDepthShader);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

	}

	//-------------------------------------------------------------------------------//

	// 2. render scene as normal 
	// -------------------------
	glViewport(0, 0, screenWidth, screenHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	UseShader(shader);

	glm::mat4 projection = glm::perspective(45.0f, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, glm::value_ptr(view));
	// set lighting uniforms
	glUniform3f(glGetUniformLocation(shader, "viewPos"), posCamX, posCamY, posCamZ);
	glUniform1i(glGetUniformLocation(shader, "shadows"), shadows); // enable/disable shadows by pressing 'SPACE'
	glUniform1f(glGetUniformLocation(shader, "far_plane"), far_plane);

	for (unsigned int i = 1; i < 4; ++i)
	{
		glActiveTexture(GL_TEXTURE1 + i);
		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubeMap[i-1]);
		glUniform1i(glGetUniformLocation(shader, ("depthMap[" + std::to_string(i - 1) + "]").c_str()), i+1);
	}

	//Draw Lingkungan Museum
	mi1.DrawAll(shader);

	//Draw Pedang
	ms1.DrawAll(shader);
	bs1.DrawAll(shader);
	ls1.DrawAll(shader);

	//DrawPerson
	person1.DrawAll(shader);
	person2.DrawAll(shader);
	person3.DrawAll(shader);

	//FOR OBJEKT 
	//UNSUSED
	//UseShader(shaderProgram);

	//GLint view_pos = glGetUniformLocation(shaderProgram, "viewPos");
	//glUniform3f(view_pos, posCamX, posCamY, posCamZ);


	//// material properties
	//GLint material_shininess = glGetUniformLocation(shaderProgram, "material.shininess");
	//glUniform1f(material_shininess, 64.0f);

	////All Lights Present

	//// point light 1 Putih
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].position"), xLight, yLight, zLight);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].ambient"), 1.25f, 1.25f, 1.25f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].diffuse"), 1.25f, 1.25f, 1.25f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].specular"), 1.25f, 1.25f, 1.25f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].linear"), 0.35f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].quadratic"), 0.44f);
	//// point light 2 Merah
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].position"), 0.0f, 5.0f, -15.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].ambient"), 1.0f, 0.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].diffuse"), 1.0f, 0.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].specular"), 1.0f, 0.0f, 0.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[1].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[1].linear"), 0.22f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[1].quadratic"), 0.20f);
	//// point light 3 Ungu
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].position"), 0.0f, 5.0f, 5.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].ambient"), 1.0f, 0.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].diffuse"), 1.0f, 0.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].specular"), 1.0f, 0.0f, 1.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[2].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[2].linear"), 0.7f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[2].quadratic"), 1.8f);
	//// point light 4 Kuning
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].position"), 0.0f, 0.1f, -21.5f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].ambient"), 0.25f, 0.25f, 0.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].diffuse"), 0.25f, 0.25f, 0.0f);
	//glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].specular"), 0.75f, 0.75f, 0.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[3].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[3].linear"), 0.7f);
	//glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[3].quadratic"), 1.8f);
	//

	//// Pass perspective projection matrix
	//glm::mat4 projection = glm::perspective(fovy, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	//GLint projLoc = glGetUniformLocation(this->shaderProgram, "projection");
	//glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//// LookAt camera (position, target/direction, up)
	//glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	//GLint viewLoc = glGetUniformLocation(this->shaderProgram, "view");
	//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	////Draw OBJEKT using shaderProgram
	//DrawTexturedCube();
	////Draw Lingkungan Musium
	//
	//mi1.DrawAll();

	

	//FOR LAMP

	UseShader(lightShader);

	// Pass perspective projection matrix
	glm::mat4 projection2 = glm::perspective(fovy, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	GLint projLoc2 = glGetUniformLocation(this->lightShader, "projection");
	glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection2));

	//// LookAt camera (position, target/direction, up)
	glm::mat4 view2 = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	GLint viewLoc2 = glGetUniformLocation(this->lightShader, "view");
	glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view2));

	//|__________Draw Light Source using lightShader__________|\\
	 
	//Light 0 Putih Lampu Atas
	DrawLight(lightPos[0].x, lightPos[0].y, lightPos[0].z, 1.0, 1.0, 1.0);

	//Lampu 1 DrawLightSaber 
	ls1.DrawLight(lightShader);

	//Light 2 Segitiga Kuning
	DrawLightSegitiga(    0 + masterPos.x, (  -0.1 - 0.05) + masterPos.y, 0.15 + masterPos.z, 1.0, 1.0, 0.0);
	DrawLightSegitiga( 0.09 + masterPos.x, (-0.275 - 0.05) + masterPos.y, 0.15 + masterPos.z, 1.0, 1.0, 0.0);
	DrawLightSegitiga(-0.09 + masterPos.x, (-0.275 - 0.05) + masterPos.y, 0.15 + masterPos.z, 1.0, 1.0, 0.0);
	
	//Light 3
	DrawLight(lightPos[3].x, lightPos[3].y, lightPos[3].z, lightColor[lc].x, lightColor[lc].y, lightColor[lc].z);

	//___________________________________________________________
	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
}


int main(int argc, char** argv) {
	RenderEngine& app = Demo();
	app.Start("PROJEKT AKHIr", 1024, 576, true, false);
}

void Demo::InitCamera()
{
	posCamX = 0.0f;
	posCamY = 1.0f;
	posCamZ = 15.0f;
	viewCamX = 0.0f;
	viewCamY = 1.0f;
	viewCamZ = 0.0f;
	upCamX = 0.0f;
	upCamY = 1.0f;
	upCamZ = 0.0f;
	CAMERA_SPEED = 0.005f;
	fovy = 45.0f;
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Demo::MoveCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	// forward positive cameraspeed and backward negative -cameraspeed.
	posCamX = posCamX + x * speed;
	posCamZ = posCamZ + z * speed;
	viewCamX = viewCamX + x * speed;
	viewCamZ = viewCamZ + z * speed;
}

void Demo::StrafeCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	float orthoX = -z;
	float orthoZ = x;

	// left positive cameraspeed and right negative -cameraspeed.
	posCamX = posCamX + orthoX * speed;
	posCamZ = posCamZ + orthoZ * speed;
	viewCamX = viewCamX + orthoX * speed;
	viewCamZ = viewCamZ + orthoZ * speed;
}

void Demo::RotateCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	viewCamZ = (float)(posCamZ + glm::sin(speed) * x + glm::cos(speed) * z);
	viewCamX = (float)(posCamX + glm::cos(speed) * x - glm::sin(speed) * z);
}



