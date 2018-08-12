#ifndef EREREADER_H
#define EREREADER_H

#include "reference.h"
#include "world.h"
#include "player.h"

#include <fstream>

class EREReader
{
    public:
        EREReader();
        virtual ~EREReader();

        void LoadExport(World& world, const char* filename);
        void LoadNodes(World& world, Player& player, const char* filename);

    protected:

    private:

};

#endif // EREREADER_H
