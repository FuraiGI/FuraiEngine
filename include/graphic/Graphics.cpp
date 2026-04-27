#include <furai.hpp>

Furai::Graphics::Graphics(){
    if (!glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Furai::Graphics::~Graphics(){
    glfwTerminate();
}

void Furai::Graphics::CreateWindow(int width, int height, std::string title, GLFWmonitor *monitor, GLFWwindow *share){
    _window = glfwCreateWindow(width, height, title.c_str(), monitor, share);

    if(_window == NULL){
        throw std::runtime_error("Failed to open GLFW window");
    }

    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        throw std::runtime_error("Failed to initialize GLAD");
    }

    // ImGui関係の初期化
    gui_comp.InitGUIComponent(_window);
}

void Furai::Graphics::ViewPort(GLint x, GLint y, GLsizei width, GLsizei height){
    glViewport(x, y, width, height);
}

void Furai::Graphics::SwapBuffers(){
    glfwSwapBuffers(_window);
}

int Furai::Graphics::WindowShouldClose(){
    return glfwWindowShouldClose(_window);
}