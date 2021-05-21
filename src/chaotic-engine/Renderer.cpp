#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Screen.h"
#include "Camera.h"

#include <iostream>

namespace engine
{
	void Renderer::onInitialize()
	{
		const char* src =
			"\n#ifdef VERTEX\n															" \
			"attribute vec2 a_Position;													" \
			"uniform mat4 u_Projection;													" \
			"uniform mat4 u_View;														" \
			"uniform mat4 u_Model;														" \
			"void main()																" \
			"{																			" \
			" gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 0, 1);	" \
			"}																			" \
			"\n#endif\n																	" \
			"\n#ifdef FRAGMENT\n														" \
			"uniform vec4 u_Color;														" \
			"void main()																" \
			"{																			" \
			" gl_FragColor = u_Color;													" \
			"}																			" \
			"\n#endif\n																	";		shader = getCore()->context->createShader();		shader->parse(src);		color = rend::vec4(1.0f, 0.0f, 1.0f, 1.0f);

		shape = getCore()->context->createBuffer();

		/*shape->add(rend::vec2(0.0f, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));*/

		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, 0.5f));
		shape->add(rend::vec2(-0.5f, 0.5f));
		shape->add(rend::vec2(0.5f, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));

		/*texCoord->add(rend::vec2(0.0f, 0.0f));
		texCoord->add(rend::vec2(1.0f, 1.0f));
		texCoord->add(rend::vec2(0.0f, 1.0f));
		texCoord->add(rend::vec2(1.0f, 1.0f));
		texCoord->add(rend::vec2(0.0f, 0.0f));
		texCoord->add(rend::vec2(1.0f, 0.0f));*/
	}

	void Renderer::setColor(rend::vec4 color)
	{
		this->color = color;
	}

	void Renderer::onRender()
	{
		shader->setAttribute("a_Position", shape);
		shader->setUniform("u_Model", getTransform()->getModel());
		shader->setUniform("u_Projection", getScreen()->getPerspective());
		shader->setUniform("u_Color", color);
		//shader->setUniform("u_View", rend::inverse(getCore()->getCamera()->getTransform()->getModel()));
		shader->setUniform("u_View", rend::inverse(getCore()->getCurrentCamera()->getTransform()->getModel()));
		
		shader->render();
	}
}