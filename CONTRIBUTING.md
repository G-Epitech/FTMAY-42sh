# Welcome on 42sh project !

Contribute to this Epitech project involves following strict rules to keep a clean project and easily maintainable code.

* [1 - Project architecture and file naming](#1---project-architecture-and-file-naming)
* [2 - Commits and Pull Requests](#2---commits-and-pull-requests)
* [3 - Variables and types naming](#3---variables-and-types-naming)
* [4 - Header files and preprocessor directives](#4---header-files-and-preprocessor-directives)
* [5 - Functions](#5---functions)

## 1 - Project architecture and file naming
Files conventions naming and project architecture need to be followed.

### a - Files and folders naming
Files and folders names must be short and readable by architecure depth level.

*Examples*

* File located in `./sources/display/prompt.c` can be read easily as:
    > A file used to display prompt

* File located in `./sources/display/builtins/cd.c` can be read easily as:
    > A file used to display the builtin cd

### b - Project architecture
The architecture of have to be organized as the follwing tree.

```text
.
├── CONTRIBUTING.md
├── Makefile
├── README.md
├── includes
│   ├── types                           ✅  This folder is reserved for types
│   │   │                                   headers. This folder is normally symetric
│   │   │                                   with sources/types folder (1st level only)
│   │   │
│   │   ├── shell                       ✅  Reserved folder for shell type
│   │   │   ├── defs.h                  ✅  Reserved file to declare types and constants
│   │   │   │                               relative to shell type
│   │   │   └── shell.h                 ✅  Reserved file to declare all functions
│   │   │                                   relative to shell type
│   │   │                               ❌  Other file here is not really good
│   │   └── list
│   │       ├── defs.h
│   │       └── list.h
│   ├── display.h                       ✅  Reserved folder for sources/display
│   │                                       folder
│   └── ...                             👍  Here you can add other folders and sub folders
│                                           to orgnanize inclusions, but max sub folders
│                                           level is 2. Try to keep symetry with sources
│                                           folder.
├── sources
│   ├── main.c
│   ├── display                         ✅  Folder dedicated for all needed displays
│   │   ├── prompt.c                    ✅  File used to implement prompt display
│   │   │                                   with at least function display_prompt
│   │   │
│   │   └── builtins
│   │       └── cd.c                    ✅  File used to implement cd builtin display
│   │                                       with at least function display_builtin_cd
│   │
│   └── types                           ✅  This folder is reserved for types
│       │                                   implmementation. All functions and files
│       │                                   in this folder must not call functions outside
│       │                                   of types folder.
│       │
│       └── list                        ✅  Folder of a type
│       │   └── new.c                   ✅  File reserved to create a new instance
│       │   │                               of given type
│       │   └── free.c                  ✅  File reserved to create a free given instance
│       │   │                               of type
│       │   └── my_method.c             ✅  File used to create a pseudo-method associated
│       │                                   to current type
│       │
│       └── shell                       ✅  Folder dedicated to shell type (shell_t)
│       │   └── builtins                ✅  Sub-folder builtins that is not for a sub type
│       │   │   │                           but for sub-methods
│       │   │   ├── init.c              ✅  Sub method : shell_builtins_init
│       │   │   ├── builtins_remove.c   ❌  Bad group convention: useless prefix "builtins"
│       │   │   │                           name it remove.c instead
│       │   │   └── register.c          ✅  Sub method : shell_builtins_register
│       │   │
│       │   └── env                     ✅  Sub-folder bultins that is not a sub type
│       │       │                           but sub-methods
│       │       ├── get.c                   
│       │       ├── serialize.c             
│       │       ├── set.c               ✅  Sub methods : shell_env_set and shell_env_unset
│       │       │                           because theses sub methods are linked : unset
│       │       │                           is set to non-existant
│       │       ├── set_specials.c      ✅  Extension of set.c used to define particular
│       │       │                           cases
│       │       └── unserialize.c           
│       ├── create.c                    ❌  Bad group convention: new.c has to
│       │                                   be used instead
│       └── destroy.c                   ❌  Bad group convention: free.c has
│                                           to be used instead
└── tests
```

## 2 - Commits and Pull Requests
The group convention is to use emojis with a past tense in your commits message and in your pull requests too.

### a - Meaning of emojis
`✨` New global feature  
`🔨` Utils functions  
`💡` Display functions  
`📑` Files functions  
`📒` Types functions  
`⚡️`  Optimisation / Performance  
`🏗️` Code architecture  
`🍱` Assets  
`✅` Tests  
`🚚` Files structure / File rename  
`📦` Library  
`🙈` Gitignore  
`🍌` Coding-style  
`🏷️` Header definition  
`📝` Makefile / CMakeLists  
`👷‍♂️` CI Github Action  
`🐛` Simple fix  
`💚` Automation fix  
`🚑️` Hotfix  
`🔥` Remove file / function

### b - Commit syntax
```
[EMOJI] [Past tense verb] [Description]
```
*Examples :*
* > 🐛 Fixed parsing of arguments
* > 👷‍♂️ Added coding-style CI
* > ✅ Updated units tests of files functions (criterion)
* > 📦️ Updated my_str_to_word_array function


## 3 - Variables and types naming
An unified types and variable naming will allow us to keep our project clean and clear for all of us. All details of this sections are importants !

### a - Types
You have to declare your types in a C file header such the Epitech standard is imposing us.

A type in C have to be prototyped as follwing:

```c
// The type name has to end with letter t and have the letter t.
// We have to avoid the most possible abbreviations
// Name have to be prefixed by first letter of existant used type
//      -------
//      v     v
typedef union u_node_data {
    char *str;
} node_data_t;

typedef struct s_shell {
    char **env;
} env_t;
//    ^
// The type name has to end with letter t and have the letter t.
// We have to avoid the most possible abbreviations
```

Enumerations needs to be prefixed by at least 2 letters to identify clearly its values and theses letters must relate to enumeration name. All values must be in uppercase.

```c
// ST prefix is related to state_t (2 first letters of name)
typedef enum e_state {
    ST_LOADING,
    ST_VALID,
    ST_ERROR
} state_t;
```

### b - Multiple and single elements
Sometimes just add an `s` at the end of a name can do a big difference.

If you variable (not the type of it) contains several elements end it by an `s`. Otherwise leave it singular.

*Example*
```c
list_t *animals = list_new(); //Here there are several animals in current variable
node_t *animal = NULL;        //But here we have just one of them
```

It the same rule for the names that you give to your types. 

*Examples*

In the follwing exemple you must not set an `s` at the end of type name. In fact, you're defining a type that describe just one state at time. Even if the `enum` contains several values, the type is used to set just one state at time so you don't have to add `s`.

```c
typedef enum e_state {
    ST_LOADING,
    ST_VALID,
    ST_ERROR
} state_t;
```

In the follwing exemple you have to set an `s` at the end of type name because you're defining a type that contains several values in same time so you have to add an `s` at the end.

```c
typedef struct s_components {
    button_t *button_start;
    input_t *input_zone;
} components_t;
```

## 4 - Header files and preprocessor directives
### a - Header files
When you create a C header file you have first to follow the Epitech standard.

The header guard name needs to be like `<NAME>_H_`.

```c
#ifndef FILE_H_
    #define FILE_H_

#endif /* !FILE_H_ */
```

### b - Preprocessor directives
In your header you have to indent all preprocessor directives. A preprocessor directive is a line which start with `#` (`#include`, `#define`...).

Just after header guard definition, you have to add a break line. Preprocessor directives order is free, but all `#include` directives have to be placed first.

*Examples*

✅ Correct
```c
#ifndef FILE_H_
    #define FILE_H_

    #include <stdlib.h>

    #define ABS(x) (x < 0 ? -x : x)
    #define SQUARE(x) (x * x)

#endif /* !FILE_H_ */
```

❌ Incorrect
```c
#ifndef FILE_H_
    #define FILE_H_

    #include <stdlib.h>
    #define ABS(x) (x < 0 ? -x : x)
    #define SQUARE(x) (x * x)

#endif /* !FILE_H_ */

```

❌ Incorrect
```c
#ifndef FILE_H_
    #define FILE_H_

    #define ABS(x) (x < 0 ? -x : x)
    #define SQUARE(x) (x * x)

    #include <stdlib.h>

#endif /* !FILE_H_ */
```

### c - `#include` directive
When you're including headers, the inclusion order is:
* Inclusion from path (with chevrons : `<stdlib.h>`)
* Inclusion from own files (with quotes : `"my.h"`)
* Shortest directive at top

✅ Correct
```c
#ifndef MY_HEADER_H_
    #define MY_HEADER_H_

    #include <stdlib.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include "my.h"
    #include "cjson.h"

    #define ABS(x) (x < 0 ? -x : x)
    #define SQUARE(x) (x * x)

#endif /* !MY_HEADER_H_ */
```

✅ Correct
```c
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"
#include "types/list/defs.h"
```

❌ Incorrect
```c
#ifndef MY_HEADER_H_
    #define MY_HEADER_H_

    #include <sys/wait.h>
    #include <stdlib.h>
    #include "my.h"
    #include <sys/types.h>
    #include "cjson.h"

#endif /* !MY_HEADER_H_ */
```

### d - `#define` preprocessor directive naming
You have to name your macros and your defined values with the prefix of current context. This in order to avoid conflicts of naming.

*Examples*

* If you define the header guard of `includes/types/shell/shell.h` you have to name it : `SHELL_H_`
* If you define the header guard of `includes/types/shell/defs.h` you have to name it : `SHELL_DEFS_H_`.
* If you define the header guard of `includes/display.h` you have to name it : `DISPLAY_H_`
* If you define the header guard of `includes/display/builtins.h` you have to name it : `DISPLAY_BUILTINS_H_`
* If you define a macro in `includes/types/shell/defs.h` you have to name it : `SHELL_EXIT_CODE`.

### e - `#define` macros
You have to set macro on 2 lines maximum.

If your macros are variables based, you have to pass these variables as parameters of your macro and you must not hard code it with the variables names. In fact in different context your variables could be undefined.

*Example*

```c
    //❌ Incorrect
    #define LIST_NODE_ITEM node->next.data->item     //Will fail if node is undefined

    //✅ Correct
    #define LIST_NODE_ITEM(node) node->next.data->item
```

## 5 - Functions

### a - Returned value
In your C functions you can return any value. But in some cases the returned value is just an indicator to specify if an error occured.

- So in the most cases return value are `success` or `fail` and to indicate them you have to prototype your functions with returned type `bool`. In fact in order to make the developer read more easier we can use the created function in a pseudo-sentences like:

    ```c
    bool add_item(int e, list_t *list)
    {
        //...
        (void) e;
        (void) list;

        if (success) {
            return true; //No error occured
        } else {
            return false; //An error occured
        }
    }

    //✅ Good convention
    //Next statement could be easily read as 'If non item add' or 'If item not added' then...
    if (!add_item(3, NULL)) {
        printf("error during item adding\n");
    }

    //❌ Bad convention
    //Next statement can not be easily read : 'If item was added then error' => illogical
    if (add_item(3, NULL)) {
        printf("error during item adding\n");
    }

    ```
- But in some others cases the value of returned code is useful. Then in that case, on `success` you have to return `0` and all `errors` code can be described by other values :
    ```c
    #include <string.h>

    int display_check_data(char *data)
    {
        if (!data)
            return 1;           //To indicate that pointer is NULL (Error 1)
        if (strlen(data) == 0)
            return 2;           //To indicate data is too short (Error 2)
        return 0;               //To indicate success
    }

    //✅ Good convention
    int check_data_status = display_check_data("Hello");

    if (check_data_status == 1) {
        printf("NULL pointer given\n");
    } else if (check_data_status == 2) {
        printf("Too short data given\n");
    } else {
        printf("Valid data\n");
    }
    ```