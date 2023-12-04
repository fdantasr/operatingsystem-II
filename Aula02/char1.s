.section .text
.global secondChar, anyChar

secondChar:
  lb a0, 0(a0) #load byte 0(a0)  # carrega o byte no offset 0 -> 0(a0)
  ret

anyChar:
  lb a0, 2(a0) #load byte 0(a0) # carrega o byte no offset 2 -> 2(a0)
  ret

