#include "Node.h"

Atlas::Node::Node()
{
	parent = NULL;
	children = std::vector<Node*>();
	translation = glm::vec3(0.0f);
	cameraComponent = nullptr;
	lightComponent = nullptr;
	objectComponent = nullptr;
}

Atlas::Node::~Node()
{
	for (int i = 0; i < children.size(); i++) {
		delete children.at(i);
	}
	children.clear();
	delete cameraComponent;
	delete lightComponent;
	delete objectComponent;
}

void Atlas::Node::AddChildNode(Node* newChild)
{
	children.push_back(newChild);
	newChild->SetParent(this);
}

void Atlas::Node::RemoveAndDeleteChildNode(Node* child)
{
	for (int i = 0; i < children.size(); i++) {
		if (child == children.at(i)) {
			delete child;
			children.erase(children.begin() + i);
			break;
		}
	}
}

void Atlas::Node::SetParent(Node* newParent)
{
	parent = newParent;
}

std::vector<Atlas::Node*> Atlas::Node::GetChildren()
{
	return std::vector<Node*>();
}