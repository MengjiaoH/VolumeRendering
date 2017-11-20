//
//  main.cpp
//  tb_volume_rendering
//
//  Created by 韩孟娇 on 10/2/17.
//  Copyright © 2017 Mengjiao. All rights reserved.
//

#include <iostream>
#include "loadRaw.h"
#include "viewPort.h"

// global variables need to extern in view.h
Data volumeData;

int main(int argc, char * argv[]) {
    /*
    ** Read Command Lines
    */
//   volumeData.filename = argv[1];
//   volumeData.dimX = atoi(argv[2]); volumeData.dimY = atoi(argv[3]); volumeData.dimZ = atoi(argv[4]);
//   volumeData.dataType = argv[5];
     volumeData.filename = "../data/visMale_128x256x256.raw";
     volumeData.dimX = 128; volumeData.dimY = 256; volumeData.dimZ = 256;
     volumeData.dataType = "uint8";
    loadRaw(volumeData);
    int check = 1;
    check = ShowViewPort();


    return check;
}
