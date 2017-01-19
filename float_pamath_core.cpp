extern "C"{

	#include <omp.h>
	#include <math.h>

//#include <iostream>
//using namespace std;

	void map_vec(float * srcp, float * rsp, long vecsize, float (func)(float)){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rsp[i] = func(srcp[i]);
		}
	}

	void map2_vec(float * srcp1, float * srcp2, float * rsp, long vecsize, float (func)(float, float)){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rsp[i] = func(srcp1[i], srcp2[i]);
		}
	}

	float sum_vec(float * vecin, long vecsize){
		float sum = 0;
		#pragma omp parallel for reduction(+:sum)
		for(long i = 0; i < vecsize; ++i){
			sum += vecin[i];
		}
		return sum;
	}

	void mul_vec(float * vec1, float * vec2, float * rs, long vecsize){
		#pragma omp parallel for
		for(long i = 0; i<vecsize; ++i){
			rs[i] = vec1[i] * vec2[i];
		}
	}

	float dot_vec(float * vec1, float * vec2, long vecsize){
		float * mul_rs = new float[vecsize];
		mul_vec(vec1, vec2, mul_rs, vecsize);
		float rs = sum_vec(mul_rs, vecsize);
		delete [] mul_rs;
		return rs;
	}

	float norm2_vec(float * vec, long vecsize){
		float * mul_rs = new float[vecsize];
		mul_vec(vec, vec, mul_rs, vecsize);
		float rs = sqrt(sum_vec(mul_rs, vecsize));
		delete [] mul_rs;
		return rs;
	}

	float cos_vec(float * vec1, float * vec2, long vecsize){
		float * mul_rs = new float[vecsize];
		mul_vec(vec1, vec2, mul_rs, vecsize);
		float dotv = sum_vec(mul_rs, vecsize);
		mul_vec(vec1, vec1, mul_rs, vecsize);
		float sqr1 = sum_vec(mul_rs, vecsize);
		mul_vec(vec2, vec2, mul_rs, vecsize);
		float sqr2 = sum_vec(mul_rs, vecsize);
		delete [] mul_rs;
		float rs = dotv / sqrt(sqr1 * sqr2);
		return rs;
	}

}

/*int main(){
	long veclen = 1000;
	float * ivec1 = new float[veclen];
	for(long i=0;i<veclen;++i){
		ivec1[i]=(float)(i+2);
	}
	float * ivec2 = new float[veclen];
	for(long i=0;i<veclen;++i){
		ivec2[i]=(float)(1+i*2);
	}
	cout<<sum_vec(ivec1, veclen)<<endl;
	cout<<dot_vec(ivec1,ivec2,veclen)<<endl;
	cout<<cos_vec(ivec1,ivec2,veclen)<<endl;
	return 0;
}*/
