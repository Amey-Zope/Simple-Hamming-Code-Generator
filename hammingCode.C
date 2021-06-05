//program to find hamming code (DS Project)
#include<stdio.h>
#include<conio.h>
#include<math.h>

void calcHamming(int noOfBits)
{
	int i,a[50],noOfParityBits,tBits;

	if(noOfBits<=4)
	{
		noOfParityBits=3;
	}

	else if(noOfBits<=8)
	{
		noOfParityBits=4;
	}

	else if(noOfBits<=16)
	{
		noOfParityBits=5;
	}

	else if(noOfBits<=32)
	{
		noOfParityBits=6;
	}

	tBits=noOfBits+noOfParityBits;
	for(i=0; i<20; i++)     //to make all the values of indices zero
	{
		a[i]=0;
	}

	printf("Enter %d number of bits: ",noOfBits);
	for(i=1; i<=(tBits) ; i++)    //to accept bits at appropriate indices
	{
		if((i!=1) && (i!=2) && (i!=4) && (i!=8) && (i!=16) && (i!=32))
		{
			scanf("%d",&a[i]);
		}
	}

	for(i=1;i<=(tBits);i++)      //to find parity
	{
		int counterP1=1,counterP2=2,counterP4=4,counterP8=8,counterP16=16,counterP32=32;


		while(counterP1<=(tBits))   //to find p1
		{
			if(counterP1==tBits)
			{
				a[1]=a[1] ^ a[tBits];
			}
			else
			{
				a[1]=a[1] ^ a[counterP1+2];
				counterP1 = counterP1 + 2;
			}
		}
		printf("%d",a[1]);

		while(counterP2<=(tBits))   //to find p2
		{
			if(counterP2==tBits)
			{
				a[2]=a[2] ^ a[tBits];
			}
			else
			{
				a[2]=a[2] ^ a[counterP2+1];
				counterP2 = counterP2 + 4;
			}
		}
			printf("%d",a[2]);

		while(counterP4<=(tBits))  //to find p4
		{
			if(counterP4==tBits)
			{
				a[4]=a[4] ^ a[tBits];
			}
			else
			{
				for(counterP4=4;counterP4<=7 && (counterP4<=(tBits)); )
				{
					a[4]=a[4] ^ a[counterP4+1];
					counterP4=counterP4+2;
				}
				counterP4 = counterP4 + 5;
			}
		}

		while(counterP8<=(tBits))  // to find p8
		{
			if(counterP8==tBits)
			{
				a[8]=a[8] ^ a[tBits];
			}
			else
			{
				for(counterP8=8;(counterP8<=15 && counterP8<=(tBits)); )
				{
					a[8]=a[8] ^ a[counterP8+1];
					counterP8=counterP8+2;
				}
				counterP8 = counterP8 + 9;
			}
		}

		while(counterP16<=(tBits))  //to find p16
		{
			if(counterP16==tBits)
			{
				a[16]=a[16] ^ a[tBits];
			}
			else
			{
				for(counterP16=16;(counterP16<=31 && (counterP16<=(tBits))); )
				{
					a[16]=a[16] ^ a[counterP16+1];
					counterP16=counterP16+2;
				}
				counterP16=counterP16+17;
			}
		}

		while(counterP32<=(tBits))  //to find p32
		{
			if(counterP32==tBits)
			{
				a[32]=a[32] ^ a[tBits];
			}
			else
			{
				for(counterP16=32;(counterP16<=63 && (counterP32<=(tBits))); )
				{
					a[32]=a[32] ^ a[counterP32+1];
					counterP32=counterP32+2;
				}
				counterP32=counterP32+33;
			}
		}

		printf("Hamming code for entered bitcode: "); /* to print the hamming
													 code */
		for(i=1;i<=(tBits);i++)
		{
			printf("%d ",a[i]);
		}
	}
}


void main()
{
	int noOfBits;
	clrscr();
	printf("Enter no of bits: ");
	scanf("%d",&noOfBits);
	calcHamming(noOfBits);
	getch();
}
