#ifndef PATHS_INCLUDED
 #define PATHS_INCLUDED
#include <string>
//Tee tästä dynaamisempi. Mieti mistä root-polku revitään. Onko järkevää tehdä uusi namespace?
namespace Paths
{
std::string root = std::string("C:\\Users\\Topi\\Documents\\Ohjelmointi\\ProtoEngine\\PE\\");
std::string sprites = std::string("sprites\\");
std::string levels = std::string("levels\\");
}
#endif