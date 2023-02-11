#include <thread>
#include <chrono>

#include "board.h"
#include "item.h"
#include "clear.h"
#include "draw.h"

int main(){
    // init
    Board board;
    board = item::gosper(board, 2,4);

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(500, 500, "uwu", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 1, 1);
        print(board);
        board.next();

        glfwSwapBuffers(window);
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    glfwTerminate();
    return 0;
}