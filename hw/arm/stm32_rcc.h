#include "hw/sysbus.h"
#include "hw/arm/stm32_clktree.h"
#include "hw/arm/stm32.h"

/** RCC Base data structure */
struct Stm32Rcc {
    /* Inherited */
    SysBusDevice busdev;

    /* Properties */
    uint32_t osc_freq;
    uint32_t osc32_freq;

    /* Private */
    MemoryRegion iomem;
    qemu_irq irq;

    uint32_t dummy; // Fixes structure alignment issue on windows

    /* Peripheral clocks */
    Clk PERIPHCLK[];
};
