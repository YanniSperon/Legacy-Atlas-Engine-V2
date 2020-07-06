#pragma once

#include "glew.h"

namespace Atlas {
	class Texture {
	private:
		GLuint textureID;
	public:
		Texture();
		~Texture();

		void Bind();
		void Unbind();
	};
}