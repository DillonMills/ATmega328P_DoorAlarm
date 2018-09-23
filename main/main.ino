// main.ino
// ATmega328P_DoorAlarm
// Dillon Mills

const unsigned long int FOSC = 16000000;          // Clock Speed (need data type for this)
const unsigned short int BAUD = 1200;             // Baud Rate

void setup()
{
  // ---------- Serial ---------- //
  
  // Set baud rate
  unsigned short int ubrr = (FOSC / (16 * BAUD)) - 1;
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  // Enable receiver and transmitter
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  // Set frame format: 8data, 2stop bit
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);

  Serial.print("Setup: Serial...COMPLETE\n");

  // ---------- Clock ---------- //

  Serial.print("Setup: Clock...");
  
  // # CLKPR - Clock Prescale Register
  // CLKPCE: Clock Prescaler Change Enable
  // CLKPS[3:0]: Clock Prescaler Select Bits 3-0
  CLKPR = (1 << CLKPCE); // CLKPCE = 1b, CLKPS[3:0] = 0000b, Mandatory to change CLKPS bits
  //                                                                           Prescaler | CIRCO 8 MHz |
  CLKPR |= (1 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);   //       256 |   31.25 kHz |
  //CLKPR |= (0 << CLKPS3) | (1 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0); //       128 |   62.50 kHz |
  //CLKPR |= (0 << CLKPS3) | (1 << CLKPS2) | (1 << CLKPS1) | (0 << CLKPS0); //        64 |  125.00 kHz |
  //CLKPR |= (0 << CLKPS3) | (1 << CLKPS2) | (0 << CLKPS1) | (1 << CLKPS0); //        32 |  250.00 kHz |
  //CLKPR |= (0 << CLKPS3) | (1 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0); //        16 |  500.00 kHz |
  //CLKPR |= (0 << CLKPS3) | (0 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0); //         8 | 1000.00 kHz | (DEFAULT)
  //CLKPR |= (0 << CLKPS3) | (0 << CLKPS2) | (1 << CLKPS1) | (0 << CLKPS0); //         4 | 2000.00 kHz |
  //CLKPR |= (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (1 << CLKPS0); //         2 | 4000.00 kHz |
  //CLKPR |= (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0); //         1 | 8000.00 kHz |

  Serial.print("COMPLETE\n");
  
  // ---------- Timer ---------- //
  
  Serial.print("Setup: Timer...");

  // <Add timer stuff here.>
  
  Serial.print("COMPLETE\n");
  
  // ---------- Interrupts ---------- //
  
  Serial.print("Setup: Interrupts...");
  
  // # SREG - AVR Status Register
  // BIT7 (I): Global Interrupt Enable
  SREG = (1 << 7);

  // <Add more interrupt stuff here.>
  
  Serial.print("COMPLETE\n");

  // ---------- Power ---------- //

  Serial.print("Setup: Power...");

  // <Add power stuff here.>

  Serial.print("COMPLETE\n");
}

void loop()
{
  Serial.print("ping\n");
  delay(1000);
}

ISR(INT0_vect)
{
  Serial.print("Alert: Door Activity");
  // <Add door sensor interrupt stuff here.>
}

/*ISR(timer)
{
  // <Add door timer interrupt stuff here.>
}*/
