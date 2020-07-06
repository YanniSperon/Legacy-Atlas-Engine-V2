#pragma once

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a);
#include "glm.hpp"
#include "Mesh3D.h"

namespace Atlas {
	class MeshGenerator {
	public:
		static Mesh3D CreateCube(const glm::vec3& min, const glm::vec3& max);
	};
}