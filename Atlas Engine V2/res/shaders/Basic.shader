#shader vertex
#version 330 core

in layout(location = 0) vec3 position;

void main()
{
	gl_Position = vec4(position, 1.0);
}

#shader fragment
#version 330 core

out vec4 color;

void main()
{
	color = vec4(1.0, 1.0, 1.0, 1.0);
}