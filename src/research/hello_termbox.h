/**
 * @file hello_termbox.h
 * @author William Blount
 * @date 7/6/2018
 * @brief Simple "Hello World" test using termbox.
 *
 * This application will initialize the termbox screen, clear the screen, and
 * then write the text "Hello, World!" in rainbow colors (once with only the
 * foreground color, once with only the background color, and once with both).
 */

#ifndef HELLO_TERMBOX_DEFINED
#define HELLO_TERMBOX_DEFINED

const uint16_t RAINBOW[] = {
    TB_RED,
    TB_YELLOW,
    TB_GREEN,
    TB_CYAN,
    TB_BLUE,
    TB_MAGENTA
};

/**
 * @brief Writes a message with rainbow fg (black bg) at the given position.
 */
void write_rainbow_fg(int x, int y, char *msg);

/**
 * @brief Writes a message with rainbow bg (black fg) at the given position.
 */
void write_rainbow_bg(int x, int y, char *msg);

/**
 * @brief Writes a message with rainbow fg and bg at the given position.
 */
void write_rainbow_fg_bg(int x, int y, char *msg);

#endif
