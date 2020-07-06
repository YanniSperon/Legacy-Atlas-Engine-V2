#include "Renderable3D.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/quaternion.hpp"

Atlas::Renderable3D::Renderable3D(Object3D* object)
	: objectBeingRendered(object), finalTranslation(0.0f), finalRotation(0.0f), finalScale(1.0f)
{

}

Atlas::Renderable3D::~Renderable3D()
{

}

Atlas::Object3D* Atlas::Renderable3D::GetObject()
{
	return objectBeingRendered;
}

glm::mat4 Atlas::Renderable3D::GetTransformMatrix()
{
	/*rintf("  Getting transform data:\n    Translation: (");
	printf(std::to_string(finalTranslation.x).c_str());
	printf(", ");
	printf(std::to_string(finalTranslation.y).c_str());
	printf(", ");
	printf(std::to_string(finalTranslation.z).c_str());
	printf(")\n    Rotation: (");
	printf(std::to_string(finalRotation.x).c_str());
	printf(", ");
	printf(std::to_string(finalRotation.y).c_str());
	printf(", ");
	printf(std::to_string(finalRotation.z).c_str());
	printf(")\n    Scale: (");
	printf(std::to_string(finalScale.x).c_str());
	printf(", ");
	printf(std::to_string(finalScale.y).c_str());
	printf(", ");
	printf(std::to_string(finalScale.z).c_str());
	printf("\n");*/
	return (glm::translate(glm::mat4(), finalTranslation) * glm::yawPitchRoll(glm::radians(finalRotation.x), glm::radians(finalRotation.y), glm::radians(finalRotation.z)) * glm::scale(glm::mat4(), finalScale));
}
