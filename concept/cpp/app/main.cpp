
/// \brief  STL Includes
#include <iostream>
#include <vector>
#include <string>

/// \brief  Crust Includes
#include "../lib/crust_entity.h"

/// \brief  Main Implementation
int main( int argn, char* argc[] ) {

    crust::Entity<crust::Base> entity;

    entity["Color"]         = "(1.0, 1.0, 1.0)";
    entity["Position"]      = "(2.5, 1.0, 1.0)";

    entity.setRender(
     [&] ( crust::Entity<crust::Base>* ent) -> void {
        std::cout << "Meow" << std::endl;
     }
    );

    std::cout << entity["Color"] << std::endl;
    std::cout << entity["Position"] << std::endl;

    entity.onRender();


    return 0;
}
