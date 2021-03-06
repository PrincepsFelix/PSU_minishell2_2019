/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef IS_CORE_H_INCLUDED
#define IS_CORE_H_INCLUDED

#ifndef SETENV_ERR_1
#define SETENV_ERR_1 ("Variable name must contain alphanumeric characters")
#endif

#include "istl/common_types.h"
#include "env_map.h"
#include "command_model.h"
#include "istl/list.h"
#include "istl/string.h"
#include "istl/iterator.h"
#include "istl/hash_table.h"
#include "istl/utility.h"

typedef enum { GETENV, SETENV, FREE } env_option_t;
typedef int (*builtin_ft)(list_t *args);

char *strerror(int code);

char **env_to_char();
env_map_t env_to_map(char **envp);
env_map_t *env_manager(env_option_t opt, char **environment);
string_t *get_envvar(cchar_t var);
uint_t set_envvar(cchar_t var, cchar_t value);
uint_t unset_envvar(cchar_t var);
void env_add_key(cchar_t key);
void env_rem_key(cchar_t key);
string_t *get_cwd();
string_t *prompt_line();
void print_cchar(cchar_t str);
void print_cerr(cchar_t cmd, cchar_t msg);
void print_invite();
void concat_path(string_t **rpath, string_t const *part);
int change_dir(cchar_t ndir);
int change_sdir(string_t const *ndir);
int builtin_cd(list_t *args);
int builtin_exit(list_t *args);
int builtin_env(list_t *args);
int builtin_setenv(list_t *args);
int builtin_unsetenv(list_t *args);
int eval_extern(cmd_t const *cmd, list_t *args, cmd_t *);
list_t *extract_all_cmds(string_t const *prompt);
builtin_ft get_builtin(string_t const *command);

int eval_prompt(string_t const *prompt);
void print_env();

#endif
