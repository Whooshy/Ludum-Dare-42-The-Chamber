#ifndef AUDIODATA_H
#define AUDIODATA_H

#include "reference.h"

#include "AL/al.h"
#include <fstream>
#include <windows.h>

class AudioData
{
    public:
        AudioData(const char* path);
        virtual ~AudioData();

        unsigned char* LoadWavData(const char* path);

        unsigned int GetABO() const { return ABO; }
        unsigned char* GetData() const { return data; }

    protected:

    private:
        unsigned int ABO;
        unsigned char* data;

        unsigned int format;

        short formatType, channels, bytesPerSample, bitsPerSample;
        DWORD size, chunkSize, sampleRate, average, dataSize;
};

#endif // AUDIODATA_H
