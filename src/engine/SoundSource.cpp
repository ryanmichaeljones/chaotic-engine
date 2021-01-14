#include "SoundSource.h"

namespace engine
{
	///<summary>
	/// Initializes and outputs sound.
	///</summary>
	void SoundSource::onInitialize(std::shared_ptr<Sound> sound)
	{
		sid = 0;

		alGenSources(1, &sid);
		alSourcei(sid, AL_BUFFER, 0);
		alSourcePlay(sid);
	}

	///<summary>
	/// Checks state of sound every tick.
	///</summary>
	void SoundSource::onTick()
	{
		ALint state = 0;

		alGetSourcei(sid, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			onDestroy();
		}
	}

	///<summary>
	/// Destroys sound source.
	///</summary>
	void SoundSource::onDestroy()
	{
		alDeleteSources(1, &sid);
	}
}