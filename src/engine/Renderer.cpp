#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
#include <iostream>

namespace engine
{
	void Renderer::onInitialize()
	{
		const char* src =
			"\n#ifdef VERTEX\n						" \
			"attribute vec2 a_Position;				" \
			/*"uniform mat4 u_Projection;				" \*/
			"uniform mat4 u_Model;					" \
			"										" \
			"void main()							" \
			"{										" \
			" gl_Position = u_Model * vec4(a_Position, 0, 1); " \
			"}										" \
			"										" \
			"\n#endif\n								" \
			"\n#ifdef FRAGMENT\n					" \
			"uniform vec4 u_Color;                  " \
			"										" \
			"void main()							" \
			"{										" \
			" gl_FragColor = u_Color;		        " \
			"}										" \
			"										" \
			"\n#endif\n								";		shader = getCore()->context->createShader();		shader->parse(src);		shape = getCore()->context->createBuffer();		color = rend::vec4(1, 0, 0, 1);		//color = getCore()->context->createBuffer();		// triangle		/*shape->add(rend::vec2(0, 0.5f));		shape->add(rend::vec2(-0.5f, -0.5f));		shape->add(rend::vec2(0.5f, -0.5f));*/

		// rectangle
		shape->add(rend::vec2(-0.5f, 0.5f));		shape->add(rend::vec2(0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, 0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));		shape->add(rend::vec2(-0.5f, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
	}

	void Renderer::setColor(rend::vec4 color)
	{
		this->color = color;
	}

	void Renderer::onRender()
	{
		//add set shape? set colour?

		//shader->setAttribute("a_color", color);
		shader->setAttribute("a_Position", shape);
		/*shader->setUniform("u_Projection", rend::perspective(rend::radians(45.0f),
			1.0f, 0.1f, 100.0f));*/
		shader->setUniform("u_Model", getEntity()->getTransform()->getModel());
		shader->setUniform("u_Color", color);

		shader->render();
	}
}