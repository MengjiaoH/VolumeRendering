#include "common.h"
#include "loadRaw.h"
#ifdef USE_GLM
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>
#else
# error "GLM is required here"
#endif
class transferControlPoint{
public:
    glm::vec4 color;
    int isoValue;
    /*
    ** Constructor for color control points
    */
    transferControlPoint(float r, float g, float b, float alpha, int isovalue){
        color.x = r;
        color.y = g;
        color.z = b;
        color.w = alpha;
        isoValue = isovalue;
    }
    /*
    ** Constructor for alpha control points
    */
    // transferControlPoint(float alpha, int isovalue)
    // {
    //     color.x = 0.0f;
    //     color.y = 0.0f;
    //     color.z = 0.0f;
    //     color.w = alpha;
    //     isoValue = isovalue;
    // }
};

void loadTF(GLuint &textureTF, Data data);
