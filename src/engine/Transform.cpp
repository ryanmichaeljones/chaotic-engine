#include "Transform.h"

namespace engine 
{
	///<summary>
	/// Initializes the transform component.
	///</summary>
	void Transform::onInitialize()
	{
		localScale = rend::vec3(1, 1, 1);
	}

	///<summary>
	/// Returns the matrix model of a transform.
	///</summary>
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

	///<summary>
	/// Translates the position of a transform by a given vector.
	///</summary>
	void Transform::translate(rend::vec3 translation)
	{
		localPosition += translation;
		setPosition(localPosition);
	}

	///<summary>
	/// Rotates a transform by a given vector.
	///</summary>
	void Transform::rotate(rend::vec3 rotation)
	{
		localRotation += rotation;
		setRotation(localRotation);
	}

	///<summary>
	/// Scales a transform by a given vector.
	///</summary>
	void Transform::scale(rend::vec3 scale)
	{
		localScale += scale;
		setScale(localScale);
	}

	///<summary>
	/// Returns the local position of a transform.
	///</summary>
	rend::vec3 Transform::getPosition()
	{
		return localPosition;
	}

	///<summary>
	/// Returns the local rotation of a transform.
	///</summary>
	rend::vec3 Transform::getRotation()
	{
		return localRotation;
	}

	///<summary>
	/// Returns the local scale of a transform.
	///</summary>
	rend::vec3 Transform::getScale()
	{
		return localScale;
	}

	///<summary>
	/// Sets the position of a transform.
	///</summary>
	void Transform::setPosition(rend::vec3 position)
	{
		this->localPosition = position;
	}

	///<summary>
	/// Sets the rotation of a transform.
	///</summary>
	void Transform::setRotation(rend::vec3 rotation)
	{
		this->localRotation = rotation;
	}

	///<summary>
	/// Sets the scale of a transform.
	///</summary>
	void Transform::setScale(rend::vec3 scale)
	{
		this->localScale = scale;
	}
}