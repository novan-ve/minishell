# minishell
Custom shell written in C, based on Bash.

![Example](https://raw.githubusercontent.com/novan-ve/minishell/master/screenshots/example.png)

## Usage
```
make
./minishell
```

## Builtins
  - echo
  - cd
  - pwd
  - export
  - unset
  - env
  - exit

## Supports
  - Semicolon `;` to seperate commands
  - Single quotes `'` and double quotes `"`
  - Redirections `< > >>`
  - Pipes `|`
  - Environment variables
  - Return values of commands `$?`
  - ctrl-C, ctrl-D and ctrl-\
