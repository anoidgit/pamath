extern "C"{

	#include <omp.h>
	#include <math.h>

//#include <iostream>
//using namespace std;

	void map_vec(long double * srcp, long double * rsp, long vecsize, long double (func)(long double)){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rsp[i] = func(srcp[i]);
		}
	}

	void map2_vec(long double * srcp1, long double * srcp2, long double * rsp, long vecsize, long double (func)(long double, long double)){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rsp[i] = func(srcp1[i], srcp2[i]);
		}
	}

	long double sum_vec(long double * vecin, long vecsize){
		long double sum = 0;
		#pragma omp parallel for reduction(+:sum)
		for(long i = 0; i < vecsize; ++i){
			sum += vecin[i];
		}
		return sum;
	}

	void mul_vec(long double * vec1, long double * vec2, long double * rs, long vecsize){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rs[i] = vec1[i] * vec2[i];
		}
	}

	long double dot_vec(long double * vec1, long double * vec2, long vecsize){
		long double * mul_rs = new long double[vecsize];
		mul_vec(vec1, vec2, mul_rs, vecsize);
		long double rs = sum_vec(mul_rs, vecsize);
		delete [] mul_rs;
		return rs;
	}

	long double norm2_vec(long double * vec, long vecsize){
		long double * mul_rs = new long double[vecsize];
		mul_vec(vec, vec, mul_rs, vecsize);
		long double rs = sqrt(sum_vec(mul_rs, vecsize));
		delete [] mul_rs;
		return rs;
	}

	long double cos_vec(long double * vec1, long double * vec2, long vecsize){
		long double * mul_rs = new long double[vecsize];
		mul_vec(vec1, vec2, mul_rs, vecsize);
		long double dotv = sum_vec(mul_rs, vecsize);
		mul_vec(vec1, vec1, mul_rs, vecsize);
		long double sqr1 = sum_vec(mul_rs, vecsize);
		mul_vec(vec2, vec2, mul_rs, vecsize);
		long double sqr2 = sum_vec(mul_rs, vecsize);
		delete [] mul_rs;
		long double rs = dotv / sqrt(sqr1 * sqr2);
		return rs;
	}

}

/*int main(){
	long veclen = 1000;
	long double * ivec1 = new long double[veclen];
	for(long i=0;i<veclen;++i){
		ivec1[i]=(long double)(i+2);
	}
	long double * ivec2 = new long double[veclen];
	for(long i=0;i<veclen;++i){
		ivec2[i]=(long double)(1+i*2);
	}
	cout<<sum_vec(ivec1, veclen)<<endl;
	cout<<dot_vec(ivec1,ivec2,veclen)<<endl;
	cout<<cos_vec(ivec1,ivec2,veclen)<<endl;
	return 0;
}*/
