#include <stdio.h>
static struct stack_frame
{
    unsigned int r0;
    unsigned int r1;
    unsigned int r2;
    unsigned int r3;
    unsigned int r12;
    unsigned int lr;
    unsigned int pc;
    unsigned int psr;
};

void print_regs(void *sp)
{
    struct stack_frame *contex = (struct stack_frame *)sp;
    printf("psr: 0x %08x\n", contex->psr);
    printf(" pc: 0x %08x\n", contex->pc);
    printf(" lr: 0x %08x\n", contex->lr);
    printf("r12: 0x %08x\n", contex->r12);
    printf("r03: 0x %08x\n", contex->r3);
    printf("r02: 0x %08x\n", contex->r2);
    printf("r01: 0x %08x\n", contex->r1);
    printf("r00: 0x %08x\n", contex->r0);
}

void isr_hardfault(void)
{
    __asm volatile(
        "	.syntax unified			\n"
        "	MRS     R0, PSP	        \n"
        "	PUSH    {LR}			\n"
        "	BL      print_regs      \n"
        "	POP     {PC}			\n"
        "							\n"
        "	.align 4				\n");
}

void traceMalloc(void* pvReturn, size_t xWantedSize) {
    printf("malloc %d bytes at %p\n", xWantedSize, pvReturn);
}
