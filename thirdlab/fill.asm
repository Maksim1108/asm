.686
.model FLAT, C
INCLUDELIB msvcrt.lib
time    proto c ,:dword
srand   proto c ,:dword
rand    proto c 
.data
    arraySize dd 0

.code
fillArray proc
    push ebp
    mov ebp, esp
    push edi
    push esi
    push ebx

    ; Set up the arguments
    mov ebx, [ebp+8] ; arraySize
    mov esi, [ebp+12] ; initialArray

    ; Initialize random seed
    push 0
    call time
    add esp, 4
    push eax
    call srand
    add esp, 4

    ; Loop over the array
    xor edi, edi ; i = 0
    loop_start:
        cmp edi, ebx ; Compare i with arraySize
        jge loop_end ; If i >= arraySize, exit loop

        ; Generate random number
        call rand
        mov edx, eax ; Store rand() result in edx
        mov eax, edx
        cdq
        mov ecx, 101
        idiv ecx ; Divide edx:eax by 101
        mov eax, edx ; Move remainder to eax
        sub eax, 50 ; randomNumber = (rand() % 101) - 50

        ; Store randomNumber in initialArray[i]
        mov [esi + edi*4], eax

        ; Increment i
        inc edi
        jmp loop_start
    loop_end:

    ; Return initialArray
    mov eax, esi

    ; Restore registers and return
    pop ebx
    pop esi
    pop edi
    pop ebp
    ret
    fillArray endp
END