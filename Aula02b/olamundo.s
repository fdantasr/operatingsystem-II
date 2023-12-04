.section .text
.global _start #Definir o label _start como global

_start: #Função para iniciar o programa em assembly.
#Informar ao Sistema que queremos executar a função write
    li a7, 64 #Carrega o valor 4 no registrador a7. 
    #Preparare os argumentos para a função write
    li a0, 1 #Descritor de arquivo da saída padrão (stdout)
    la a1, msg #Endereço da string a ser impressa
    li a2, 13 #Define o tamanho da string a ser impressa
    ecall #Intrução chamar o sistema operacional

#terminar a execução do programa com a chamada de sistema exit
# exit(0) 

finaliza:
    li a7, 93 #10 é o código da chamada de sistema para sair (exit)
    li a0 , 0  #Carrega a saída do programa com o valor 0
    ecall

msg: #Definir um label para o endereço da string
    .ascii "Hello World\n" #Definir uma string com o texto Hello World (Diretiva)
