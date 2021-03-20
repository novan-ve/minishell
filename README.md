# minishell
The objective of this project is to create a simple shell, based on bash.

![Example](https://raw.githubusercontent.com/novan-ve/minishell/master/screenshots/example.png)

The following builtins have been reimplemented:
  - echo
  - cd
  - pwd
  - export
  - unset
  - env
  - exit

It supports:
  - Semicolon `;` to seperate commands
  - Single quotes `'` and double quotes `"`
  - Redirections `< > >>`
  - Pipes `|`
  - Environment variables
  - Return values of commands `$?`
  - ctrl-C, ctrl-D and ctrl-\
