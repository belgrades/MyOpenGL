#include "figura.h"

GLfloat figura::PixelToOpenGLX(int x){
    return  (GLfloat)((x<<1)-(GL_WINDOW_WIDTH-1))/(GL_WINDOW_WIDTH-1);

}
GLfloat figura::PixelToOpenGLY(int y){
    return (GLfloat)((GL_WINDOW_HEIGHT-1)-(y<<1))/(GL_WINDOW_HEIGHT-1);
}
GLint figura::OpenGLToPixelX(float x){
    return (GLint)(((GL_WINDOW_WIDTH-1)*(x+1)))>>1;
}
GLint figura::OpenGLToPixelY(float y){
    return (GLint)((GL_WINDOW_HEIGHT-1)-((GL_WINDOW_HEIGHT-1)*y))>>1;
}
