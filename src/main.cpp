#include <iostream>
#include <cmath>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//const unsigned int width = 800;
//const unsigned int height = 800;

int main()
{
    //Requesting the Width and Height of the Open GL Window
    int width;
    int height;

    std::cout << "Program Started." << std::endl;
    std::cout << "Please Fill in the below Settings" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "Width of Window: ";
    std::cin >> width;

    std::cout << "Height of Window: ";
    std::cin >> height;
  
    const int constWidth = width;
    const int constHeight = height;


    //Requesting RGBA for Color of Background
    std::vector <GLfloat> backgroundColor;
    GLfloat red = -1;
    GLfloat gre = -1;
    GLfloat blu = -1;
    std::cout << " " << std::endl;
    std::cout << "Color of Window " << std::endl;
    //Red of RGBA
    while(not (red <= 1 and red >= 0))
    {
        std::cout << "Red: ";
        std::cin >> red;
    }
    backgroundColor.push_back(red);
    //Green of RGBA
    while(not (gre <= 1 and gre >= 0))
    {
        std::cout << "Green: ";
        std::cin >> gre;
    }
    backgroundColor.push_back(gre);
    //Blue of RGBA
    while(not (blu <= 1 and blu >= 0))
    {
        std::cout << "Blue: ";
        std::cin >> blu;
    }
    backgroundColor.push_back(blu);
    backgroundColor.push_back(1);



    //Setting up Open GL
    glfwInit(); //Initialize GLFW

    //Hinting GLFW all of our settings so it knows what its working with
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3.3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3.3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Creating the Open GL Window
    GLFWwindow* window = glfwCreateWindow(constWidth, constHeight, "Automation", NULL, NULL);

    //Checking Whether the Window was properly created
    if (window == NULL)
    {
        std::cout << "Error in creating the GLFW Window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Setting Up GLAD
    gladLoadGL();
    glViewport(0, 0, constWidth, constHeight);

    while (!glfwWindowShouldClose(window))
	{
		glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
	}

    //Close Down Shop
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

