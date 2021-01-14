#include <string>
#include <vector>
#include <AL/al.h>

namespace engine
{
	struct Sound
	{
	public:
		void onLoad(const std::string& path);

	private:
		ALuint loadOgg(const std::string& fileName, 
			std::vector<char>& buffer, ALenum& format, ALsizei& freq);
	};
}