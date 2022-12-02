#include "Demo.h"



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

void Demo::DrawLight() {
	glUseProgram(lightShader);

	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized


	//set mat4 model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xLight, yLight, zLight));

	model = glm::rotate(model, 0.0f, glm::vec3(0, 1, 0));

	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

	GLint modelLoc = glGetUniformLocation(this->lightShader, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glBindVertexArray(lightVAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Demo::Init() {
	// build and compile our shader program
	// ------------------------------------
	//texturedShader = BuildShader("vertexShader.vert", "fragmentShader.frag", nullptr);
	shaderProgram = BuildShader("texturedShader.vert", "texturedShader.frag", nullptr);
	lightShader = BuildShader("lightShader.vert", "lightShader.frag", nullptr);
	
	BuildLight();

	//Build Lingkungan Musium
	mi1.BuildAll(shaderProgram);

	//Build Swords
	ms1.BuildCube(shaderProgram);
	bs1.BuildAll(shaderProgram);

	//Build Person 1
	person1.BuildAll(shaderProgram, "knight_skin.png");
	person1.position(-2,0,23);

	//Build Person 2
	person2.BuildAll(shaderProgram, "knight_skin.png");
	person2.position(2, 0, 23);

	//Build Person 3
	person3.BuildAll(shaderProgram, "knight_skin.png");
	person3.position(0, 0, 3);
	person3.changeRotationX(0);
	
	BuildTexturedCube();

	InitCamera();

	UseShader(shaderProgram);
	glUniform1i(glGetUniformLocation(shaderProgram, "material.diffuse"), 0);
	glUniform1i(glGetUniformLocation(shaderProgram, "material.specular"), 1);
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

	// update camera speed
	bool run = false;
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		if (run == false) {
			CAMERA_SPEED = 0.01f;
			run = true;
		}
		else if (run == true) {
			CAMERA_SPEED = 0.005f;
			run == false;
		}
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
	//std::cout << 2.0/4.0;
	//zLight = 24.0f * cos(glfwGetTime()/2);
}

void Demo::Render() {
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 1.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	//FOR OBJEKT 

	UseShader(shaderProgram);

	GLint view_pos = glGetUniformLocation(shaderProgram, "viewPos");
	glUniform3f(view_pos, posCamX, posCamY, posCamZ);


	// material properties
	GLint material_shininess = glGetUniformLocation(shaderProgram, "material.shininess");
	glUniform1f(material_shininess, 64.0f);

	// direction Light
	/*glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.direction"), 0.0f, -1.0f, -1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.ambient"), 0.1f, 0.1f, 0.1f);
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.diffuse"), 1.0f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.specular"), 0.1f, 0.1f, 0.1f);*/
	// point light 1
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].position"), xLight, yLight, zLight);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].ambient"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].linear"), 0.35f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].quadratic"), 0.44f);
	// point light 2
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].position"), 0.0f, 5.0f, -15.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].ambient"), 1.0f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].diffuse"), 1.0f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[1].specular"), 1.0f, 0.0f, 0.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[1].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[1].linear"), 0.22f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[1].quadratic"), 0.20f);
	// point light 3
	/*glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].position"), 2.0f, 3.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].ambient"), 0.0f, 0.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].diffuse"), 0.0f, 0.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[2].specular"), 0.0f, 0.0f, 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[2].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[2].linear"), 0.09f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[2].quadratic"), 0.032f);*/
	// point light 4
	/*glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].position"), 0.0f, 3.0f, 2.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].ambient"), 0.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].diffuse"), 0.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[3].specular"), 0.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[3].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[3].linear"), 0.09f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[3].quadratic"), 0.032f);*/
	// spotLight
	glUniform3fv(glGetUniformLocation(shaderProgram, "spotLight.position"), 1, &glm::vec3(posCamX, posCamY, posCamZ)[0]);
	glUniform3fv(glGetUniformLocation(shaderProgram, "spotLight.direction"), 1, &glm::vec3(viewCamX, viewCamY, viewCamZ)[0]);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLight.ambient"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLight.diffuse"), 0.1f, 0.1f, 0.1f);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLight.specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLight.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLight.linear"), 0.09f);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLight.quadratic"), 0.032f);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLight.cutOff"), glm::cos(glm::radians(12.5f)));
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLight.outerCutOff"), glm::cos(glm::radians(17.6f)));

	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(fovy, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(this->shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// LookAt camera (position, target/direction, up)
	glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	GLint viewLoc = glGetUniformLocation(this->shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	//Draw OBJEKT using shaderProgram	
	//Draw Lingkungan Musium
	DrawTexturedCube();
	mi1.DrawAll();

	//Draw Pedang
	ms1.DrawAll();
	bs1.DrawAll();

	//DrawPerson
	person1.DrawAll();
	person2.DrawAll();
	person3.DrawAll();

	//FOR LAMP

	UseShader(lightShader);

	// Pass perspective projection matrix
	glm::mat4 projection2 = glm::perspective(fovy, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	GLint projLoc2 = glGetUniformLocation(this->lightShader, "projection");
	glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection2));

	// LookAt camera (position, target/direction, up)
	glm::mat4 view2 = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	GLint viewLoc2 = glGetUniformLocation(this->lightShader, "view");
	glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view2));

	//Draw OBJEKT using lightShader
	DrawLight();

	

	glDisable(GL_DEPTH_TEST);
}


int main(int argc, char** argv) {
	RenderEngine& app = Demo();
	app.Start("Transformation: Transform Cube", 1024, 576, true, false);
}

void Demo::InitCamera()
{
	posCamX = 0.0f;
	posCamY = 1.0f;
	posCamZ = 8.0f;
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

void Demo::BuildTexturedCube()
{
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &cube_texture);
	glBindTexture(GL_TEXTURE_2D, cube_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("container.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenTextures(1, &stexture);
	glBindTexture(GL_TEXTURE_2D, stexture);
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

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glGenBuffers(1, &cubeEBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(cubeVAO);

	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
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

void Demo::DrawTexturedCube()
{
	glUseProgram(shaderProgram);

	// bind diffuse map
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, cube_texture);

	//bind specular map
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, stexture);

	glBindVertexArray(cubeVAO);

	//set mat4 model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0, 0.6, 0));

	model = glm::rotate(model, angle, glm::vec3(0, 0, 1));

	model = glm::scale(model, glm::vec3(1, 1, 1));

	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}


