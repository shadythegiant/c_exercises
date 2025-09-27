	unsigned char	swap_bits(unsigned char octet) { 
		unsigned char high_bits = octet >> 4; 
		//0x0F (which is 0000 1111 in binary).
		unsigned char low_bits = octet & 0x0F;
		unsigned char swapped= (low_bits << 4) | high_bits;
		return(swapped); 
	}