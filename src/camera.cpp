#include "../include/camera.hpp"

//debug
#include <iostream>

// Constructor - set up reference to shader object, and model, view, perspective matrices
Camera::Camera(Shader* shader) {
    this->shaderPtr = shader;

    //default values
    this->model = glm::translate( glm::mat4(1.0f), glm::vec3( 0, 0, 0) );

    this->cameraPosition = glm::vec3(0, 0,-5);
    this->cameraDirection = glm::vec3(0, 0, 1);
    this->cameraUp = glm::vec3(0,-1, 0);

    this->projection = glm::perspective
    (
            45.0f,              // 45º field of view
            1920.0f / 1080.0f,  // 16:9 aspect ratio
            0.1f,               // Only render what's 0.1 or more away from camera
            100.0f              // Only render what's 100 or less away from camera
    );

    this->yaw = 0;
    this->pitch = 0;
}

Camera::~Camera(){}

// helper function, create modelViewProjection and copy to graphics program for the vertex shader to use
//handle frame to frame changes
//TODO implement different modes - periodic, fixed, free
//TODO enable parameter delta t for time-sensitive rendering - periodic, or movement scaled for different processor speeds
void Camera::update(){

    //debug
    //std::cout << "Camera Position x: " << this->cameraPosition.x << " y: " << this->cameraPosition.y << " z: " << this->cameraPosition.z <<"\n";
    //std::cout << "Camera Target x: " << this->cameraDirection.x << " y: " << this->cameraDirection.y << " z: " << this->cameraDirection.z <<"\n";

    // calculate mvp
    glm::mat4 view = glm::lookAt
    (
            this->cameraPosition,
            this->cameraPosition+this->cameraDirection,
            this->cameraUp
    );

    glm::mat4 modelViewProjection = projection * view * model;

    // Get the ID
    int matrixID = glGetUniformLocation(shaderPtr->shaderProgram, "mvp");

    //Set the matrix
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &modelViewProjection[0][0]);
}

// for camera controls, call on every iteration of the input loop, however that's handled
void Camera::handleInput(SDL_Event event) {

    //process translation

    glm::vec3 rightward = glm::normalize(glm::cross(this->cameraDirection, this->cameraUp));
    //check for a keydown event
    if (event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym) {
            case SDLK_w:
                this->cameraPosition += this->cameraDirection;
                break;
            case SDLK_s:
                this->cameraPosition -= this->cameraDirection;
                break;
            case SDLK_a:
                this->cameraPosition -= rightward;
                break;
            case SDLK_d:
                this->cameraPosition += rightward;
                break;
            default:
                break;
        }
    }

    //process rotation w/ mouse input

    //toggle rotation
    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
       this->rotate = true;
    else if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
        this->rotate = false; 

    // process rotation
    if(event.type == SDL_MOUSEMOTION && this->rotate){
        //update yaw and pitch values based on mouse movement
        this->yaw += event.motion.xrel * MOUSE_SENSITIVITY;        
        this->pitch += event.motion.yrel * MOUSE_SENSITIVITY;

        // restrict pitch to relevant quadrants
        if(this->pitch > M_PI/2)
                this->pitch = M_PI/2;
        else if(this->pitch < -M_PI/2)
                this->pitch = -M_PI/2;

        //update camera direction based on yaw and pitch
        this->cameraDirection = glm::normalize(glm::vec3((sin(yaw)*cos(pitch)),(sin(pitch)),(cos(yaw))));
    }

}
