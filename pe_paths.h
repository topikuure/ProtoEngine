#ifndef PE_PATHS_INCLUDED
 #define PE_PATHS_INCLUDED
#include <string>
//Tee tästä dynaamisempi. Mieti mistä root-polku revitään. Onko järkevää tehdä uusi namespace?
namespace PE_Paths
{
std::string root = std::string("C:\\Users\\Topi\\Documents\\Ohjelmointi\\ProtoEngine\\");
std::string sprites = std::string("sprites\\");
std::string levels = std::string("levels\\");
}
#endif