#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

Atlas::Camera::Camera()
	: forwardDirection(0.0f, 0.0f, -1.0f), upDirection(0.0f, 1.0f, 0.0f), translation(0.0f)
{

}

Atlas::Camera::~Camera()
{

}

glm::mat4 Atlas::Camera::GetViewTransformMatrix()
{
	return glm::lookAt(translation, translation + forwardDirection, upDirection);
}
