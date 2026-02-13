
		.syntax unified
		.text
		.global suma

#define		ope1 		R0
#define		ope2		R1

			.thumb_func
			
suma: 		
			PUSH  	{LR}
			ADD		ope1,	ope1,	ope2
			pop		{PC}