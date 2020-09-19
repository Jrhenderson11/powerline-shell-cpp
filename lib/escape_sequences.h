#ifndef ESCAPE_SEQUENCES_H__
#define ESCAPE_SEQUENCES_H__

#define BASH 0
#define ZSH 1

#ifndef SHELL
	#define SHELL ZSH
#endif


#if SHELL==BASH
	#define START_ESCAPE "\\[\\"
	#define END_ESCAPE "\\]"
#elif SHELL==ZSH
	#define START_ESCAPE "%{"
	#define END_ESCAPE "%}"
#else
	#error "SHELL must be BASH or ZSH"
#endif

#endif //ESCAPE_SEQUENCES_H__