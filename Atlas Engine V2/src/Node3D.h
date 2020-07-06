#pragma once

#include <vector>
#include "Camera.h"
#include "Light.h"
#include "Object3D.h"

namespace Atlas {
	class Node3D {
	private:
		Node3D* parent;
		std::vector<Node3D*> children;
		glm::vec3 translation;
		Camera* cameraComponent;
		Light* lightComponent;
		Object3D* objectComponent;
	public:
		Node3D();
		~Node3D();
		// an individual node may contain a camera, a light, an object (physics body/mesh), and an infinite number of children nodes
		
		void Update(float deltaTime);
		
		void AddChildNode(Node3D* newChild);

		void RemoveAndDeleteChildNode(Node3D* child);



		void SetParent(Node3D* newParent);

		Node3D* GetParentNode();
		std::vector<Node3D*> GetChildren();
		Object3D* GetObjectComponent();
		Light* GetLightComponent();
		Camera* GetCameraComponent();
	};
}