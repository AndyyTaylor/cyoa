#ifndef BLOCK_TYPE_H_INCLUDED
#define BLOCK_TYPE_H_INCLUDED

#include <string>

#include "../Block_Data.h"

namespace Block
{
    class Type
    {
    public:
        
    protected:
        Type (const std::string& fileName);
        
    private:
        Data m_data;
    };
}

#endif