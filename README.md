# Powerline-cpp

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
sys	    0m0.018s
```

So in this case it is almost 10 times faster, although this varies.

Obviously this has a lot less features / segments than the python version, but still has the same aesthetic and core functionality.

## Segments:

Cwd:

Prints the current path, also shortens it if in certain common directories and colours the output to show this.

Git:

Not as verbose as the default powerline-shell, which I don't mind because all that information could take a lot of space. I haven't done anything to this segment from the original fork.

Jobs:

if there are any background jobs show the number before the prompt. I liked this feature from the original powerline-shell so added it back in.

## What this doesn't have:

I didn't add in colouring the prompt based on success of last shell command as it was quite fiddly to get right. If I miss it I might add it back in.

## Misc changes:

I changed the spelling of color to colour.
