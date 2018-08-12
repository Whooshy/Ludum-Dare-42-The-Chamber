#include "audiosource.h"

AudioSource::AudioSource()
{
    alGenSources(1, &ASO);

    alSourcef(ASO, AL_GAIN, 1);
    alSourcef(ASO, AL_PITCH, 1);
    alSource3f(ASO, AL_POSITION, 0, 0, 0);
}

void AudioSource::Play(unsigned int ABO)
{
    alSourcei(ASO, AL_BUFFER, ABO);
    alSourcePlay(ASO);
}

AudioSource::~AudioSource()
{
    alDeleteSources(1, &ASO);
}
