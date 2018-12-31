#include <unistd.h>
#include <stdint.h>

uint8_t read_buf[1000000];
uint64_t read_buf_size = 0;

uint8_t write_buf[1000000];
uint64_t write_buf_size = 0;

uint8_t fun_name[64];
uint64_t fun_name_size = 0;

void write_str(const char* str) {
    int64_t i = 0;
    while (str[i] != '\0') {
        write_buf[write_buf_size] = str[i];
        write_buf_size += 1;
        i += 1;
    }
}

int main() {
    int i;
    int j;
    read_buf_size = read(0, read_buf, 1000000);
    write_str("    .intel_syntax noprefix\n");
    write_str("    .text\n");
    i = 0;
    while (i < read_buf_size) {
        if (read_buf[i] == '\n') {
            if (fun_name_size != 0) {
                write_str("    .globl ");
                j = 0;
                while (j < fun_name_size) {
                    write_buf[write_buf_size] = fun_name[j];
                    write_buf_size += 1;
                    j += 1;
                }
                write_str("\n");
                j = 0;
                while (j < fun_name_size) {
                    write_buf[write_buf_size] = fun_name[j];
                    write_buf_size += 1;
                    j += 1;
                }
                write_str(":\n");
                write_str("    push rbp\n");
                write_str("    mov rbp, rsp\n");
                write_str("    mov rax, 0\n");
                write_str("    pop rbp\n");
                write_str("    ret\n");
                fun_name_size = 0;
            }
        }
        else {
            fun_name[fun_name_size] = read_buf[i];
            fun_name_size += 1;
        }
        i += 1;
    }
    write(1, write_buf, write_buf_size);
}
