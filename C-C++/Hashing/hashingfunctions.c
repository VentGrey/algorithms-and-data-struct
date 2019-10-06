#include <math.h>
#include <stdio.h>

#define TRUE (1==1)

/*
	Returns the sum two numbers adding each digit separately and keeping just the unit of the result
	@param a one of the numbers you want to sum
	@param b the other number you want to sum
*/

int sumDigits (int a, int b){
	int j, c=0;
	for (j=10; a/(j/10) != 0 || b/(j/10) != 0; j*=10){
		c+= ((((a/(j/10))%10)+((b/(j/10))%10))%10)*(j/10);
	}
	return c;
}

/*
	Returns 10 to the power of the number you want
	@param a the exponent
*/

int tenToThePowerOf(int a){
	int i;
	for (i=1; a>0; i*=10) a--;
	return i;
}

/*
	Invert a number passed by reference, completing it with zeros in the right
	@param a the pointer (address) of the number you want to invert
	@param digitsWanted the number of digits the result may have (complete with zeros in the right)
*/

void invertedNumber (int *a, int digitsWanted){
	int b=0, j, i=tenToThePowerOf(digitsWanted);
	
	for (j=10; i > 0; j*=10){
		b+= (((*a)/(j/10))%10)*(i/10);
		i/=10;
	}
	
	*a=b;
	return;
}

/*
	Returns the hashed key by trivial hashing
	@param key the key you want to hash
	@param hashSize the size of the hash table (array) you have
*/

int hashTrivial(int key, int hashSize){
	return key%hashSize;
}

/*
	Returns the hashed key by fold hashing
	@param key the key you want to hash
	@param originalDigits the number of digits of the original decimal key
	@param finalDigits the number of digits of the hashed key (after fold hashing it)
*/

int hashFolding (int key, int originalDigits, int finalDigits){
	int i, j, a, b, d, folds, qa, qb;
	
	while (originalDigits > finalDigits){
	
		d = tenToThePowerOf(originalDigits-finalDigits);//point of separation to fold the number
		a = key/d;//left side of the fold
		b = key%d;//rigth side of the fold
		
		invertedNumber (&a, finalDigits);
		
		qa = finalDigits;//number of digits of a
		qb = originalDigits-finalDigits;//number of digits of b
		//equaling the number of digits of both
		if (qb > qa) a*=tenToThePowerOf(qb-qa);
		else b*=tenToThePowerOf(qa-qb);
		
		key = sumDigits (a, b); //sum digit by digit
		originalDigits-=finalDigits;
	}
	
	return key;
}

/*
	Returns the hashed key by multiplication hashing
	@param key the key you want to hash
	@param hashSize the size of the hash table (array) you have
*/

int hashMultiplication1(int key, int hashSize){
	double constant = 0.6485312158645; //any constant between 0 and 1 (not including 0 and 1)
	constant *= key;
	if (constant < 0) constant*=-1; //in case of overflow
	return ((int)(hashSize*(constant - ((int)constant))));
}

/*
	Returns the hashed key by squared multiplication hashing
	@param key the key you want to hash
	@param hashSize the size of the hash table (array) you have
*/

int hashMultiplication2 (int key, int hashSize){
	double constant = 0.6485312158645; //constant entre 0 e 1
	constant *= key*key;
	if (constant < 0) constant*=-1; //in case of overflow
	return ((int) (hashSize*(constant - ((int)constant))) );
}

/*
	A small application of the hashing functions
*/

int main (){
	int option, key, originalDigits, finalDigits, size;
  
	printf ("\n\nHASHING FUNCTIONS\n\n1 Trivial Method\n2 Folding Method\n3 Multiplication Method\n4 Squared Multiplication Method\n0 Close Program\n\n");
	while (TRUE){
		
		scanf ("%d", &option);
		switch (option){
			case 0:
				return 0;
			case 1:
				printf("Input the key you want to hash and size of the hash table:\n");
				scanf("%d %d", &key, &size);
				printf("Hashed key = %d\n\n",hashTrivial(key, size));
				break;
			case 2:
				printf ("Input the key you want to hash, the number of digits of the original key, and the number of digits you want the hashed key to have (smaller or equal to the original):\n");
				scanf ("%d %d %d", &key, &originalDigits, &finalDigits);
				printf("Hashed key = %d\n\n",hashFolding(key, originalDigits, finalDigits));
				break;
			case 3:
				printf("Input the key you want to hash and size of the hash table:\n");
				scanf("%d %d", &key, &size);
				printf("Hashed key = %d\n\n",hashMultiplication1(key, size));
				break;
			case 4:
				printf("Input the key you want to hash and size of the hash table:\n");
				scanf("%d %d", &key, &size);
				printf("Hashed key = %d\n\n",hashMultiplication2(key, size));
				break;
			default:
				break;
		}
	}
}
