#include <furai.hpp>

void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

FuraiEngine::Graphics::Graphics(int width, int height, std::string title, GLFWmonitor *monitor, GLFWwindow *share){
    if (!glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    CreateWindow(width, height, title, monitor, share);
}

FuraiEngine::Graphics::~Graphics(){
    glfwTerminate();
}

void FuraiEngine::Graphics::CreateWindow(int width, int height, std::string title, GLFWmonitor *monitor, GLFWwindow *share){
    _window = glfwCreateWindow(width, height, title.c_str(), monitor, share);

    if(_window == NULL){
        throw std::runtime_error("Failed to open GLFW window");
    }

    glfwMakeContextCurrent(_window);

    // フレームバッファのコールバック
    glfwSetFramebufferSizeCallback(_window, FramebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        throw std::runtime_error("Failed to initialize GLAD");
    }

    // ImGui関係の初期化
    gui_comp.InitGUIComponent(_window);
}

void FuraiEngine::Graphics::ViewPort(GLint x, GLint y, GLsizei width, GLsizei height){
    glViewport(x, y, width, height);
}

void FuraiEngine::Graphics::SwapBuffers(){
    glfwSwapBuffers(_window);
}

void FuraiEngine::Graphics::ClearColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void FuraiEngine::Graphics::PollEvents(){
    glfwPollEvents();
}

int FuraiEngine::Graphics::WindowShouldClose(){
    return glfwWindowShouldClose(_window);
}

float FuraiEngine::Graphics::GetAspectRatio() {
    int width, height;

    glfwGetFramebufferSize(_window, &width, &height);
    
    if(height == 0){
        return 1.0f;
    }
    return (float)width / (float)height;
}