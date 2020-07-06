#pragma once

#include <vector>
#include "Node3D.h"
#include "glm.hpp"

namespace Atlas {
	class Scene {
	private:
		Node3D* rootNode;
		bool isPaused;
		glm::vec3 backgroundColor; // Replace this with a material and render a quad with the material
	public:
		Scene();
		~Scene();

		void Update(float deltaTime);
		Node3D* GetRootNode();
		void AddNode(Node3D* object);
		void PrintLocations();
	};
}