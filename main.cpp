#include <iostream>
#include <fstream>
#include <string>

#include "src/neper.hpp"

int main(void)
{
    std::string path = "/Users/raphaelgoutmann/Desktop/Neper/data/example.html";
    
    /* lecture du fichier */

    std::ifstream file (path);
    if( !file.is_open() ) {
        std::cerr << "Cannot open " << path << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::string html = "";
    
    std::string line;
    while( getline(file, line) ) {
        html.append(line);
    }

    /* fin lecture */
    

    dom::Node* tree = html::parseHTML(html);
    std::cout << *tree << std::endl;
    delete tree;

    return 0;
}