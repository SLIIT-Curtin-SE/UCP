#ifndef FALSE
#define FALSE 0
#define TRUE !FALSE
#define BETWEEN(low, high, value) result = FALSE; if (low <= value) {if (high >= value){result = TRUE;}} 
#endif


