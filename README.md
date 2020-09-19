# Powerline-cpp


![powerline-shell-cpp](https://github.com/Jrhenderson11/powerline-shell-cpp/blob/master/powerline.png "powerline-shell-cpp")

## Forked from: https://github.com/konradmiller/powerline-shell-cpp

## Intro:

I started using this as I was finding the python powerline-shell a bit too slow, see the following for a speed comparison:

**python version:**
```bash
time powerline-shell 

real    0m0.356s
user    0m0.296s
sys     0m0.066s
```

**cpp version:**
```bash
time powerline-shell-cpp

real    0m0.042s
user    0m0.021s
sys     0m0.018s
```

So in this case it is almost 10 times faster, although this varies.

Obviously this has a lot less features / segments than the python version, but still has the same aesthetic and core functionality.

## Installation:

To build:

`make`

Then you can copy the binary into your path e.g

`cp ./powerline-shell-cpp /usr/local/bin`

### BASH

To change your bash prompt: find the line in **~/.bashrc** setting 

`PS1=`

And replace with

```
    function _update_ps1() {
        PS1=$(powerline-shell-cpp $?)
    }

    if [[ $TERM != linux && ! $PROMPT_COMMAND =~ _update_ps1 ]]; then
        PROMPT_COMMAND="_update_ps1; $PROMPT_COMMAND"
    fi
```

And then `source ~/.bashrc` to reload.

I nicked this part from the original powershell so it's not my fault if it's broken ok.

### ZSH:

Make sure you compile with `-DSHELL=ZSH` in the makefile

Add this snippet to **~/.zshrc**

```
function powerline_precmd() {
    PS1="$(powerline-shell-cpp $?)"
}

function install_powerline_precmd() {
  for s in "${precmd_functions[@]}"; do
    if [ "$s" = "powerline_precmd" ]; then
      return
    fi
  done
  precmd_functions+=(powerline_precmd)
}

if [ "$TERM" != "linux" ]; then
    install_powerline_precmd
fi

```

### Note:

If you're editing anything in lib, you will need to do a `make clean` before `make`.

## Segments:

Cwd:

Prints the current path, also shortens it if in certain common directories and colours the output to show this.

Git:

Not as verbose as the default powerline-shell, which I don't mind because all that information could take a lot of space. I haven't done anything to this segment from the original fork.

Jobs:

if there are any background jobs show the number before the prompt. I liked this feature from the original powerline-shell so added it back in.

## What this doesn't have:

I didn't add in colouring the prompt based on success of last shell commands. If I miss it I might add it back in.

## Misc changes:

I changed the spelling of color to colour.

I fixed so escape characters are properly treated as 0 width chars dependent on SHELL macro
