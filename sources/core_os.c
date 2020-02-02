/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "core.h"
#include "common_types.h"
#include "list.h"
#include "string.h"
#include "iterator.h"
#include "hash_table.h"
#include "nfa_node.h"
#include "match.h"
#include "builtin_pattern.h"

void concat_path(string_t **rpath, string_t *part)
{
    string_t *tmp = 0;
    string_t *path = *rpath;

    if (rpath == 0 || path == 0 || part == 0)
        return;
    tmp = str_addch(path, '/');
    str_free(&path);
    path = tmp;
    tmp = str_concat(path, part);
    str_free(&path);
    *rpath = tmp;
}

int change_dir(cchar_t ndir)
{
    string_t *dir = 0;
    string_t *path = 0;

    if (ndir == 0)
        return (84);
    path = get_cwd();
    dir = str_create(ndir);
    concat_path(&path, dir);
    if (chdir(str_cstr(path)) != 0)
        if (chdir(str_cstr(dir)) != 0) {
            print_cerr("cd", 0);
            str_free(&dir);
            str_free(&path);
            return (84);
        }
    str_free(&dir);
    str_free(&path);
    return (0);
}

int change_sdir(string_t const *ndir)
{
    return (change_dir(str_cstr(ndir)));
}