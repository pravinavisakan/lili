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
    Shader* shaderPtr; // pointer to the shader program

    glm::mat4 model;   // global transform, used in mvp creation

    glm::vec3 cameraPosition; // component of view matrix
    glm::vec3 cameraDirection; // used to calculate view matrix, avoids freezing on crossover
    glm::vec3 cameraUp; // camera up direction

    glm::mat4 projection; //projection onto screen 

    double yaw;
    double pitch;
    bool rotate; //toggles rotation of camera via mouse movement
};

const double MOUSE_SENSITIVITY = 0.01;
const float MOVEMENT_SPEED = 0.1;

#endif /*CAMERA_H */
