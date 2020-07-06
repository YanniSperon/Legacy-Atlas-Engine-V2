#include "MeshGenerator.h"

Atlas::Mesh3D Atlas::MeshGenerator::CreateCube(const glm::vec3& min, const glm::vec3& max)
{
	Mesh3D cube;

	Vertex3D positions[] = {
		glm::vec3(min.x, min.y, min.z), // 0
		glm::vec2(+0.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, -1.0f),   // normal

		glm::vec3(max.x, min.y, min.z), // 1
		glm::vec2(+1.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, -1.0f),   // normal

		glm::vec3(max.x, max.y, min.z), // 2
		glm::vec2(+1.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, -1.0f),   // normal

		glm::vec3(min.x, max.y, min.z), // 3
		glm::vec2(+0.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, -1.0f),   // normal



		glm::vec3(max.x, min.y, min.z), // 4
		glm::vec2(+0.0f, +0.0f),        // texCoord
		glm::vec3(1.0f, 0.0f, 0.0f),    // normal

		glm::vec3(max.x, min.y, max.z), // 5
		glm::vec2(+1.0f, +0.0f),        // texCoord
		glm::vec3(1.0f, 0.0f, 0.0f),    // normal

		glm::vec3(max.x, max.y, max.z), // 6
		glm::vec2(+1.0f, +1.0f),        // texCoord
		glm::vec3(1.0f, 0.0f, 0.0f),    // normal

		glm::vec3(max.x, max.y, min.z), // 7
		glm::vec2(+0.0f, +1.0f),        // texCoord
		glm::vec3(1.0f, 0.0f, 0.0f),    // normal



		glm::vec3(min.x, max.y, min.z), // 8
		glm::vec2(+0.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, 1.0f, 0.0f),    // normal

		glm::vec3(max.x, max.y, min.z), // 9
		glm::vec2(+1.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, 1.0f, 0.0f),    // normal

		glm::vec3(max.x, max.y, max.z), // 10
		glm::vec2(+1.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, 1.0f, 0.0f),    // normal

		glm::vec3(min.x, max.y, max.z), // 11
		glm::vec2(+0.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, 1.0f, 0.0f),    // normal



		glm::vec3(max.x, min.y, max.z), // 12
		glm::vec2(+0.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, 1.0f),    // normal

		glm::vec3(min.x, min.y, max.z), // 13
		glm::vec2(+1.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, 1.0f),    // normal

		glm::vec3(min.x, max.y, max.z), // 14
		glm::vec2(+1.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, 1.0f),    // normal

		glm::vec3(max.x, max.y, max.z), // 15
		glm::vec2(+0.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, 0.0f, 1.0f),    // normal



		glm::vec3(min.x, min.y, max.z), // 16
		glm::vec2(+0.0f, +0.0f),        // texCoord
		glm::vec3(-1.0f, 0.0f, 0.0f),   // normal

		glm::vec3(min.x, min.y, min.z), // 17
		glm::vec2(+1.0f, +0.0f),        // texCoord
		glm::vec3(-1.0f, 0.0f, 0.0f),   // normal

		glm::vec3(min.x, max.y, min.z), // 18
		glm::vec2(+1.0f, +1.0f),        // texCoord
		glm::vec3(-1.0f, 0.0f, 0.0f),   // normal

		glm::vec3(min.x, max.y, max.z), // 19
		glm::vec2(+0.0f, +1.0f),        // texCoord
		glm::vec3(-1.0f, 0.0f, 0.0f),   // normal



		glm::vec3(min.x, min.y, max.z), // 20
		glm::vec2(+0.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, -1.0f, 0.0f),   // normal

		glm::vec3(max.x, min.y, max.z), // 21
		glm::vec2(+1.0f, +0.0f),        // texCoord
		glm::vec3(0.0f, -1.0f, 0.0f),   // normal

		glm::vec3(max.x, min.y, min.z), // 22
		glm::vec2(+1.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, -1.0f, 0.0f),   // normal

		glm::vec3(min.x, min.y, min.z), // 23
		glm::vec2(+0.0f, +1.0f),        // texCoord
		glm::vec3(0.0f, -1.0f, 0.0f)    // normal
	};

	cube.numVertices = NUM_ARRAY_ELEMENTS(positions);
	cube.vertices = new Vertex3D[cube.numVertices];
	memcpy(cube.vertices, positions, sizeof(positions));

	GLuint indices[] = {
		2, 1, 0, // Front face
		3, 2, 0,

		6, 5, 4, // Right face
		7, 6, 4,

		10, 9, 8, // Top face
		11, 10, 8,

		14, 13, 12, // Back face
		15, 14, 12,

		18, 17, 16, // Left face
		19, 18, 16,

		20, 23, 22, // Bottom face
		21, 20, 22
	};
	cube.numIndices = NUM_ARRAY_ELEMENTS(indices);
	cube.indices = new GLuint[cube.numIndices];
	memcpy(cube.indices, indices, sizeof(indices));

	return cube;
}
