#ifndef _SYS_MCONTEXT_H_
#define _SYS_MCONTEXT_H_

#include <sys/types.h>

typedef uint32_t greg_t;
#define NGREG 16
typedef greg_t gregset_t[NGREG];

enum
{
  REG_GS = 0,
# define REG_GS     REG_GS
  REG_FS,
# define REG_FS     REG_FS
  REG_ES,
# define REG_ES     REG_ES
  REG_DS,
# define REG_DS     REG_DS
  REG_EDI,
# define REG_EDI    REG_EDI
  REG_ESI,
# define REG_ESI    REG_ESI
  REG_EBP,
# define REG_EBP    REG_EBP
  REG_ESP,
# define REG_ESP    REG_ESP
  REG_EBX,
# define REG_EBX    REG_EBX
  REG_EDX,
# define REG_EDX    REG_EDX
  REG_ECX,
# define REG_ECX    REG_ECX
  REG_EAX,
# define REG_EAX    REG_EAX
  REG_EIP,
# define REG_EIP    REG_EIP
  REG_CS,
# define REG_CS     REG_CS
  REG_EFL,
# define REG_EFL    REG_EFL
  REG_SS
# define REG_SS REG_SS
};

typedef struct {
    gregset_t gregs;
} mcontext_t;

#endif
