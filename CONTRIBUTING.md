# Welcome on 42sh project !

Contribute to this Epitech project involves following strict rules to keep a clean project and easily maintainable code.

* [1 - Project architecture and file naming](#1---project-architecture-and-file-naming)
* [2 - Commits and Pull Requests](#2---commits-and-pull-requests)
* [3 - Variables and types naming](#3---variables-and-types-naming)

## 1 - Project architecture and file naming
Files conventions naming and project architecture need to be followed.

### Files and folders naming
Files and folders names must be short and readable by architecure depth level.

*Exemples*

* File located in `./sources/display/prompt.c` can be read easily as:
    > A file used to display prompt

* File located in `./sources/display/builtins/cd.c` can be read easily as:
    > A file used to display the builtin cd

### Project architecture
The architecture of have to be organized as the follwing tree.

```text
.
├── CONTRIBUTING.md
├── Makefile
├── README.md
├── includes
├── sources
│   ├── main.c
|   ├── display                         ✅  Folder dedicated for all needed displays
|   |   ├── prompt.c                    ✅  File used to implement prompt display
|   |   |                                   with at least function display_prompt
|   |   |
|   |   └── builtins
|   |       └── cd.c                    ✅  File used to implement cd builtin display
|   |                                       with at least function display_builtin_cd
|   |
│   └── types                           ✅  This folder is reserved for types
│       │                                   implmementation. All functions and files
|       |                                   in this folder must not call functions outside
|       |                                   of types folder.
|       |
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

### Meaning of emojis
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

### Commit syntax
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

### Types
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

### Multiple and single elements
Sometimes just add an `s` at the end of a name can do a big difference.

If you variable (not the type of it) contains several elements end it by an `s`. Otherwise leave it singular.

*Exemple*
```c
list_t *animals = list_new(); //Here there are several animals in current variable
node_t *animal = NULL;        //But here we have just one of them
```

It the same in the names that you give to your types. 

*Exemples*

❌ In the follwing exemple you must not set an `s` at the end of type name. In fact, you're defining a type that describe just one state at time. Even if the `enum` contains several values, the type is used to set just one state at time so you don't have to add `s`.

```c
typedef enum e_state {
    ST_LOADING,
    ST_VALID,
    ST_ERROR
} state_t;
```

✅ In the follwing exemple you have to set an `s` at the end of type name because you're defining a type that contains several values in same time so you have to add an `s` at the end.

```c
typedef struct s_components {
    button_t *button_start;
    input_t *input_zone;
} components_t;
```
