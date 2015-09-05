#ifndef FILEUTILS_INCLUDED
 #define FILEUTILS_INCLUDED
#include <string>
namespace fileutils
{
int saveBinary(const std::string &filename, char *data, std::size_t size);
int loadBinary(const std::string &filename, char *data, std::size_t size);
}
#endif