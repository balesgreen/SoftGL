#include <glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "SoftGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    std::cout << "Renderizando triangulo.." << std::endl;

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Ativador das estruturas que serão renderizadas na tela | GL_LINE -> apenas desenha linhas e não
        // preenche o background da imagem que está sendo renderizada.
        // Caso for renderizar a imagem com o background preenchido, apenas remova o GL_LINE
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
            glVertex3f(0.0, 0.5, 0.0);
            glVertex3f(-0.5, -0.5, 0.0);
            glVertex3f(0.5, -0.5, 0.0);
        glEnd();
    }

    glfwTerminate();
    return 0;
}