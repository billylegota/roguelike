/**
 * @file hello_termbox.c
 * @author William Blount
 * @date 7/6/2018
 * @brief Simple "Hello World" test using termbox.
 *
 * This application will initialize the termbox screen, clear the screen, and
 * then write the text "Hello, World!" in rainbow colors (once with only the
 * foreground color, once with only the background color, and once with both).
 */

#include <stdint.h>

#include "termbox.h"

const uint16_t RAINBOW[] = {
    TB_RED,
    TB_YELLOW,
    TB_GREEN,
    TB_CYAN,
    TB_BLUE,
    TB_MAGENTA
};

int main(void) {
    // Initialize the screen.
    tb_init();

    // Then clear it.
    tb_clear();

    // Write "Hello, World" with rainbow foreground.
    write_rainbow_fg(0, 0, "Hello, World!");

    // Write "Hello, World" with rainbow background.
    write_rainbow_bg(0, 1, "Hello, World!");

    // Write "Hello, World" with rainbow foreground and background.
    write_rainbow_bg(0, 2, "Hello, World!");

    // Show the changes.
    tb_present();

    // Close the screen and exit.
    tb_shutdown();
    return 0;
}

/**
 * @brief Writes a message with rainbow fg (white bg) at the given position.
 */
void write_rainbow_fg(int x, int y, char *msg) {
    for(int i = 0; msg[i] != NULL; i++) {
        uint32_t ch = (uint32_t) msg[i];
        uint16_t fg = RAINBOW[i % 6];
        uint16_t bg = TB_WHITE;

        tb_change_cell(x + i, y, ch, fg, bg);
    }
}

/**
 * @brief Writes a message with rainbow bg (white fg) at the given position.
 */
void write_rainbow_bg(int x, int y, char *msg) {
    for(int i = 0; msg[i] != NULL; i++) {
        uint32_t ch = (uint32_t) msg[i];
        uint16_t fg = TB_WHITE;
        uint16_t bg = RAINBOW[i % 6];

        tb_change_cell(x + i, y, ch, fg, bg);
    }
}

/**
 * @brief Writes a message with rainbow fg and bg at the given position.
 */
void write_rainbow_bg_fb(int x, int y, char *msg) {
    for(int i = 0; msg[i] != NULL; i++) {
        uint32_t ch = (uint32_t) msg[i];
        uint16_t fg = RAINBOW[i % 6];
        uint16_t bg = RAINBOW[(i - 1) % 6];

        tb_change_cell(x + i, y, ch, fg, bg);
    }
}
