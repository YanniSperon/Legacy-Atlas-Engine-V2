#pragma once

#include <deque>
#include "Renderable3D.h"
#include "Renderable2D.h"
#include "RenderableText.h""
#include "Camera.h"

namespace Atlas {
	class Renderer {
	private:
		std::deque<Renderable3D> renderQueue3D;
		std::deque<Renderable2D> renderQueue2D;
		std::deque<RenderableText> renderQueueText;
	public:
		Renderer();
		~Renderer();

		void AddRenderable3D(const Renderable3D& renderable);
		void AddRenderable2D(const Renderable2D& renderable);
		void AddRenderableText(const RenderableText& renderable);

		void Flush(Camera* cam);
	};
}