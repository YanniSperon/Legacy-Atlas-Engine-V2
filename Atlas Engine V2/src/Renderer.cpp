#include "Renderer.h"

Atlas::Renderer::Renderer()
{
	renderQueue3D = std::deque<Renderable3D>();
	renderQueue2D = std::deque<Renderable2D>();
	renderQueueText = std::deque<RenderableText>();
}

Atlas::Renderer::~Renderer()
{
	while (!renderQueue3D.empty()) {
		renderQueue3D.pop_front();
	}
	while (!renderQueue2D.empty()) {
		renderQueue2D.pop_front();
	}
	while (!renderQueueText.empty()) {
		renderQueueText.pop_front();
	}
}

void Atlas::Renderer::AddRenderable3D(const Renderable3D& renderable)
{
	renderQueue3D.push_back(renderable);
}

void Atlas::Renderer::AddRenderable2D(const Renderable2D& renderable)
{
	renderQueue2D.push_back(renderable);
}

void Atlas::Renderer::AddRenderableText(const RenderableText& renderable)
{
	renderQueueText.push_back(renderable);
}

void Atlas::Renderer::Flush(Camera* cam)
{
	while (!renderQueue3D.empty()) {
		//printf("Rendering queued object\n");
		Renderable3D tempRenderable = renderQueue3D.front();
		tempRenderable.GetObject()->Draw(tempRenderable.GetTransformMatrix(), cam->GetViewMatrix(), cam->GetProjMatrix());
		renderQueue3D.pop_front();
	}
}
