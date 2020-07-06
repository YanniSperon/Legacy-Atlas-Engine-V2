#include "Node3D.h"

Atlas::Node3D::Node3D()
{
	parent = NULL;
	children = std::vector<Node3D*>();
	translation = glm::vec3(0.0f);
	cameraComponent = nullptr;
	lightComponent = nullptr;
	objectComponent = nullptr;
}

Atlas::Node3D::~Node3D()
{
	for (int i = 0; i < children.size(); i++) {
		delete children.at(i);
	}
	children.clear();
	delete cameraComponent;
	delete lightComponent;
	delete objectComponent;
}

void Atlas::Node3D::Update(float deltaTime)
{
	for (int i = 0; i < children.size(); i++) {
		children.at(i)->Update(deltaTime);
	}
	cameraComponent->Update(deltaTime);
	lightComponent->Update(deltaTime);
	objectComponent->Update(deltaTime);
}

void Atlas::Node3D::AddChildNode(Node3D* newChild)
{
	children.push_back(newChild);
	newChild->SetParent(this);
}

void Atlas::Node3D::RemoveAndDeleteChildNode(Node3D* child)
{
	for (int i = 0; i < children.size(); i++) {
		if (child == children.at(i)) {
			delete child;
			children.erase(children.begin() + i);
			break;
		}
	}
}

void Atlas::Node3D::SetParent(Node3D* newParent)
{
	parent = newParent;
}

Atlas::Node3D* Atlas::Node3D::GetParentNode()
{
	return parent;
}

std::vector<Atlas::Node3D*> Atlas::Node3D::GetChildren()
{
	return children;
}

Atlas::Object3D* Atlas::Node3D::GetObjectComponent()
{
	return objectComponent;
}

Atlas::Light* Atlas::Node3D::GetLightComponent()
{
	return lightComponent;
}

Atlas::Camera* Atlas::Node3D::GetCameraComponent()
{
	return cameraComponent;
}
