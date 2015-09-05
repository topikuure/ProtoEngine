#include "fileutils.h"
#include <string>
//#include <cstring>
#include <fstream>
namespace fileutils
{
int saveBinary(const std::string &filename, char *data, std::size_t size)
    {
    std::ofstream file(filename.c_str(), std::ios_base::out | std::ios_base::binary);
    if(file.fail())
        {
        file.close();
        return 0;
        }
    file.write(data, size);

    if(file.fail())
        {
        file.close();
        return 0;
        }
    file.close();
    return 1;
    }
int loadBinary(const std::string &filename, char *data, std::size_t size)
    {
    std::ifstream file(filename.c_str(), std::ios_base::in | std::ios_base::binary);
    if(file.fail())
        {
        file.close();
        return 0;
        }
    file.seekg(0);
    file.read(data, size);
    if(file.fail())
        {
        file.close();
        return 0;
        }
    file.close();
    return 1;
    }
}