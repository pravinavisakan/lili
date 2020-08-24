#include "../include/camera.hpp"

Camera::Camera(Shader* shader) {
    this->shaderPtr = shader;
}

Camera::~Camera(){}

void Camera::setUpMatrices(){
        glm::mat4 model = glm::translate( glm::mat4(1.0f), glm::vec3( 0, 0, 0) );
         
        glm::mat4 view = glm::lookAt
        (
            glm::vec3(0, 0,-5), // Camera is at ( 0, 0, -5), in World Space
            glm::vec3(0, 0, 0), // And looks at the center
            glm::vec3(0,-1, 0)  // Camera is upside-down
        );
         
        glm::mat4 projection = glm::perspective
        (
            45.0f,              // 45º field of view
            1920.0f / 1080.0f,  // 16:9 aspect ratio
            0.1f,               // Only render what's 0.1 or more away from camera
            100.0f              // Only render what's 100 or less away from camera
        );
         
        glm::mat4 modelViewProjection = projection * view * model;

        // Get the ID
        int matrixID = glGetUniformLocation(shaderPtr->shaderProgram, "mvp");
         
        //Set the matrix
        glUniformMatrix4fv(matrixID, 1, GL_FALSE, &modelViewProjection[0][0]);
}
