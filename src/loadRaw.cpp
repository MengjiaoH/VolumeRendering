
#include "loadRaw.h"
#include <vector>

void loadRaw(Data &data){
    std::cout << "  ========== Start Loading Raw Data ==========  " << std::endl;
    std::cout << "  Data File is [Raw]: " << data.filename << std::endl;

    std::ifstream fp(data.filename, std::ios::binary);
    data.depth = std::max(data.dimX, std::max(data.dimY, data.dimZ));
    int u_size;
    if(data.dataType == "uint8"){
        u_size = sizeof(uint8_t);
        std::cout << "  Data Type is: " << data.dataType << std::endl;
        data.GL_dataType = GL_UNSIGNED_BYTE; //uint8
    }else if(data.dataType == "uint16"){
      u_size = sizeof(uint16_t);
      std::cout << "  Data Type is: " << data.dataType << std::endl;
      data.GL_dataType = GL_UNSIGNED_SHORT; //uint16
    }

    int uCount = data.dimX * data.dimY * data.dimZ;

    data.raw_data_ptr = new char[uCount * u_size];
    fp.read((char*)data.raw_data_ptr, uCount * u_size);
    fp.close();

    std::cout << "  Data Size is [Raw]: " << data.dimX << " " << data.dimY << " " << data.dimZ << std::endl;

    std::cout << "  ========== Done Parsing Raw Data ==========  " << std::endl;

}
