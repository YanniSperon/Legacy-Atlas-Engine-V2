#pragma once

#include <deque>
#include "Renderable3D.h"

namespace Atlas {
	class Renderer {
	private:
		std::deque<Renderable3D*> renderQueue3D;
		std::deque<Renderable2D*> renderQueue2D;
		std::deque<RenderableText*> renderQueueText;
	public:
		Renderer();
		~Renderer();

		void Flush();
	};
}