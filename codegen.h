/**
 * codegen.h - Gerador de código assembly para CafeMachine VM
 */

#ifndef CODEGEN_H
#define CODEGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *output_file;

// Contador de labels únicos
static int label_counter = 0;
static int temp_var_counter = 0;

// Tabela de símbolos simplificada
#define MAX_VARS 100
typedef struct {
    char name[64];
    int offset;  // offset na pilha ou registrador
} Variable;

static Variable symbol_table[MAX_VARS];
static int symbol_count = 0;

// Funções auxiliares
static int new_label() {
    return label_counter++;
}

static int new_temp() {
    return temp_var_counter++;
}

static void emit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(output_file, fmt, args);
    va_end(args);
}

static void emit_label(const char *label) {
    fprintf(output_file, "%s:\n", label);
}

static void emit_comment(const char *comment) {
    fprintf(output_file, "; %s\n", comment);
}

// Variáveis e registradores
static void emit_set(const char *reg, double value) {
    fprintf(output_file, "SET %s %.2f\n", reg, value);
}

static void emit_load_sensor(const char *reg, const char *sensor) {
    fprintf(output_file, "LOAD %s %s\n", reg, sensor);
}

// Operações aritméticas
static void emit_add(const char *dest, const char *src) {
    fprintf(output_file, "ADD %s %s\n", dest, src);
}

static void emit_sub(const char *dest, const char *src) {
    fprintf(output_file, "SUB %s %s\n", dest, src);
}

static void emit_mul(const char *dest, const char *src) {
    fprintf(output_file, "MUL %s %s\n", dest, src);
}

static void emit_div(const char *dest, const char *src) {
    fprintf(output_file, "DIV %s %s\n", dest, src);
}

static void emit_inc(const char *reg) {
    fprintf(output_file, "INC %s\n", reg);
}

static void emit_dec(const char *reg) {
    fprintf(output_file, "DEC %s\n", reg);
}

// Comparações
static void emit_cmp(const char *reg1, const char *reg2) {
    fprintf(output_file, "CMP %s %s\n", reg1, reg2);
}

// Jumps
static void emit_goto(const char *label) {
    fprintf(output_file, "GOTO %s\n", label);
}

static void emit_je(const char *label) {
    fprintf(output_file, "JE %s\n", label);
}

static void emit_jne(const char *label) {
    fprintf(output_file, "JNE %s\n", label);
}

static void emit_jl(const char *label) {
    fprintf(output_file, "JL %s\n", label);
}

static void emit_jg(const char *label) {
    fprintf(output_file, "JG %s\n", label);
}

static void emit_jle(const char *label) {
    fprintf(output_file, "JLE %s\n", label);
}

static void emit_jge(const char *label) {
    fprintf(output_file, "JGE %s\n", label);
}

static void emit_decjz(const char *reg, const char *label) {
    fprintf(output_file, "DECJZ %s %s\n", reg, label);
}

// Pilha
static void emit_push(const char *reg) {
    fprintf(output_file, "PUSH %s\n", reg);
}

static void emit_pop(const char *reg) {
    fprintf(output_file, "POP %s\n", reg);
}

// Ações
static void emit_action(const char *action, const char *args) {
    if (args && strlen(args) > 0) {
        fprintf(output_file, "ACTION %s %s\n", action, args);
    } else {
        fprintf(output_file, "ACTION %s\n", action);
    }
}

static void emit_beep() {
    fprintf(output_file, "BEEP\n");
}

static void emit_print(const char *reg) {
    fprintf(output_file, "PRINT %s\n", reg);
}

static void emit_halt() {
    fprintf(output_file, "HALT\n");
}

// Mapeamento de sensores
static const char* map_sensor(const char *sensor_name) {
    if (strcmp(sensor_name, "temp") == 0) return "TEMP";
    if (strcmp(sensor_name, "pressao") == 0) return "PRESSURE";
    if (strcmp(sensor_name, "agua") == 0) return "WATER_LEVEL";
    if (strcmp(sensor_name, "graos") == 0) return "BEAN_LEVEL";
    if (strcmp(sensor_name, "fluxo") == 0) return "FLOW_RATE";
    if (strcmp(sensor_name, "copo") == 0) return "CUP_PRESENT";
    if (strcmp(sensor_name, "porta") == 0) return "DOOR_OPEN";
    return "UNKNOWN";
}

// Tabela de símbolos
static int find_variable(const char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

static int add_variable(const char *name) {
    if (symbol_count >= MAX_VARS) {
        fprintf(stderr, "Erro: tabela de símbolos cheia\n");
        return -1;
    }
    strncpy(symbol_table[symbol_count].name, name, 63);
    symbol_table[symbol_count].offset = symbol_count;
    return symbol_count++;
}

#endif // CODEGEN_H
