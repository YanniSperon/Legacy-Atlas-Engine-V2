#pragma once

#include <vector>
#include "Camera.h"
#include "Light.h"
#include "Object.h"

namespace Atlas {
	class Node {
	private:
		Node* parent;
		std::vector<Node*> children;
		glm::vec3 translation;
		Camera* cameraComponent;
		Light* lightComponent;
		Object* objectComponent;
	public:
		Node();
		~Node();
		// an individual node may contain a camera, a light, an object (physics body/mesh), and an infinite number of children nodes
		void AddChildNode(Node* newChild);
		void RemoveAndDeleteChildNode(Node* child);
		void SetParent(Node* newParent);
		std::vector<Node*> GetChildren();
	};
}