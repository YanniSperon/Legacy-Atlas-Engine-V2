#pragma once

#include <vector>
#include "Node.h"
#include "glm.hpp"

namespace Atlas {
	class Scene {
	private:
		Node* rootNode;
		bool isPaused;
		glm::vec3 backgroundColor; // Replace this with a material and render a quad with the material
	public:
		Scene();
		~Scene();

		void AddNode(Node* object);
		void PrintLocations();
	};
}