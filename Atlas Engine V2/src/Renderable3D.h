#pragma once

#include "Object3D.h"
#include "glm.hpp"

namespace Atlas {
	class Renderable3D {
	private:
		Object3D* objectBeingRendered;

		glm::vec3 finalTranslation;
		glm::vec3 finalRotation;
		glm::vec3 finalScale;
	public:
		Renderable3D(Object3D* object);
		~Renderable3D();

		Object3D* GetObject();
		glm::mat4 GetTransformMatrix();
		// this is going to include the same information as an object, except it will also include a
		// reference to the scene it is coming from which includes lights, camera, etc
	};
}