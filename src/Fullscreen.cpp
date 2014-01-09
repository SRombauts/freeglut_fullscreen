/**
 * @file    Fullscreen.cpp
 * @brief   Tests of freeglut fullscreen Game Mode.
 *
 * Copyright (c) 2014 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */


#include <GL/freeglut.h>
#include <iostream>

/*

From GLUT manual :

When game mode is entered, certain GLUT functionality is disable to 
facilitate high-performance fullscreen rendering. GLUT pop-up menus are not 
available while in game mode. Other created windows and subwindows are not 
displayed in GLUT game mode. Game mode will also hide all other applications 
running on the computer's display screen. The intent of these restrictions 
is to eliminate window clipping issues, permit screen display format 
changes, and permit fullscreen rendering optimization such as page flipping 
for fullscreen buffer swaps.

The value returned by glutEnterGameMode is a unique small integer identifier 
for the fullscreen window. The range of allocated identifiers starts at one. 
This window identifier can be used when calling glutSetWindow.

After leaving game mode, the GLUT functionality disabled in game mode is 
available again. The game mode window (and its OpenGL rendering state) is 
destroyed when leaving game mode. Any windows and subwindows created before 
entering the game mode are displayed in their previous locations. The OpenGL 
state of normal GLUT windows and subwindows is not disturbed by entering 
and/or leaving game mode.

*/

void display() {
    glClearColor(0.0f, 0.0f, 0.1f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glFlush();

    glutSwapBuffers();      // Swap front & back buffers, waiting for vsynch if driver configured for it
    glutPostRedisplay();    // Ask for refresh ; only needed if animation are present
}


/**
 * @brief GLUT keyboard key pressed callback function
 *
 * @param[in] aKey  ASCII code of the key pressed
 * @param[in] aX    X coord of the mouse cursor (0 is the left of the render surface of the window: can be negative!)
 * @param[in] aY    Y coord of the mouse cursor (0 is the top of the render surface of the window: can be negative!)
 */
void keyboard(unsigned char aKey, int aX, int aY) {
    std::cout << "keyboardCallback(" << static_cast<int>(aKey) << "='" << aKey
                        << "'," << aX << "," << aY << ")\n";

    // ESC to quit
    if (27 == aKey) {
        glutLeaveMainLoop();
    }
}

// Register freeglut callbacks
void registerCallbacks() {
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
}

// OpenGL init
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

// OpenGL & freeglut cleanup
void cleanup() {
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

/*  glutInitWindowPosition(0,0);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Fullscreen");
*/
    // setting the game mode replaces the above
    // calls to set the window size and position.
    glutGameModeString("1920x1080:32");
    // enter full screen
    if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
        glutEnterGameMode();
    } else {
        std::cout << "The select mode is not available\n";
        exit(1);
    }

    // register all callbacks
    registerCallbacks();
    init();

    // Main Loop (specifically asking to continue here on exiting main loop)
    std::cout << "main loop starting...\n";
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutMainLoop();
    std::cout << "bye...\n";

    cleanup();

    return 0;
}

