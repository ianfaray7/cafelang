#!/usr/bin/env python3
"""
CafeMachine VM - Máquina Virtual para CafeLang
Inspirada na MicrowaveVM, adaptada para máquinas de café expresso.

Arquitetura Turing-completa com:
- 2+ registradores (TEMP, POWER, VOLUME, TIME)
- Memória (pilha)
- Sensores readonly (WATER_LEVEL, BEAN_LEVEL, CUP_PRESENT, DOOR_OPEN, PRESSURE)
- Instruções de controle de fluxo (GOTO, DECJZ) = Turing-completo
"""

from dataclasses import dataclass
from typing import List, Dict, Tuple, Optional
import sys

Register = str

@dataclass
class Instr:
    """Representa uma instrução da VM"""
    op: str
    args: Tuple[str, ...]  # argumentos como strings

class CafeMachineVM:
    """
    Máquina Virtual para simular uma máquina de café expresso.
    
    Conjunto de instruções (Turing-completo):
      SET R n           ; inicializa registrador
      INC R             ; R := R + 1
      DEC R             ; R := R - 1
      DECJZ R label     ; if R == 0: PC := label, else: R := R - 1
      GOTO label        ; PC := label
      PRINT R           ; imprime valor do registrador
      PUSH R            ; empilha valor do registrador
      POP R             ; desempilha para o registrador
      ADD R1 R2         ; R1 := R1 + R2
      SUB R1 R2         ; R1 := R1 - R2
      MUL R1 R2         ; R1 := R1 * R2
      DIV R1 R2         ; R1 := R1 / R2
      MOD R1 R2         ; R1 := R1 % R2
      CMP R1 R2         ; compara R1 e R2, define FLAGS
      JE label          ; jump if equal (baseado em FLAGS)
      JNE label         ; jump if not equal
      JL label          ; jump if less
      JG label          ; jump if greater
      JLE label         ; jump if less or equal
      JGE label         ; jump if greater or equal
      LOAD R SENSOR     ; carrega valor do sensor para registrador
      ACTION name args  ; executa ação da máquina de café
      BEEP              ; emite som
      HALT              ; para execução

    Labels:
      label_name:       ; define destino para jumps
    """

    def __init__(self):
        # Registradores de propósito geral
        self.registers: Dict[Register, float] = {
            "TEMP": 25.0,      # Temperatura atual em °C
            "POWER": 0.0,      # Potência da resistência (0-100)
            "VOLUME": 0.0,     # Volume de água em ml
            "TIME": 0.0,       # Tempo em segundos
            "R0": 0.0,         # Registradores auxiliares
            "R1": 0.0,
            "R2": 0.0,
            "R3": 0.0,
        }
        
        # Sensores somente leitura
        self.sensors: Dict[str, float] = {
            "TEMP_SENSOR": 25.0,     # Sensor de temperatura em °C
            "WATER_LEVEL": 1000.0,   # Nível de água em ml
            "BEAN_LEVEL": 500.0,     # Nível de grãos em g
            "CUP_PRESENT": 1.0,      # 1=presente, 0=ausente
            "DOOR_OPEN": 0.0,        # 1=aberta, 0=fechada
            "PRESSURE": 0.0,         # Pressão em bar
            "FLOW_RATE": 0.0,        # Taxa de fluxo em ml/s
        }
        
        self.program: List[Instr] = []
        self.labels: Dict[str, int] = {}
        self.pc: int = 0
        self.halted: bool = False
        self.steps: int = 0
        self.stack: List[float] = []
        self.flags: Dict[str, bool] = {
            "EQ": False,  # Equal
            "LT": False,  # Less than
            "GT": False,  # Greater than
        }
        
        # Log de ações executadas
        self.action_log: List[str] = []

    def load_program(self, source: str):
        """Carrega programa assembly na VM"""
        self.program.clear()
        self.labels.clear()
        self.stack.clear()
        self.pc = 0
        self.halted = False
        self.steps = 0
        self.action_log.clear()
        
        # Reset registradores
        self.registers = {k: 0.0 for k in self.registers.keys()}
        self.registers["TEMP"] = 25.0  # Temperatura ambiente
        
        lines = source.splitlines()
        
        # Primeira passagem: coletar labels
        idx = 0
        for raw in lines:
            line = raw.split(';', 1)[0].split('#', 1)[0].strip()
            if not line:
                continue
            if line.endswith(':'):
                label = line[:-1].strip()
                if not label:
                    raise ValueError("Label vazio.")
                if label in self.labels:
                    raise ValueError(f"Label duplicado: {label}")
                self.labels[label] = idx
            else:
                idx += 1
        
        # Segunda passagem: parse de instruções
        for raw in lines:
            line = raw.split(';', 1)[0].split('#', 1)[0].strip()
            if not line or line.endswith(':'):
                continue
            
            tokens = line.replace(',', ' ').split()
            if not tokens:
                continue
                
            op = tokens[0].upper()
            args = tuple(tokens[1:])
            
            # Validação básica
            self._validate_instruction(op, args, line)
            self.program.append(Instr(op, args))

    def _validate_instruction(self, op: str, args: Tuple[str, ...], line: str):
        """Valida sintaxe da instrução"""
        valid_regs = set(self.registers.keys())
        valid_sensors = set(self.sensors.keys())
        
        if op == "SET":
            if len(args) != 2 or args[0].upper() not in valid_regs:
                raise ValueError(f"SET espera registro e valor: {line}")
        elif op in ("INC", "DEC", "PRINT", "PUSH", "POP"):
            if len(args) != 1 or args[0].upper() not in valid_regs:
                raise ValueError(f"{op} espera 1 registro válido: {line}")
        elif op in ("ADD", "SUB", "MUL", "DIV", "MOD", "CMP"):
            if len(args) != 2:
                raise ValueError(f"{op} espera 2 registradores: {line}")
        elif op in ("DECJZ", "JE", "JNE", "JL", "JG", "JLE", "JGE", "GOTO"):
            if len(args) < 1:
                raise ValueError(f"{op} espera label: {line}")
        elif op == "LOAD":
            if len(args) != 2 or args[0].upper() not in valid_regs or args[1].upper() not in valid_sensors:
                raise ValueError(f"LOAD espera registro e sensor: {line}")
        elif op in ("ACTION", "BEEP", "HALT"):
            pass  # Validação flexível
        else:
            raise ValueError(f"Instrução desconhecida: {op}")

    def step(self):
        """Executa uma instrução"""
        if self.halted:
            return
        
        if not (0 <= self.pc < len(self.program)):
            self.halted = True
            return
        
        instr = self.program[self.pc]
        self.steps += 1
        
        def regname(s: str) -> str:
            return s.upper()
        
        def get_value(s: str) -> float:
            """Retorna valor numérico ou de registrador"""
            try:
                return float(s)
            except ValueError:
                return self.registers.get(s.upper(), 0.0)
        
        # Execução das instruções
        if instr.op == "SET":
            r, v = regname(instr.args[0]), get_value(instr.args[1])
            self.registers[r] = v
            self.pc += 1
        
        elif instr.op == "INC":
            r = regname(instr.args[0])
            self.registers[r] = self.registers.get(r, 0.0) + 1
            self.pc += 1
        
        elif instr.op == "DEC":
            r = regname(instr.args[0])
            self.registers[r] = self.registers.get(r, 0.0) - 1
            self.pc += 1
        
        elif instr.op == "DECJZ":
            r = regname(instr.args[0])
            target = instr.args[1]
            if self.registers.get(r, 0.0) == 0:
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.registers[r] -= 1
                self.pc += 1
        
        elif instr.op == "GOTO":
            target = instr.args[0]
            if target not in self.labels:
                raise ValueError(f"Label desconhecido: {target}")
            self.pc = self.labels[target]
        
        elif instr.op == "PRINT":
            r = regname(instr.args[0])
            value = self.registers.get(r, 0.0)
            print(f"{r}: {value}")
            self.pc += 1
        
        elif instr.op == "PUSH":
            r = regname(instr.args[0])
            value = self.registers.get(r, 0.0)
            self.stack.append(value)
            self.pc += 1
        
        elif instr.op == "POP":
            r = regname(instr.args[0])
            if not self.stack:
                raise RuntimeError("Não é possível fazer POP de pilha vazia")
            value = self.stack.pop()
            self.registers[r] = value
            self.pc += 1
        
        elif instr.op == "ADD":
            r1, r2 = regname(instr.args[0]), regname(instr.args[1])
            self.registers[r1] += self.registers.get(r2, 0.0)
            self.pc += 1
        
        elif instr.op == "SUB":
            r1, r2 = regname(instr.args[0]), regname(instr.args[1])
            self.registers[r1] -= self.registers.get(r2, 0.0)
            self.pc += 1
        
        elif instr.op == "MUL":
            r1, r2 = regname(instr.args[0]), regname(instr.args[1])
            self.registers[r1] *= self.registers.get(r2, 0.0)
            self.pc += 1
        
        elif instr.op == "DIV":
            r1, r2 = regname(instr.args[0]), regname(instr.args[1])
            r2_val = self.registers.get(r2, 0.0)
            if r2_val == 0:
                raise RuntimeError("Divisão por zero")
            self.registers[r1] /= r2_val
            self.pc += 1
        
        elif instr.op == "MOD":
            r1, r2 = regname(instr.args[0]), regname(instr.args[1])
            self.registers[r1] %= self.registers.get(r2, 1.0)
            self.pc += 1
        
        elif instr.op == "CMP":
            r1, r2 = regname(instr.args[0]), regname(instr.args[1])
            v1 = self.registers.get(r1, 0.0)
            v2 = self.registers.get(r2, 0.0)
            self.flags["EQ"] = (v1 == v2)
            self.flags["LT"] = (v1 < v2)
            self.flags["GT"] = (v1 > v2)
            self.pc += 1
        
        elif instr.op == "JE":
            target = instr.args[0]
            if self.flags.get("EQ", False):
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.pc += 1
        
        elif instr.op == "JNE":
            target = instr.args[0]
            if not self.flags.get("EQ", False):
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.pc += 1
        
        elif instr.op == "JL":
            target = instr.args[0]
            if self.flags.get("LT", False):
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.pc += 1
        
        elif instr.op == "JG":
            target = instr.args[0]
            if self.flags.get("GT", False):
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.pc += 1
        
        elif instr.op == "JLE":
            target = instr.args[0]
            if self.flags.get("EQ", False) or self.flags.get("LT", False):
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.pc += 1
        
        elif instr.op == "JGE":
            target = instr.args[0]
            if self.flags.get("EQ", False) or self.flags.get("GT", False):
                if target not in self.labels:
                    raise ValueError(f"Label desconhecido: {target}")
                self.pc = self.labels[target]
            else:
                self.pc += 1
        
        elif instr.op == "LOAD":
            r = regname(instr.args[0])
            sensor = instr.args[1].upper()
            if sensor not in self.sensors:
                raise ValueError(f"Sensor desconhecido: {sensor}")
            self.registers[r] = self.sensors[sensor]
            self.pc += 1
        
        elif instr.op == "ACTION":
            action_name = instr.args[0] if instr.args else "unknown"
            action_args = instr.args[1:] if len(instr.args) > 1 else ()
            action_str = f"{action_name}({', '.join(action_args)})"
            self.action_log.append(action_str)
            print(f"[ACTION] {action_str}")
            self.pc += 1
        
        elif instr.op == "BEEP":
            self.action_log.append("BEEP")
            print("BEEEEEEP!")
            self.pc += 1
        
        elif instr.op == "HALT":
            print("=== PROGRAMA FINALIZADO ===")
            self.halted = True

    def run(self, max_steps: Optional[int] = 10000):
        """Executa o programa até HALT ou limite de passos"""
        while not self.halted:
            if max_steps is not None and self.steps >= max_steps:
                raise RuntimeError("Limite de passos atingido (possível loop infinito)")
            self.step()

    def state(self) -> Dict[str, float]:
        """Retorna estado dos registradores"""
        return dict(self.registers)

    def full_state(self) -> Dict:
        """Retorna estado completo da VM"""
        return {
            "registers": dict(self.registers),
            "sensors": dict(self.sensors),
            "stack": list(self.stack),
            "pc": self.pc,
            "halted": self.halted,
            "steps": self.steps,
            "flags": dict(self.flags),
            "actions": list(self.action_log),
        }

    def set_sensor(self, sensor: str, value: float):
        """Define valor de um sensor (para simulação)"""
        sensor = sensor.upper()
        if sensor in self.sensors:
            self.sensors[sensor] = value
        else:
            raise ValueError(f"Sensor desconhecido: {sensor}")


