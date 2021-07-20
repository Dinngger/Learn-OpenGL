#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define GLEW_STATIC
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;
#define WIDTH 2
#define HEIGHT 3
int main(int argc, char** argv)
{
    int nWidth=(int)WIDTH;
    int nHeight=(int)HEIGHT;
    int nSize=(int)nWidth*nHeight;

    //创建输入数据
    float* pfInput=new float[4*nSize];
    float* pfOutput=new float[4*nSize];
    for (int i=0; i<nSize*4; i++)
    {
        pfInput[i]= (float)(i) / 10.0;
    }
    //初始化并设置GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    //创建GLFW窗口
    GLFWwindow* window = glfwCreateWindow(3, 2, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //创建FBO并绑定
    GLuint fb;
    glGenFramebuffers(1, &fb);
    glBindFramebuffer(GL_FRAMEBUFFER, fb);

    //创建纹理对象并绑定
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    //设置纹理参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    //将纹理关联到FBO
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0);

    //将纹理数据设置为单精度浮点数

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nWidth, nHeight,0, GL_RGBA, GL_FLOAT, NULL); 
    //将数据传至输入纹理缓存
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, nWidth, nHeight, GL_RGBA, GL_FLOAT, pfInput);

    //从输出纹理缓存中读出数据
    glReadBuffer(GL_COLOR_ATTACHMENT0);
    glReadPixels(0,0, nWidth, nHeight, GL_RGBA, GL_FLOAT, pfOutput);

    //打印并检查结果
    bool bCap=true;
    for (int i=0; i<nSize*4; i++)
    {
        cout<<i<<":\t"<<pfInput[i]<<'\t'<<pfOutput[i]<<endl;
        if (pfInput[i]!=pfOutput[i])  bCap=false;
    }

    if (bCap) cout<<"Round trip complete!"<<endl;
    else      cout<<"Round trip failed!" <<endl;

    delete pfInput;
    delete pfOutput;
    glDeleteFramebuffers(1, &fb);
    glDeleteTextures(1, &tex);
    return 0;
}
