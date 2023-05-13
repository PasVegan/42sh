/*
** EPITECH PROJECT, 2023
** shell.c
** File description:
** shell for 42sh
*/

#include "shell.h"
#include "history.h"
#include "line_edition.h"

uint8_t write_prompt(envdata_t *env)
{
    printf(env->is_fallback ? "> " : "<%s@%s %s >$ ", env->user,
        env->hostname, env->cwd);
    fflush(stdout);
    return 1;
}

void process_key(ShellContext *context, InputBuffer *input_data)
{
    realloc_input(input_data);
    if (input_data->read[0] == '\x1b' && input_data->read[1] == '[') {
        if (process_arrow_keys(input_data, context)) return;
        if (process_delete_key(input_data)) return;
        if (process_home_end_keys(input_data)) return;
        return;
    }
    if (input_data->read[0] == 0x7f) {
        process_backspace_key(input_data);
        return;
    }
    if (input_data->read[0] == 4)
        handle_ctrl_d(context);
    if (strchr(input_data->read, '\n'))
        process_enter_key(context, input_data);
    else
        process_regular_key(input_data);
}

int shell(envdata_t *env, struct termios *old_term, struct termios *new_term)
{
    ShellContext context = {env, 0, false};
    InputBuffer input_data = {malloc(1024), NULL,0, 0, {0}, 0, 1,false};
    memset(input_data.input, 0, 1024);
    if (isatty(0)) {
        configure_terminal(new_term, old_term);
        write_prompt(env);
        input_data.is_tty = true;
    }
    while (!context.exiting) {
        input_data.read_len = read(STDIN_FILENO, input_data.read, 4);
        process_key(&context, &input_data);
        fflush(stdout);
        memset(input_data.read, 0, 5);
    }
    free(input_data.input);
    return context.status;
}
