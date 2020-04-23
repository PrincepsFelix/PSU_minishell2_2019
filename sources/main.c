/*
** EPITECH PROJECT, 2019
** minishell1 main
** File description:
** Description
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#include "istl/common_types.h"
#include "istl/list.h"
#include "istl/string.h"
#include "istl/iterator.h"
#include "istl/hash_table.h"
#include "core.h"
#include "env_map.h"

void print_invite(void)
{
    string_t *cwd = get_envvar("PWD");

    if (!isatty(0))
        return;
    str_print(cwd);
    str_free(&cwd);
    print_cchar(" > ");
}

void prompt_loop(void)
{
    string_t *prompt = 0;

    while (1) {
        print_invite();
        prompt = prompt_line(prompt);
        if (prompt == 0) {
            if (isatty(0))
                print_cchar("exit\n");
            break;
        }
        if (eval_prompt(prompt) == 200)
            break;
        str_free(&prompt);
    }
    str_free(&prompt);
}

void handle_sigint(int sig)
{
    write(1, "\n", 1);
    print_invite();
}

int main(int argc, char **argv, char **env)
{
    string_t *arg = 0;

    signal(SIGINT, handle_sigint);
    env_manager(SETENV, env);
    if (argv[1] != 0) {
        arg = str_create(argv[1]);
        eval_prompt(arg);
        str_free(&arg);
    } else
        prompt_loop();
    env_manager(FREE, 0);
    return (0);
}
