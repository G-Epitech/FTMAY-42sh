# Welcome on 42sh project !

Contribute to this Epitech project involves following strict rules to keep a clean project and easily maintainable code.

## 1 - Project architecture and file naming
Files conventions naming and project architecture need to be followed.

### Files and folders naming
---
Files and folders names must be short and readable by architecure depth level.

**Exemple**

File located in `./sources/display/prompt.c` can be read easily as:
> A file used to display prompt

File located in `./sources/display/builtins/cd.c` can be read easily as:
> A file used to display the builtin cd

### Project architecture
---
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