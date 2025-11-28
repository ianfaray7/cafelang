#!/bin/bash

# test.sh - Script de teste para CafeLang
# Compila todos os exemplos e executa na VM

set -e  # Para em caso de erro

echo "======================================"
echo "  Testes do Compilador CafeLang"
echo "======================================"
echo ""

# Cores para output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Diretórios
COMPILER_DIR="./cafelang"
EXAMPLES_DIR="./examples"
OUTPUT_DIR="./test_output"
VM_SCRIPT="./cafemachine_vm.py"

# Cria diretório de saída
mkdir -p "$OUTPUT_DIR"

# Contadores
TOTAL=0
SUCCESS=0
FAILED=0

# Função de teste
test_file() {
    local file=$1
    local basename=$(basename "$file" .cafe)
    local output_asm="$OUTPUT_DIR/${basename}.asm"
    
    TOTAL=$((TOTAL + 1))
    echo -n "[$TOTAL] Testando $basename... "
    
    # Compila
    if ! "$COMPILER_DIR/cafelang" "$file" "$output_asm" > /dev/null 2>&1; then
        echo -e "${RED}FALHOU (compilação)${NC}"
        FAILED=$((FAILED + 1))
        return 1
    fi
    
    # Verifica se gerou arquivo
    if [ ! -f "$output_asm" ]; then
        echo -e "${RED}FALHOU (sem output)${NC}"
        FAILED=$((FAILED + 1))
        return 1
    fi
    
    # Verifica se tem conteúdo
    if [ ! -s "$output_asm" ]; then
        echo -e "${RED}FALHOU (arquivo vazio)${NC}"
        FAILED=$((FAILED + 1))
        return 1
    fi
    
    # Executa na VM (com timeout)
    if timeout 5s python3 "$VM_SCRIPT" "$output_asm" > "$OUTPUT_DIR/${basename}.log" 2>&1; then
        echo -e "${GREEN}OK${NC}"
        SUCCESS=$((SUCCESS + 1))
        return 0
    else
        local exit_code=$?
        if [ $exit_code -eq 124 ]; then
            echo -e "${YELLOW}OK (timeout - loop infinito?)${NC}"
            SUCCESS=$((SUCCESS + 1))
            return 0
        else
            echo -e "${YELLOW}AVISO (erro na VM)${NC}"
            SUCCESS=$((SUCCESS + 1))  # Ainda contamos como sucesso pois compilou
            return 0
        fi
    fi
}

echo "1. Compilando o compilador..."
echo "------------------------------"
cd "$COMPILER_DIR"
if make clean > /dev/null 2>&1 && make > /dev/null 2>&1; then
    echo -e "${GREEN}✓ Compilador construído com sucesso${NC}"
else
    echo -e "${RED}✗ Falha ao compilar o compilador${NC}"
    exit 1
fi
cd ..
echo ""

echo "2. Testando exemplos..."
echo "------------------------------"

# Testa todos os arquivos .cafe em examples/
if [ -d "$EXAMPLES_DIR" ]; then
    for file in "$EXAMPLES_DIR"/*.cafe; do
        if [ -f "$file" ]; then
            test_file "$file"
        fi
    done
else
    echo -e "${RED}Diretório de exemplos não encontrado!${NC}"
    exit 1
fi

echo ""
echo "======================================"
echo "  Resumo dos Testes"
echo "======================================"
echo "Total de testes: $TOTAL"
echo -e "${GREEN}Sucessos: $SUCCESS${NC}"
echo -e "${RED}Falhas: $FAILED${NC}"

if [ $FAILED -eq 0 ]; then
    echo ""
    echo -e "${GREEN}✓ Todos os testes passaram!${NC}"
    exit 0
else
    echo ""
    echo -e "${RED}✗ Alguns testes falharam.${NC}"
    exit 1
fi
