#include "Object3D.h"

Atlas::Object3D::Object3D()
	: ibo(0), vbo(0), mesh(), translation(0.0f), rotation(0.0f), scale(1.0f), texture(NULL)
{

}

Atlas::Object3D::Object3D(Mesh3D objectMesh, Shader* shdr, Texture* tex)
	: ibo(0), vbo(0), mesh(objectMesh), translation(0.0f), rotation(0.0f), scale(1.0f), shader(shdr), texture(tex)
{

}

Atlas::Object3D::~Object3D()
{
	// check cache and see if it is being used anywhere and if it isnt then delete the mesh
}

void Atlas::Object3D::LoadIntoVRAM()
{
	printf("Loading into vram\n");
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mesh.VertexBufferSize(), mesh.vertices, GL_STATIC_DRAW);
	/*printf("Vertices: [\n");
	for (int i = 0; i < mesh.numVertices; i++) {
		printf("(");
		printf(std::to_string(mesh.vertices[i].position.x).c_str());
		printf(", ");
		printf(std::to_string(mesh.vertices[i].position.y).c_str());
		printf(", ");
		printf(std::to_string(mesh.vertices[i].position.z).c_str());
		printf(")\n");
	}
	printf("]\n");*/


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 5));



	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.IndexBufferSize(), mesh.indices, GL_STATIC_DRAW);



	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glFinish();
}

void Atlas::Object3D::UnloadFromVRAM()
{
	printf("Unloading from VRAM");
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void Atlas::Object3D::Draw(glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	Bind();
	shader->SetUniformMat4f("P", projection);
	shader->SetUniformMat4f("V", view);
	shader->SetUniformMat4f("M", model);
	glDrawElements(GL_TRIANGLES, mesh.numIndices, GL_UNSIGNED_INT, 0);
}

void Atlas::Object3D::Bind()
{
	shader->Bind();
	texture->Bind();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 5));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}

void Atlas::Object3D::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Atlas::Object3D::Update(float deltaTime)
{

}
