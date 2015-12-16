int main()
{
	volatile unsigned long *ddrb = (volatile unsigned long*)0x24;
	volatile unsigned long *portb = (volatile unsigned long*)0x25;

	*ddrb = 0x20;
	*portb = 0x20;

	int c=1,d=1;  
  
	while(1)
	{
     		*portb ^= 0x20;
		for ( c = 1 ; c <= 2000 ; c++ )
       			for ( d = 1 ; d <= 2000 ; d++ )
       				{}
  	}
	return 0;
}


