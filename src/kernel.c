#include <stdbool.h>

#include "utils/colors.h"
#include "screen/in_out.h"
#include "screen/screen.h"
#include "ports/ports.h"
#include "keyboard/keys.h"
#include "utils/commands.h"

void main() {
    unsigned int pos = 0;
    char *vidptr = (char*)0xb8000;

    clean_screen(vidptr, BG_BLACK);

    for (int i = 0; i < 10; i++) {
        char command[MAX_BUFFER_SIZE];

        _printf(&pos, vidptr, FG_CYAN | BG_BLACK, "CosmOS@usr:~$ ");
        _scanf(&pos, vidptr, FG_WHITE | BG_BLACK, "%s", &command);
    
        handle_command(command, &pos, vidptr);
    }
    

    return;
}