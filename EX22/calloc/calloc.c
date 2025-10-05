void *ft_calloc(size_t nmemb, size_t size) { 
	void *ptr; 
	size_t total_size; 

	//check for zeros 
	if(size == 0 || nmemb == 0) { 
		special_ptr = malloc(0); 
		return (special_ptr); 
	}

	// check for overflow  
		if(nmemb > SIZE_MAX / size )
		return NULL; 
	
	

	ptr = malloc(nmemb * size); 

	if(!ptr) 
		return NULL; 

	ft_memset(ptr, 0, (size * nmemb)); 

	return (ptr); 
}

