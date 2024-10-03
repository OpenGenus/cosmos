; Author:   SYEED MOHD AMEEN 
; Email:    ameensyeed2@gmail.com

;----------------------------------------------------------------;
;                  LINEAR SEARCH SUBROUTINE                      ;
;----------------------------------------------------------------;




;----------------------------------------------------------------;
;                   FUNCTION PARAMETERS                          ;
;----------------------------------------------------------------;   
;   1.  push KEY element                                         ;
;   2.  push no. of element in Array                             ;
;   3.  push base address of Array                               ;
;----------------------------------------------------------------;

LINSEARCH:
    POP AX 
    POP SI                  ;BASE ADDRESS OF ARRAY  
    POP CX                  ;COUNTER REGISTER 
    POP DX                  ;KEY ELEMENT 
    PUSH AX 

REPEAT_LINSEARCH:
    CMP DH,[SI]             ;COMPARE KEY == [SI]
    JNE NOTFOUND    
        POP AX              ;IF ELEMENT FOUND RETURN ADDRESS 
        PUSH SI     
        PUSH AX     
        RET                 ;RETURN SUBROUTINE 
    NOTFOUND:
    INC SI 
    LOOP REPEAT_LINSEARCH

    POP AX                  ;IF SEARCH UNSUCESSFUL RETURN 0X0000 
    MOV CX,0X0000
    PUSH CX
    PUSH AX 
    RET 
