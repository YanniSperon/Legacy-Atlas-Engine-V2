#pragma once

#include "glew.h"
#include "Mesh3D.h"
#include "Shader.h"
#include "Texture.h"

namespace Atlas {
	class Object3D {
	private:
		GLuint vbo;
		GLuint ibo;
		Shader* shader;
		Texture* texture;
		Mesh3D mesh;
		glm::vec3 translation;
		glm::vec3 rotation;
		glm::vec3 scale;
	public:
		Object3D();
		Object3D(Mesh3D objectMesh, Shader* shdr, Texture* tex);
		~Object3D();

		void LoadIntoVRAM();
		void UnloadFromVRAM();

		void Draw(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
		void Bind();
		void Unbind();
		

		void Update(float deltaTime);
		// this will contain a mesh, a physics body and much more customizable information such as
		// texture, shader, etc
	};
}