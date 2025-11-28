; Código assembly gerado pelo compilador CafeLang
; Análise sintática concluída com sucesso

; sensor read: porta
LOAD TEMP DOOR_OPEN
; sensor read: copo
LOAD TEMP CUP_PRESENT
; if statement
SET R0 0
CMP TEMP R0
JE L0
; Acao com argumentos
L0:
; push number 18.00
; variable declaration with init: dose
SET R0 18.00
; Acao com argumentos
; Acao com argumentos
; Acao com argumentos
; Acao com argumentos
; Acao com argumentos
; === Fim da receita ===
; Acao com argumentos

; Fim do programa
HALT

; Programa analisado sem erros
