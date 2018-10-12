#include <string>
#include <memory>

namespace SBEngine
{

struct AudioImpl;

class Audio
{
std::shared_ptr<AudioImpl> m_impl;

public:
	Audio();
	Audio(std::string _audioPath);

	void Load(std::string _audioPath);
	//void Play(float _volume, float _varianceMin, float _varianceMax);
	void Play();

};
}