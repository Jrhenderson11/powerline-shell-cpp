#ifndef ESCAPE_SEQUENCES_H__
#define ESCAPE_SEQUENCES_H__


#ifndef SHELL
	#define SHELL BASH
#endif


#if SHELL == BASH
	#define START_ESCAPE "\\[\\e"
	#define END_ESCAPE "\\]"
#elif SHELL == ZSH
	#define START_ESCAPE "%{\e"
	#define END_ESCAPE "%}"
#else
	#error "SHELL must be BASH or ZSH"
#endif

#endif //ESCAPE_SEQUENCES_H__