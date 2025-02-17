#pragma once

#include <cli/cli.h>
#include "../../types/plugin_state.h"

#define TOTP_CLI_COMMAND_NAME "totp"

#define DOCOPT_ARGUMENT(arg) "<" arg ">"
#define DOCOPT_OPTIONAL(param) "[" param "]"
#define DOCOPT_REQUIRED(param) "(" param ")"
#define DOCOPT_OPTION(option, value) option " " value
#define DOCOPT_SWITCH(option) option
#define DOCOPT_OPTIONS "[options]"
#define DOCOPT_DEFAULT(val) "[default: " val "]"

#define TOTP_CLI_PRINTF(format, ...)                                        \
    do {                                                                    \
        _Pragma(STRINGIFY(GCC diagnostic push))                             \
            _Pragma(STRINGIFY(GCC diagnostic ignored "-Wdouble-promotion")) \
                printf(format, ##__VA_ARGS__);                              \
        _Pragma(STRINGIFY(GCC diagnostic pop))                              \
    } while(false)

#define TOTP_CLI_DELETE_LAST_LINE()    \
    TOTP_CLI_PRINTF("\033[A\33[2K\r"); \
    fflush(stdout)

#define TOTP_CLI_DELETE_CURRENT_LINE() \
    TOTP_CLI_PRINTF("\33[2K\r");       \
    fflush(stdout)

#define TOTP_CLI_DELETE_LAST_CHAR() \
    TOTP_CLI_PRINTF("\b \b");       \
    fflush(stdout)

#define TOTP_CLI_PRINT_INVALID_ARGUMENTS() \
    TOTP_CLI_PRINTF(                       \
        "Invalid command arguments. use \"help\" command to get list of available commands")

bool totp_cli_ensure_authenticated(const PluginState* plugin_state, Cli* cli);
