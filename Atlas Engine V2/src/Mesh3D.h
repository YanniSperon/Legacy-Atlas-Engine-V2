#pragma once

#include "glew.h"
#include "Vertex3D.h"

namespace Atlas {

	struct Mesh3D {

		Mesh3D()
			: vertices(NULL), numVertices(0), indices(NULL), numIndices(0)
		{

		}

		Vertex3D* vertices;
		GLuint numVertices;
		GLuint* indices;
		GLuint numIndices;

		GLsizeiptr VertexBufferSize() const {
			return numVertices * sizeof(Vertex3D);
		}

		GLsizeiptr IndexBufferSize() const {
			return numIndices * sizeof(GLuint);
		}

		void DeleteMesh() {
			delete[] vertices;
			delete[] indices;
			numVertices = numIndices = 0;
		}
	};
}