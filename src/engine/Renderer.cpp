#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>

namespace engine
{
	///<summary>
	/// Initializes vertex shader and fragment shader for a rectangle.
	///</summary>
	void Renderer::onInitialize()
	{
<<<<<<< HEAD
		// Vertex shader and fragment shader.
		const char* src =
			"\n#ifdef VERTEX\n									" \
			"attribute vec2 a_Position;							" \
			/*"uniform mat4 u_Projection;						" \*/
			"uniform mat4 u_Model;								" \
			"													" \
			"void main()										" \
			"{													" \
			" gl_Position = u_Model * vec4(a_Position, 0, 1);	" \
			"}													" \
			"													" \
			"\n#endif\n											" \
			"\n#ifdef FRAGMENT\n								" \
			"uniform vec4 u_Color;							    " \
			"													" \
			"void main()										" \
			"{													" \
			" gl_FragColor = u_Color;						    " \
			"}													" \
			"													" \
			"\n#endif\n											";		shader = getCore()->context->createShader();		shader->parse(src);		shape = getCore()->context->createBuffer();		color = rend::vec4(1, 0, 0, 1);
=======
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
			"\n#endif\n								";		shader = getCore()->context->createShader();		shader->parse(src);		shape = getCore()->context->createBuffer();		color = rend::vec4(1, 0, 0, 1);
>>>>>>> 7cf6edf6ec6392d1292fe67401ea0a278e9bb5a6
		shape->add(rend::vec2(-0.5f, 0.5f));		shape->add(rend::vec2(0.5f, -0.5f));
		shape->add(rend::vec2(0.5f, 0.5f));
		shape->add(rend::vec2(0.5f, -0.5f));		shape->add(rend::vec2(-0.5f, 0.5f));
		shape->add(rend::vec2(-0.5f, -0.5f));
	}

	///<summary>
	/// Sets the color of the rectangle.
	///</summary>
	void Renderer::setColor(rend::vec4 color)
	{
		this->color = color;
	}

	///<summary>
	/// Renders a rectangle to the window.
	///</summary>
	void Renderer::onRender()
	{
<<<<<<< HEAD
=======
		//shader->setAttribute("a_color", color);
>>>>>>> 7cf6edf6ec6392d1292fe67401ea0a278e9bb5a6
		shader->setAttribute("a_Position", shape);
		/*shader->setUniform("u_Projection", rend::perspective(rend::radians(45.0f),
			1.0f, 0.1f, 100.0f));*/
		shader->setUniform("u_Model", getEntity()->getTransform()->getModel());
		shader->setUniform("u_Color", color);

		shader->render();
	}
}