# ========== Programas de demonstração ==========

# Programa 1: Adição simples (a + b)
ADD_PROGRAM = """
; Soma dois números
; Pre: TEMP=a, POWER=b
; Post: TEMP=a+b, POWER=0

loop:
    DECJZ POWER end
    INC TEMP
    GOTO loop
end:
    PRINT TEMP
    HALT
"""

# Programa 2: Multiplicação (a * b)
MULT_PROGRAM = """
; Multiplica TEMP * POWER
; Resultado em R0

SET R0 0            ; resultado = 0
SET R1 TEMP         ; copia multiplicando para R1

mult_loop:
    DECJZ POWER mult_end
    
    ; Adiciona R1 ao resultado
    SET R2 R1
add_loop:
    DECJZ R2 add_end
    INC R0
    GOTO add_loop
add_end:
    GOTO mult_loop

mult_end:
    PRINT R0
    HALT
"""

# Programa 3: Uso de pilha
STACK_PROGRAM = """
; Demonstra operações de pilha

SET TEMP 10
SET POWER 20

PUSH TEMP
PUSH POWER

SET TEMP 0
SET POWER 0

POP POWER
POP TEMP

PRINT TEMP
PRINT POWER

HALT
"""

# Programa 4: Comparação e jumps condicionais
COMPARE_PROGRAM = """
; Compara valores e faz jumps condicionais

SET TEMP 50
SET R0 100

CMP TEMP R0
JL temp_lower
JE temp_equal
JG temp_greater

temp_lower:
    ACTION aquecimento ativado
    GOTO end

temp_equal:
    ACTION temperatura ideal
    GOTO end

temp_greater:
    ACTION resfriamento necessario
    GOTO end

end:
    BEEP
    HALT
"""

