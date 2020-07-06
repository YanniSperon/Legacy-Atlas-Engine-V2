#pragma once

#include "glm.hpp"

namespace Atlas {
	class Camera {
	private:
		// include forward vector, up vector, etc
		glm::vec3 forwardDirection;
		glm::vec3 upDirection;
		glm::vec3 translation;
		float FOV;
		float nearPlane;
		float farPlane;
		int height;
		int width;
	public:
		Camera();
		~Camera();

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjMatrix();
		void LookAt(glm::vec3 position);
		void LookAtMouse(double xpos, double ypos);
		void MoveForward(float deltaTime);
		void MoveBackward(float deltaTime);
		void StrafeLeft(float deltaTime);
		void StrafeRight(float deltaTime);
		void MoveUp(float deltaTime);
		void MoveDown(float deltaTime);

		glm::vec3 GetTranslation();
		glm::vec3 GetForwardDirection();

		void SetTranslation(glm::vec3 newTranslation);

		void Update(float deltaTime);
	};
}