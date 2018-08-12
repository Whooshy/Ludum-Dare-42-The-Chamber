#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "reference.h"

#include "AL/al.h"
#include "AL/alc.h"

class AudioPlayer
{
    public:
        AudioPlayer();
        virtual ~AudioPlayer();

    protected:

    private:
        ALCdevice* device;
        ALCcontext* context;
};

#endif // AUDIOPLAYER_H
