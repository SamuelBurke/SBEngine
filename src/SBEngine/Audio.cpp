#include "Audio.h"

#include <AL/al.h>
#include <vorbis/vorbisfile.h>

#include <vector>
#include <iostream>

namespace SBEngine
{

struct AudioImpl
{
	ALuint ID;

	AudioImpl()
	{
		alDeleteBuffers(1, &ID);
	}

	void Load_ogg(std::string _filename, std::vector<char> &_buffer, 
				       ALenum &_format, ALsizei &_freq)
	{
		int endian = 0;
		int bitstream = 0;
		long bytes = 0;
		char array[2048] = { 0 };
		vorbis_info *pInfo = NULL;
		OggVorbis_File oggFile = { 0 };

		// use the inbuilt fopen to create a file descriptor
		if (ov_fopen(_filename.c_str(), &oggFile) != 0)
		{
			std::cout << "Failed to open the file: '" << _filename << "' for decoding" << std::endl;
			throw std::exception();
		}

		//extract information from the file header
		pInfo = ov_info(&oggFile, -1);

		//record the format required by OpenAL
		if (pInfo->channels == 1) 
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		//record the sample rate required by OpenAL
		_freq = pInfo->rate;

		//keep reading bytes from the file to populate the output buffer
		while (true)
		{
			//read bytes into temporary array
			bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitstream);

			if (bytes < 0)
			{
				ov_clear(&oggFile);
				std::cout << "Failed to decode file '" << _filename << "'." << std::endl;
				throw std::exception();
			}
			else if (bytes == 0)
			{
				break;
			}

			//copy from temporary array into output buffer
			_buffer.insert(_buffer.end(), array, array + bytes);
		}

		//clean up and close the file
		ov_clear(&oggFile);
	}
};


Audio::Audio(std::string _audiopath)
{
	Load(_audiopath);
}

void Audio::Load(std::string _audiopath)
{
	m_impl = std::make_shared<AudioImpl>();

	ALenum format = 0;
	ALsizei freq = 0;
	std::vector<char> bufferData;

	alGenBuffers(1, &m_impl->ID);
	m_impl->Load_ogg(_audiopath.c_str(), bufferData, format, freq);

	alBufferData(m_impl->ID, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);

}

void Audio::Play()
{
	ALuint sid = 0;
	alGenSources(1, &sid);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sid, AL_BUFFER, m_impl->ID);
	alSourcePlay(sid);

	//audioSources.push_back(sid);
}

void Audio::Play(float _volume, float _varianceMin, float _varianceMax)
{
	_varianceMin *= 1000.0f;
	_varianceMax *= 1000.0f;
	float variance = (std::rand() % ((int)_varianceMin + 1 - (int)_varianceMax) + (int)_varianceMin) / 1000.0f;
		//return std::rand() % (max + 1 - min) + min;
	ALuint sid = 0;
	alGenSources(1, &sid);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sid, AL_BUFFER, m_impl->ID);
	alSourcef(sid, AL_PITCH, variance);
	alSourcef(sid, AL_GAIN, _volume);
	alSourcePlay(sid);

	//audioSources.push_back(sid);
}

}