#ifndef AUDIOSOURCE_H
#define AUDIOSOURCE_H

#include "AL/al.h"
#include "AL/alc.h"

class AudioSource
{
    public:
        AudioSource();
        virtual ~AudioSource();

        void Play(unsigned int ABO);

        unsigned int GetSource() const { return ASO; }

    protected:

    private:
        unsigned int ASO;
};

#endif // AUDIOSOURCE_H
