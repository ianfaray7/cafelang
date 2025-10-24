# Makefile para compilar CafeLang com Flex e Bison

CC = gcc
CFLAGS = -Wall -g
FLEX = flex
BISON = bison

TARGET = cafelang
LEX_FILE = cafelang.l
YACC_FILE = cafelang.y

LEX_OUTPUT = lex.yy.c
YACC_OUTPUT = cafelang.tab.c
YACC_HEADER = cafelang.tab.h

OBJECTS = $(YACC_OUTPUT:.c=.o) $(LEX_OUTPUT:.c=.o)

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -lfl

$(YACC_OUTPUT) $(YACC_HEADER): $(YACC_FILE)
	$(BISON) -d -v $<

$(LEX_OUTPUT): $(LEX_FILE) $(YACC_HEADER)
	$(FLEX) $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS) $(LEX_OUTPUT) $(YACC_OUTPUT) $(YACC_HEADER)
	rm -f *.o output.asm *.output

test: $(TARGET)
	@echo "======================================"
	@echo "Testando compilador CafeLang"
	@echo "======================================"
	@echo "\n1. Testando exemplo simples..."
	@./$(TARGET) exemplo_simples.cafe output.asm && echo "✓ Teste passou!" || echo "✗ Teste falhou!"
	@echo "\n2. Conteúdo do arquivo gerado:"
	@cat output.asm
	@echo "\n======================================"
	@echo "Testes concluídos!"
	@echo "======================================"

help:
	@echo "CafeLang Compiler - Makefile"
	@echo "=============================="
	@echo "Uso:"
	@echo "  make          - Compila o compilador"
	@echo "  make clean    - Remove arquivos gerados"
	@echo "  make test     - Compila e testa com exemplo.cafe"
	@echo "  make help     - Mostra esta mensagem"
	@echo ""
	@echo "Para usar o compilador:"
	@echo "  ./cafelang <arquivo_entrada.cafe> [arquivo_saida.asm]"
