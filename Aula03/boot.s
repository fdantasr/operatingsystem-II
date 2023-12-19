.global _start

.equ STACK_SIZE, 4096 #0x1000
# mhartid é o rreg. que contém o ID da CPU

_start:
csrr t0, mhartid # Copia o ID da CPU para t0
bnez t0, park # t0 é igual a zero? Se sim, salta para park

la sp, stack_end #sp <= stack_end

j entry # pula pra entry

park:
    wfi
    j park
.skip STACK_SIZE
stack_end:
