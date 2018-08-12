#include "audioplayer.h"

AudioPlayer::AudioPlayer()
{
    device = alcOpenDevice(NULL);

    if(!device) std::cerr << "No sound device found!" << std::endl;

    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);

    if(!context) std::cerr << "No sound context found!" << std::endl;

    alListener3f(AL_POSITION, 0, 0, 0);
    alListener3f(AL_VELOCITY, 0, 0, 0);
}

AudioPlayer::~AudioPlayer()
{
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
}
