#include<stdio.h>
#include<stdlib.h>

int SpherePlane(float*Sphere,float*Plane){
	//positive radius of sphere
	//3*, 4+, 1>
	return 
		Sphere[0]*Plane[0]+
		Sphere[1]*Plane[1]+
		Sphere[2]*Plane[2]+
		Sphere[3]+Plane[3]>0;
	//negative radius of sphere
	//3*, 3+, 1>
	return
		Sphere[0]*Plane[0]+
		Sphere[1]*Plane[1]+
		Sphere[2]*Plane[2]+
		Plane[3]>Sphere[3];
}

int SphereSphere(float*A,float*B){
	//4*,3+,1-,1>
	float a=A[0]-B[0];
	float b=A[1]-B[1];
	float c=A[2]-B[2];
	float d=A[3]+B[3];
	return d*d>a*a+b*b+c*c;
}

int SphereLine(float*S,float*A,float*B){
}

int SphereSegment(float*S,float*A,float*B){
}

int main(){
	fprintf(stdout,"Hello, world!\n");
	return EXIT_SUCCESS;
}
