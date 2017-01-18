extern "C"{

	#include <omp.h>
	#include <math.h>

//#include <iostream>
//using namespace std;

	double sum_vec(double * vecin, long vecsize){
		double sum = 0;
		#pragma omp parallel for reduction(+:sum)
		for(long i = 0; i < vecsize; ++i){
			sum += vecin[i];
		}
		return sum;
	}

	void mul_vec(double * vec1, double * vec2, double * rs, long vecsize){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rs[i] = vec1[i] * vec2[i];
		}
	}

	double dot_vec(double * vec1, double * vec2, long vecsize){
		double * mul_rs = new double[vecsize];
		mul_vec(vec1, vec2, mul_rs, vecsize);
		double rs = sum_vec(mul_rs, vecsize);
		delete [] mul_rs;
		return rs;
	}

	double cos_vec(double * vec1, double * vec2, long vecsize){
		double dotv = dot_vec(vec1, vec2, vecsize);
		double sqr1 = dot_vec(vec1, vec1, vecsize);
		double sqr2 = dot_vec(vec2, vec2, vecsize);
		double rs = dotv / sqrt(sqr1 * sqr2);
		return rs;
	}

}

/*int main(){
	long veclen = 1000;
	double * ivec1 = new double[veclen];
	for(long i=0;i<veclen;++i){
		ivec1[i]=(double)(i+2);
	}
	double * ivec2 = new double[veclen];
	for(long i=0;i<veclen;++i){
		ivec2[i]=(double)(1+i*2);
	}
	cout<<sum_vec(ivec1, veclen)<<endl;
	cout<<dot_vec(ivec1,ivec2,veclen)<<endl;
	cout<<cos_vec(ivec1,ivec2,veclen)<<endl;
	return 0;
}*/
