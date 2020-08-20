#version 130
// It was expressed that some drivers required this next line to function properly
precision highp float;
 
//varying vec4 ex_Color;

in vec4 ex_Color;
 
void main() {
    gl_FragColor = vec4(ex_Color);
}
