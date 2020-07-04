#pragma once

#include "glm.hpp"

namespace Atlas {
	class Camera {
	private:
		// include forward vector, up vector, etc
		glm::vec3 forwardDirection;
		glm::vec3 upDirection;
		glm::vec3 translation;
	public:
		Camera();
		~Camera();

		glm::mat4 GetViewTransformMatrix();
		void LookAt();
		void MoveForward(float deltaTime);
		void MoveBackward(float deltaTime);
		void StrafeLeft(float deltaTime);
		void StrafeRight(float deltaTime);
		void MoveUp(float deltaTime);
		void MoveDown(float deltaTime);

		glm::vec3 GetTranslation();
		void SetTranslation(glm::vec3 newTranslation);
	};
}