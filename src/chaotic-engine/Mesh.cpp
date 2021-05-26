#include "Mesh.h"
#include "Core.h"

namespace engine
{
	void Mesh::onLoad()
	{
		mesh = getCore()->getContext()->createMesh();

		std::ifstream f(getPath());
		if (!f.is_open())
		{
			throw std::exception("Failed to open model");
		}

		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		mesh->parse(obj);
	}

	std::shared_ptr<rend::Mesh> Mesh::getMesh()
	{
		return mesh;
	}
}