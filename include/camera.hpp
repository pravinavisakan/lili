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
        void update();

        //setters for model, view, perspective

        //input hamdling - handleInput(event e)? - later check type enum for behavior
        void handleInput(SDL_Event event);

private:
    Shader* shaderPtr;
    glm::mat4 model;
    glm::vec3 cameraPosition;
    glm::vec3 cameraDirection;
    glm::vec3 cameraUp;
    glm::mat4 projection;

};

#endif /*CAMERA_H */
