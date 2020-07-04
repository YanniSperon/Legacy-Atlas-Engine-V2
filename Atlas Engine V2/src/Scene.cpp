#include "Scene.h"

Atlas::Scene::Scene()
{
	rootNode = new Node();
}

Atlas::Scene::~Scene()
{
	delete rootNode;
}

void Atlas::Scene::AddNode(Node* node)
{
	rootNode->AddChildNode(node);
}

void Atlas::Scene::PrintLocations()
{
	for (int i = 0; i < rootNode->GetChildren().size(); i++) {
		// recursively go through and add all the objects to the rendering scene with final offsets of the sum of the node translations
	}
}
