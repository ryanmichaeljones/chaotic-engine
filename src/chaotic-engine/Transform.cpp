#include "Transform.h"

namespace engine
{
	void Transform::onInitialize() 
	{
		localScale = rend::vec3(1, 1, 1);
	}

	rend::mat4 Transform::getModel() 
	{
		rend::mat4 rtn(1.0f);

		rtn = rend::translate(rtn, localPosition);
		rtn = rend::rotate(rtn, localRotation.x, rend::vec3(1, 0, 0));
		rtn = rend::rotate(rtn, localRotation.y, rend::vec3(0, 1, 0));
		rtn = rend::rotate(rtn, localRotation.z, rend::vec3(0, 0, 1));
		rtn = rend::scale(rtn, localScale);

		return rtn;
	}

	void Transform::translate(rend::vec3 translation) 
	{
		localPosition += translation;
		setPosition(localPosition);
	}

	void Transform::rotate(rend::vec3 rotation) 
	{
		localRotation += rotation;
		setRotation(localRotation);
	}

	void Transform::scale(rend::vec3 scale) 
	{
		localScale += scale;
		setScale(localScale);
	}

	rend::vec3 Transform::getPosition() 
	{
		return localPosition;
	}

	rend::vec3 Transform::getRotation() 
	{
		return localRotation;
	}

	rend::vec3 Transform::getScale() 
	{
		return localScale;
	}

	void Transform::setPosition(rend::vec3 position) 
	{
		this->localPosition = position;
	}

	void Transform::setRotation(rend::vec3 rotation) 
	{
		this->localRotation = rotation;
	}

	void Transform::setScale(rend::vec3 scale) 
	{
		this->localScale = scale;
	}
}