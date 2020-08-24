#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>

#include "../include/Shader.h"

class Camera{
public:
        Camera(Shader* shader);
        ~Camera();

        //setup matrices (or equivalent)
        void setUpMatrices();

        //setters for model, view, perspective

        //input hamdling - handleInput(event e)? - later check type enum for behavior

        // update / render function - called every frame, changes pos for rendering

private:
    Shader* shaderPtr;

};

#endif /*CAMERA_H */
