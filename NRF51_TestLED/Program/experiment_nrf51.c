/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf_gpio.h"

#include "nrf51_system.h"
#include "nrf51_delay.h"
#include "experiment_nrf51.h"
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  GPIO_Config();

  while(1) {
    nrf_gpio_pin_toggle(18);
    Delay_100ms(1);
    nrf_gpio_pin_toggle(19);
    Delay_100ms(1);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  nrf_gpio_cfg_output(LED0);
  nrf_gpio_cfg_output(LED1);

  nrf_gpio_pin_set(LED0);
  nrf_gpio_pin_set(LED1);
}
/*====================================================================================================*/
/*====================================================================================================*/
