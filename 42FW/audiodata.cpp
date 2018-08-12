#include "audiodata.h"

AudioData::AudioData(const char* path)
{
    alGenBuffers(1, &ABO);
    data = LoadWavData(path);

    if(bitsPerSample == 8)
    {
        if(channels == 1)
            format = AL_FORMAT_MONO8;
        if(channels == 2)
            format = AL_FORMAT_STEREO8;
    }
    if(bitsPerSample == 16)
    {
        if(channels == 1)
            format = AL_FORMAT_MONO16;
        if(channels == 2)
            format = AL_FORMAT_STEREO16;
    }

    alBufferData(ABO, format, data, dataSize, sampleRate);
    delete data;
}

unsigned char* AudioData::LoadWavData(const char* path)
{
    FILE* file = fopen(path, "rb");
    if(!file)
    {
        std::cerr << "Invalid file path! " << path << std::endl;
        return NULL;
    }

    /*
    WAV files are formatted as follows:

    Bytes 1-4: "RIFF" tag (char[4])
    Bytes 5-8: Size (32-bit integer (DWORD/unsigned int))
    Bytes 9-12: "WAVE" tag (char[4])
    Bytes 13-16: "fmt " tag (char[4])
    Bytes 17-20: Chunk size (32-bit integer)
    Bytes 21-22: Format type (16-bit integer (short))
    Bytes 23-24: # of channels (16-bit integer)
    Bytes 25-28: Sample rate (32-bit integer)
    Bytes 29-32: Average bytes/sec (32-bit integer)
    Bytes 33-34: Bytes per sample (16-bit integer)
    Bytes 35-36: Bits per sample (16-bit integer)
    Bytes 37-40: "data" tag (char[4])
    Bytes 41-44: Data Size (32-bit integer)
    Bytes 45+: Data
    */

    char wavType[4];

    fread(wavType, sizeof(char), 4, file);

    if(!strcmp(wavType, "RIFF"))
    {
        std::cerr << "Invalid .WAV type : " << path << std::endl;
        return NULL;
    }

    fread(&size, sizeof(DWORD), 1, file);
    fread(wavType, sizeof(char), 4, file);

    if(!strcmp(wavType, "WAVE"))
    {
        std::cerr << "WAVE tag not present : " << path << std::endl;
        return NULL;
    }

    fread(wavType, sizeof(char), 4, file);

    if(!strcmp(wavType, "fmt "))
    {
        std::cerr << "Invalid .WAV format : " << path << std::endl;
        return NULL;
    }

    fread(&chunkSize, sizeof(DWORD), 1, file);
    fread(&formatType, sizeof(short), 1, file);
    fread(&channels, sizeof(short), 1, file);
    fread(&sampleRate, sizeof(DWORD), 1, file);
    fread(&average, sizeof(DWORD), 1, file);
    fread(&bytesPerSample, sizeof(short), 1, file);
    fread(&bitsPerSample, sizeof(short), 1, file);

    fread(wavType, sizeof(char), 4, file);

    if(!strcmp(wavType, "data"))
    {
        std::cerr << "Missing data : " << path << std::endl;
        return NULL;
    }

    fread(&dataSize, sizeof(DWORD), 1, file);

    unsigned char* newData = new unsigned char[dataSize];
    fread(newData, 1, dataSize, file);

    return newData;
}

AudioData::~AudioData()
{
    alDeleteBuffers(1, &ABO);
}
