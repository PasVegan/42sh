/*
** EPITECH PROJECT, 2023
** parsing.h
** File description:
** parsing for 42sh
*/
/*
 _____               __      __
|  __ \              \ \    / /
| |__) |  __ _  ___   \ \  / /   ___   __ _   __ _  _ __
|  ___/  / _` |/ __|   \ \/ /   / _ \ / _` | / _` || '_ \
| |     | (_| |\__ \    \  /   |  __/| (_| || (_| || | | |
|_|      \__,_||___/     \/     \___| \__, | \__,_||_| |_|
                                       __/ |
                                      |___/
*/
#ifndef INC_42SH_PARSING_H
    #define INC_42SH_PARSING_H

    #include "types.h"
    #include <stddef.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>

    ///////////////
    /// Parsing ///
    ///////////////

    command_t **cut_input_to_commands(char *input);
    command_t *parse_single_command(char *comm, command_t *prev, char next_sep,
        int **data);
    void detect_redirections(command_t *command, char *comm, char next_sep,
        int *status);
    int get_redirections_file_descriptors(command_t *command, char *comm);
    char *remove_spaces_in_command(char *comm, char sep, bool pipe_in, int *status);
    bool parse_and_load_redirections(command_t *command);
    void get_word_wait_input(command_t *cmd);
    int load_redirections_for_command(command_t *command);
    void free_commands(command_t **commands);
    void free_command(command_t *command);

    /////////////
    /// Utils ///
    /////////////

    char **my_str_to_word_array(char const *str, char *sep);
    char *get_command_in_path(char *command, pathdir_t **path_dirs);
    void missing_name_for_redirection(void);
    void ambigous_redirection(bool input);
    void null_command(void);

#endif //INC_42SH_PARSING_H

/*
─▄▀▀▀▀▄─█──█────▄▀▀█─▄▀▀▀▀▄─█▀▀▄
─█────█─█──█────█────█────█─█──█
─█────█─█▀▀█────█─▄▄─█────█─█──█
─▀▄▄▄▄▀─█──█────▀▄▄█─▀▄▄▄▄▀─█▄▄▀

─────────▄██████▀▀▀▀▀▀▄
─────▄█████████▄───────▀▀▄▄
──▄█████████████───────────▀▀▄
▄██████████████─▄▀───▀▄─▀▄▄▄──▀▄
███████████████──▄▀─▀▄▄▄▄▄▄────█
█████████████████▀█──▄█▄▄▄──────█
███████████──█▀█──▀▄─█─█─█───────█
████████████████───▀█─▀██▄▄──────█
█████████████████──▄─▀█▄─────▄───█
█████████████████▀███▀▀─▀▄────█──█
████████████████──────────█──▄▀──█
████████████████▄▀▀▀▀▀▀▄──█──────█
████████████████▀▀▀▀▀▀▀▄──█──────█
▀████████████████▀▀▀▀▀▀──────────█
──███████████████▀▀─────█──────▄▀
──▀█████████████────────█────▄▀
────▀████████████▄───▄▄█▀─▄█▀
──────▀████████████▀▀▀──▄███
──────████████████████████─█
─────████████████████████──█
────████████████████████───█
────██████████████████─────█
────██████████████████─────█
────██████████████████─────█
────██████████████████─────█
────██████████████████▄▄▄▄▄█

─────────────█─────█─█──█─█───█
─────────────█─────█─█──█─▀█─█▀
─────────────█─▄█▄─█─█▀▀█──▀█▀
─────────────██▀─▀██─█──█───█
*/