# Programa 5: Leitura de sensores
SENSOR_PROGRAM = """
; Lê sensores e executa ações

LOAD R0 WATER_LEVEL
SET R1 100

CMP R0 R1
JL low_water

ACTION preparando cafe
BEEP
HALT

low_water:
    ACTION alerta nivel agua baixo
    BEEP
    HALT
"""


def main():
    """Função principal - executa VM com programa fornecido"""
    vm = CafeMachineVM()
    
    if len(sys.argv) > 1:
        # Carrega programa de arquivo
        filename = sys.argv[1]
        try:
            with open(filename, 'r') as f:
                program_content = f.read()
            
            print(f"=== Carregando programa: {filename} ===\n")
            vm.load_program(program_content)
            
            # Permite setar valores iniciais via argumentos
            if len(sys.argv) > 2:
                for arg in sys.argv[2:]:
                    if '=' in arg:
                        reg, val = arg.split('=')
                        vm.registers[reg.upper()] = float(val)
            
            print("Estado inicial:", vm.state())
            print("\n=== Executando ===\n")
            
            vm.run()
            
            print("\n=== Estado final ===")
            print("Registradores:", vm.state())
            print("Pilha:", vm.stack)
            print("Ações executadas:", vm.action_log)
            print(f"Total de passos: {vm.steps}")
            
        except FileNotFoundError:
            print(f"Erro: Arquivo '{filename}' não encontrado.")
            sys.exit(1)
        except Exception as e:
            print(f"Erro: {e}")
            import traceback
            traceback.print_exc()
            sys.exit(1)
    else:
        # Executa programas de demonstração
        print("=== CafeMachine VM - Demonstrações ===\n")
        
        # Demo 1: Adição
        print("--- Demo 1: Adição (3 + 2) ---")
        vm.load_program(ADD_PROGRAM)
        vm.registers["TEMP"] = 3.0
        vm.registers["POWER"] = 2.0
        vm.run()
        print(f"Resultado: {vm.registers['TEMP']}\n")
        
        # Demo 2: Stack
        print("--- Demo 2: Operações de Pilha ---")
        vm.load_program(STACK_PROGRAM)
        vm.run()
        print()
        
        # Demo 3: Comparação
        print("--- Demo 3: Comparações e Jumps ---")
        vm.load_program(COMPARE_PROGRAM)
        vm.run()
        print()
        
        # Demo 4: Sensores
        print("--- Demo 4: Leitura de Sensores ---")
        vm.load_program(SENSOR_PROGRAM)
        vm.sensors["WATER_LEVEL"] = 50.0  # Nível baixo
        vm.run()
        print()


if __name__ == "__main__":
    main()
