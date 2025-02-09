#ifndef IDT_H
#define IDT_H
#include <stdint.h>

struct idt_desc {
    uint16_t offset_1; // offset bits 0-15
    uint16_t selector; // selector that's in our GDT
    uint8_t zero; // Does nothing. Unused set to zero.
    uint8_t type_attr; // Descriptor type and attributes
    uint16_t offset_2; // offset bits 16-31
} __attribute ((packed));

struct idtr_desc {
    uint16_t limit; // size of descriptor table - 1
    uint32_t base; // Base address of the start of the interrupt descriptor table
} __attribute ((packed));

void idt_init();

#endif