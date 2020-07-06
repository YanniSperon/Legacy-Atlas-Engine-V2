#include "Camera.h"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"'
#include "Global.h"

Atlas::Camera::Camera()
	: forwardDirection(0.0f, 0.0f, -1.0f), upDirection(0.0f, 1.0f, 0.0f), translation(0.0f), nearPlane(0.1f), farPlane(100.0f), width(Global::Variables.screenWidth), height(Global::Variables.screenHeight), FOV(90.0f)
{

}

Atlas::Camera::~Camera()
{

}

glm::mat4 Atlas::Camera::GetViewMatrix()
{
	/*printf("  Getting view data:\n    Translation: (");
	printf(std::to_string(translation.x).c_str());
	printf(", ");
	printf(std::to_string(translation.y).c_str());
	printf(", ");
	printf(std::to_string(translation.z).c_str());
	printf(")\n    Forward Direction: (");
	printf(std::to_string(forwardDirection.x).c_str());
	printf(", ");
	printf(std::to_string(forwardDirection.y).c_str());
	printf(", ");
	printf(std::to_string(forwardDirection.z).c_str());
	printf(")\n    UpDirection: (");
	printf(std::to_string(upDirection.x).c_str());
	printf(", ");
	printf(std::to_string(upDirection.y).c_str());
	printf(", ");
	printf(std::to_string(upDirection.z).c_str());
	printf("\n");*/
	return glm::lookAt(translation, translation + forwardDirection, upDirection);
}

glm::mat4 Atlas::Camera::GetProjMatrix()
{
	/*printf("  Getting proj data:\n    FOV: (");
	printf(std::to_string(FOV).c_str());
	printf(")\n    Dimensions: (");
	printf(std::to_string(width).c_str());
	printf(", ");
	printf(std::to_string(height).c_str());	
	printf(")\n    NearPlane: (");
	printf(std::to_string(nearPlane).c_str());
	printf(")\n    FarPlane: (");
	printf(std::to_string(farPlane).c_str());
	printf("\n");*/
	return glm::perspective(glm::radians(FOV), ((float)width) / ((float)height), nearPlane, farPlane);
}

void Atlas::Camera::LookAt(glm::vec3 position)
{
	glm::vec3 resultingDirection = position - translation;
	forwardDirection = glm::normalize(resultingDirection);
}

void Atlas::Camera::LookAtMouse(double xpos, double ypos)
{
	static double oldMouseX = 0.0;
	static double oldMouseY = 0.0;
	glm::vec2 mouseDelta(xpos - oldMouseX, ypos - oldMouseY);

	glm::vec3 toRotateAround = glm::cross(forwardDirection, upDirection);
	glm::vec3 vd;
	forwardDirection = glm::mat3(
		glm::rotate(glm::mat4(1.0f), -glm::radians(mouseDelta.x * 0.2f), upDirection) *
		glm::rotate(glm::mat4(1.0f), -glm::radians(mouseDelta.y * 0.2f), toRotateAround)
	) * forwardDirection;

	forwardDirection = glm::mat3() * forwardDirection;

	oldMouseX = xpos;
	oldMouseY = ypos;
}

void Atlas::Camera::MoveForward(float deltaTime)
{
	translation += glm::vec3(0.0f, 0.0f, -5.0f * deltaTime);
}

void Atlas::Camera::MoveBackward(float deltaTime)
{
	translation += glm::vec3(0.0f, 0.0f, 5.0f * deltaTime);
}

void Atlas::Camera::StrafeLeft(float deltaTime)
{
}

void Atlas::Camera::StrafeRight(float deltaTime)
{
}

void Atlas::Camera::MoveUp(float deltaTime)
{
}

void Atlas::Camera::MoveDown(float deltaTime)
{
}

glm::vec3 Atlas::Camera::GetTranslation()
{
	return translation;
}

glm::vec3 Atlas::Camera::GetForwardDirection()
{
	return forwardDirection;
}

void Atlas::Camera::SetTranslation(glm::vec3 newTranslation)
{
	translation = newTranslation;
}

void Atlas::Camera::Update(float deltaTime)
{

}
